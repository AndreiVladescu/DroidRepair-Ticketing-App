#include "SQLServer.h"

SQLServer* SQLServer::instance = nullptr;

SQLServer::SQLServer()
{
	int rc = sqlite3_open(DATABASE_NAME, &db);
	if (rc) {
		cout << "--- SQL Server encountered a problem: " << sqlite3_errmsg(db) << endl;
		exit(EXIT_FAILURE);
	}
	else {
		cout << ">>> SQL Server up and running" << endl;
	}
}

SQLServer::~SQLServer()
{
	sqlite3_close(db);
	destroyInstance();
	cout << ">>> SQL Server shutting down" << endl;
}

void SQLServer::destroyInstance()
{
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

SQLServer* SQLServer::getInstance()
{
	if (instance == nullptr)
		instance = new SQLServer;
	return instance;
}

// Returns true if the user is indeed found inside the database.
bool SQLServer::AuthenticateUser(string email, string provided_password)
{
	sqlite3_stmt* stmt;
	string passwd;

	auto sql = "select Passwd from Users where Email = '" + email + "'";

	int rc = sqlite3_prepare_v2(instance->db, sql.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		printf("error: %s", sqlite3_errmsg(instance->db));
		exit(-1);
	}

	rc = sqlite3_step(stmt);
	char* passwd_primitive = (char*)sqlite3_column_text(stmt, 0);
	passwd = passwd_primitive;

	sqlite3_finalize(stmt);

	if (passwd == provided_password)
		return true;
	return false;
}

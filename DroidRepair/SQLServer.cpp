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
	if (passwd_primitive == NULL)
		return false;
	passwd = passwd_primitive;

	sqlite3_finalize(stmt);

	if (bcrypt::validatePassword(provided_password, passwd))
		return true;
	return false;
}

int SQLServer::GetUserID(string email)
{
	sqlite3_stmt* stmt;
	int userId;

	auto sql = "select ID from Users where Email = '" + email + "'";

	int rc = sqlite3_prepare_v2(instance->db, sql.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		printf("error: %s", sqlite3_errmsg(instance->db));
		exit(-1);
	}

	rc = sqlite3_step(stmt);
	char* userIdString = (char*)sqlite3_column_text(stmt, 0);
	if (userIdString == NULL)
		return -1;
	userId = atoi(userIdString);

	sqlite3_finalize(stmt);

	return userId;
}

int SQLServer::GetUserRole(string email)
{
	sqlite3_stmt* stmt;
	int userRole = -1;

	auto sql = "select Roles.RolePriority from Users "
		"inner join Roles "
		"on Roles.ID = Users.RoleID "
		"where Users.Email = '" + email + "'";

	int rc = sqlite3_prepare_v2(instance->db, sql.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		printf("error: %s", sqlite3_errmsg(instance->db));
		exit(-1);
	}

	rc = sqlite3_step(stmt);
	char* userRoleString = (char*)sqlite3_column_text(stmt, 0);
	if (userRoleString == NULL)
		return -1;
	userRole = atoi(userRoleString);

	sqlite3_finalize(stmt);

	return userRole;
}

vector<Ticket> SQLServer::GetUserTickets(string email, int role)
{
	sqlite3_stmt* stmt;
	vector<Ticket> ticketVector = {};
	string sql;
	int ticketNumber = -1;
	if (role) {
		sql = "select count(Tickets.Problem) from Tickets inner join Users on Tickets.ClientID = Users.ID left join Users as Technicians on Technicians.ID = Tickets.TechnicianID where  Technicians.ID IS NULL or Technicians.Email = '" + email + "'";
	}
	else {
		sql = "select count(T.Problem) from Tickets as T inner join Users as C on C.ID = T.ClientID where C.Email = '" + email + "'";
	}

	int rc = sqlite3_prepare_v2(instance->db, sql.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		printf("error: %s", sqlite3_errmsg(instance->db));
		exit(-1);
	}

	rc = sqlite3_step(stmt);
	char* ticketNumberString = (char*)sqlite3_column_text(stmt, 0);
	if (ticketNumberString == NULL)
		ticketNumber = 0;
	ticketNumber = atoi(ticketNumberString);

	if (role) {
		sql = "select T.Category, T.Problem, T.Solution, C.Email as [Client Mail] from Tickets as T \
			inner join Users as C \
			on C.ID = T.ClientID \
			left join Users as TU \
			on TU.ID = T.TechnicianID \
			where TU.Email = '" + email + "'" +
			" or TU.ID IS NULL";
	}
	else {
		sql = "select T.Category, T.Problem, T.Solution from Tickets as T \
			inner join Users as C \
			on C.ID = T.ClientID \
			where C.Email = '" + email + "'";
	}

	rc = sqlite3_prepare_v2(instance->db, sql.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		printf("error: %s", sqlite3_errmsg(instance->db));
		exit(-1);
	}

	for (int i = 0; i < ticketNumber; i++) {
		Ticket tempTicket;
		rc = sqlite3_step(stmt);
		char* tempCategoryString = (char*)sqlite3_column_text(stmt, 0);
		char* tempProblemString = (char*)sqlite3_column_text(stmt, 1);
		char* tempSolutionString = (char*)sqlite3_column_text(stmt, 2);
		tempTicket.setCategory(tempCategoryString);
		tempTicket.setProblem(tempProblemString);
		if (tempSolutionString != NULL)
			tempTicket.setSolution(tempSolutionString);

		if (role) {
			char* tempClientMailString = (char*)sqlite3_column_text(stmt, 3);
			tempTicket.setClientEmail(tempClientMailString);
		}
		ticketVector.push_back(tempTicket);
	}
	sqlite3_finalize(stmt);


	return ticketVector;
}

#pragma once

#include <iostream>
#include <sqlite3.h>

using namespace std;

constexpr auto DATABASE_NAME = "droid.db";

// SQL Interface to the rest of the program.
// 
// The server primarily uses sqlite3 functions to access a database file on the machine.
// Sqlite3 is installed with the vcpkg utility.
// 
// Singleton-pattern.
class SQLServer
{
private:
	SQLServer();
	~SQLServer();
	SQLServer(SQLServer& copyInstance) = delete; // No access for another instance

	void destroyInstance();

	static SQLServer* instance;
	sqlite3* db;
public:
	static SQLServer* getInstance();
	static bool AuthenticateUser(string email, string password);
};


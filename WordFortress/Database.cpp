#include "database.h"
#include "sqlite\sqlite3.h"
#include "constants.h"

#include <iostream>

using namespace std;

// ToDo: Delete this:
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	cout << "Callback output: " << endl;
	int i;
	for (i = 0; i < argc; i++) {
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
	}
	return 0;
}

Database::Database()
{
	filePath = (GetCurrentPath() + "\\" + DATABASE_FILENAME);
	if (!ExistsDatabase())
	{
		CreateNewDatabase();
	}
}

Database::~Database()
{
}

void Database::AddEntry(const string& service, const string& user, const string& mail, const string& notes, const string& password, const string& salt)
{
	sqlite3* db;
	sqlite3_open(filePath.c_str(), &db);
	// TODO
	sqlite3_exec(db, CREATE_NEW_DATABASE, callback, 0, 0);
	sqlite3_close(db);
}

void Database::AddMailAccount(const string& mailAddress)
{
	sqlite3* db;
	sqlite3_open(filePath.c_str(), &db);
	string sql = INSERT_NEW_MAILACCOUNT_PART_1;
	sql.append(mailAddress);
	sql.append(INSERT_NEW_MAILACCOUNT_PART_2);
	sqlite3_exec(db, sql.c_str(), callback, 0, 0);
	sqlite3_close(db);
}

string Database::GetCurrentPath()
{
	char buff[FILENAME_MAX];
	GetCurrentDir(buff, FILENAME_MAX);
	string current_working_dir(buff);
	return current_working_dir;
}

inline bool Database::ExistsDatabase()
{
	struct stat buffer;
	return (stat(filePath.c_str(), &buffer) == 0);
}

void Database::CreateNewDatabase()
{
	sqlite3* db;
	sqlite3_open(filePath.c_str(), &db);
	sqlite3_exec(db, CREATE_NEW_DATABASE, callback, 0, 0);
	sqlite3_close(db);
}

#include "database.h"

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

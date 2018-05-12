#ifndef RESSOURCE_DATABASE_H
#define RESSOURCE_DATABASE_H

#define WINDOWS

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <string>
#include <iostream>
#include "sqlite\sqlite3.h"
#include "constants.h"

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

class Database
{
public:
	Database();
	~Database();

private:
	string GetCurrentPath();
	inline bool ExistsDatabase();
	void CreateNewDatabase();

	string filePath;
};

#endif // RESSOURCE_DATABASE_H

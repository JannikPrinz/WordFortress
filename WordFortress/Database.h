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
#include "sqlite\sqlite3.h"
#include "constants.h"

using namespace std;

class Database
{
public:
	Database();
	~Database();

private:
	string GetCurrentPath();

	const char* filePath;
};

#endif // RESSOURCE_DATABASE_H

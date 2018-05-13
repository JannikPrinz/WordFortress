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

class Database
{
public:
	Database();
	~Database();

private:
	std::string GetCurrentPath();
	inline bool ExistsDatabase();
	void CreateNewDatabase();

	std::string filePath;
};

#endif // RESSOURCE_DATABASE_H

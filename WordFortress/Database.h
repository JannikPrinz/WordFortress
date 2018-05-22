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
	void AddEntry(const std::string& service, const std::string& user, const std::string& mail, const std::string& notes, const std::string& password, const std::string& salt);
	void AddMailAccount(const std::string& mailAddress);

private:
	std::string GetCurrentPath();
	inline bool ExistsDatabase();
	void CreateNewDatabase();

	std::string filePath;
};

#endif // RESSOURCE_DATABASE_H

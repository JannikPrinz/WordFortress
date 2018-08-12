#pragma once

#define WINDOWS

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <iostream>

#ifdef _DEBUG
static int outputCallback(void *NotUsed, int argc, char **argv, char **azColName)
{
	std::cout << "Callback output: " << std::endl;
	for (int i = 0; i < argc; i++) {
		std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
	}
	return 0;
}
#else
static int outputCallback(void *NotUsed, int argc, char **argv, char **azColName)
{
	return 0;
}
#endif // DEBUG

#include <string>
#include <list>
#include <tuple>

using CallbackFunction = int(*)(void*, int, char**, char**);
using SQLCommand = std::tuple<std::string, CallbackFunction, void*>;
using SQLCommandList = std::list<SQLCommand>;
using MailList = std::list<std::tuple<int, std::string>>;
using MailWithTimesUsedList = std::list<std::tuple<int, std::string, int>>;

class Database
{
public:
	Database();
	~Database();
	void AddEntry(const std::string& service, const std::string& user, const int mailId, const std::string& notes, const std::string& password, const std::string& salt);
	void AddMailAccount(const std::string& mailAddress);
	MailList GetMailAccounts();
	MailWithTimesUsedList GetMailAccountsWithTimesUsed();


private:
	std::string GetCurrentPath();
	inline bool ExistsDatabase();
	void CreateNewDatabase();
	inline void ExecuteDBCommand(const std::string& cmd, CallbackFunction cb = outputCallback, void* returnValues = 0);
	void ExecuteDBCommands(const SQLCommandList& cmds);
	/*
	 * Add a new password to the database with a salt value.
	 *
	 * Returns the id of the new entry.
	 */
	int AddPassword(const std::string& password, const std::string& salt);

	std::string filePath;
};

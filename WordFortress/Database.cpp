#include "database.h"
#include "sqlite\sqlite3.h"
#include "constants.h"

#include <sstream>

using namespace std;

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

void Database::AddEntry(const string& service, const string& user, const int mailId, const string& notes, const string& password, const string& salt)
{
	std::stringstream sql;
	int passwordId = AddPassword(password, salt);

	sql << INSERT_NEW_ENTRY_PART_1 << service;
	sql << INSERT_NEW_ENTRY_PART_2 << user;
	sql << INSERT_NEW_ENTRY_PART_3 << mailId;
	sql << INSERT_NEW_ENTRY_PART_4 << notes;
	sql << INSERT_NEW_ENTRY_PART_5 << passwordId;
	sql << INSERT_NEW_ENTRY_PART_6;

	ExecuteDBCommand(sql.str());
}

void Database::AddMailAccount(const string& mailAddress)
{
	string sql = INSERT_NEW_MAILACCOUNT_PART_1;
	sql.append(mailAddress);
	sql.append(INSERT_NEW_MAILACCOUNT_PART_2);

	ExecuteDBCommand(sql);
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
	ExecuteDBCommand(CREATE_NEW_DATABASE);
}

inline void Database::ExecuteDBCommand(const std::string& cmd, CallbackFunction cb, void* returnValues)
{
	ExecuteDBCommands({ SQLCommand(cmd, cb, returnValues) });
}

void Database::ExecuteDBCommands(const SQLCommandList& cmds)
{
	sqlite3* db;
	sqlite3_open(filePath.c_str(), &db);
	for (auto&& cmd : cmds)
	{
		char* errormsg = NULL;

		sqlite3_exec(db, std::get<0>(cmd).c_str(), std::get<1>(cmd), std::get<2>(cmd), &errormsg);

#ifdef _DEBUG
		cout << "Executed sql-Command: " << std::get<0>(cmd) << std::endl;
		if (errormsg != NULL)
		{
			cout << "Error: " << errormsg << std::endl;
		}
#endif

		if (errormsg != NULL)
		{
			delete errormsg;
		}
	}
	sqlite3_close(db);
}

int Database::AddPassword(const std::string& password, const std::string& salt)
{
	std::stringstream sql;
	int* idp = new int;
	int id = -1;

	sql << INSERT_NEW_PASSWORD_PART_1 << salt;
	sql << INSERT_NEW_PASSWORD_PART_2 << password;
	sql << INSERT_NEW_PASSWORD_PART_3;

	CallbackFunction cb = [](void *NotUsed, int argc, char **argv, char **azColName) {
		*(int*)NotUsed = (argc < 1) ? -1 : stoi(argv[0]);
		return 0;
	};

	ExecuteDBCommands({
		SQLCommand(sql.str(), outputCallback, 0),
		SQLCommand(GET_LAST_INSERTED_ID, cb, idp)
	});

	if (idp != NULL)
	{
		id = *((int*)idp);
		delete idp;
	}

	return id;
}

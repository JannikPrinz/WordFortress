#include "database.h"

Database::Database()
{
	filePath = (GetCurrentPath() + "/" + DATABASE_FILENAME).c_str();
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

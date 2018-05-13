#ifndef LOGIC_MAINGUILOGIC_H
#define LOGIC_MAINGUILOGIC_H

#include "database.h"

class MainGuiLogic
{
public:
	MainGuiLogic(Database* database);
	~MainGuiLogic();

	void AddEntry();

private:
	Database* database;
};

#endif // LOGIC_MAINGUILOGIC_H

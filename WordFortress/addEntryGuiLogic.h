#ifndef LOGIC_ADDENTRYGUILOGIC_H
#define LOGIC_ADDENTRYGUILOGIC_H

#include "database.h"

class AddEntryGuiLogic
{
public:
	AddEntryGuiLogic(Database* database);
	~AddEntryGuiLogic();

	void AddEntry();

private:
	Database* database;
};

#endif // LOGIC_ADDENTRYGUILOGIC_H

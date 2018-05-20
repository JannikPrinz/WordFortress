#ifndef LOGIC_ADDENTRYGUILOGIC_H
#define LOGIC_ADDENTRYGUILOGIC_H

#include "database.h"
#include "GUI\wordFortressAddEntryGui.h"

class AddEntryGuiLogic
{
public:
	AddEntryGuiLogic(Database* database);
	~AddEntryGuiLogic();

	void AddEntry(WordFortressAddEntryGui* gui);

private:
	Database* database;
};

#endif // LOGIC_ADDENTRYGUILOGIC_H

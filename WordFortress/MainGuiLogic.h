#ifndef LOGIC_MAINGUILOGIC_H
#define LOGIC_MAINGUILOGIC_H

#include "database.h"
#include "addEntryGuiLogic.h"
#include "GUI\wordFortressAddEntryGui.h"
#include "wx\window.h"

class MainGuiLogic
{
public:
	MainGuiLogic(Database* database);
	~MainGuiLogic();

	void AddEntry();

private:
	void ConnectViewWithLogic(WordFortressAddEntryGui* gui, AddEntryGuiLogic& logic);

	Database* database;
};

#endif // LOGIC_MAINGUILOGIC_H

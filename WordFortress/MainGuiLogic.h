#ifndef LOGIC_MAINGUILOGIC_H
#define LOGIC_MAINGUILOGIC_H

#include "GUI\wordFortressMainGui.h"
#include "database.h"

class MainGuiLogic
{
public:
	MainGuiLogic(Database* database);
	~MainGuiLogic();

	void ShowGui();

private:
	void ConnectViewWithLogic();
	void AddEntry();

	Database* database;
	WordFortressMainGui* gui = NULL;
};

#endif // LOGIC_MAINGUILOGIC_H

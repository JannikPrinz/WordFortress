#pragma once

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
	void ManageMails();

	Database* database;
	WordFortressMainGui* gui = NULL;
};

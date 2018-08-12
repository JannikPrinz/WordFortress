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
	void Initialize();
	void AddEntry();
	void ManageMails();

	Database* database;
	WordFortressMainGui* gui = NULL;
};

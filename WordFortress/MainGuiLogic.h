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
	void AddEntry();
	void ManageMails();
	void RefreshGuiContent();
	void Initialize();

	Database* database;
	WordFortressMainGui* gui = NULL;
	EntryVector shownEntries;
};

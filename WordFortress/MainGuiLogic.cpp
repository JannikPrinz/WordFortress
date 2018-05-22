#include "mainGuiLogic.h"
#include "addEntryGuiLogic.h"

#include <iostream>

using namespace std;

MainGuiLogic::MainGuiLogic(Database* db)
	: database(db)
{
}

MainGuiLogic::~MainGuiLogic()
{
	if (gui != NULL)
	{
		delete gui;
		gui = NULL;
	}
}

void MainGuiLogic::ShowGui()
{
	if (gui != NULL) return;
	gui = new WordFortressMainGui(NULL, wxID_ANY);
	ConnectViewWithLogic();
	gui->Show();
}

void MainGuiLogic::AddEntry()
{
	AddEntryGuiLogic guiLogic = AddEntryGuiLogic(database);
	guiLogic.ShowGui();
}

void MainGuiLogic::ConnectViewWithLogic()
{
	gui->SetCBFunction(MainGuiAction::ADD_ENTRY, [&] { AddEntry(); });
}

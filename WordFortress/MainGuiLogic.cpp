#include "mainGuiLogic.h"
#include "addEntryGuiLogic.h"
#include "manageMailsGuiLogic.h"

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
	Initialize();
	gui->Show();
}

void MainGuiLogic::AddEntry()
{
	AddEntryGuiLogic guiLogic = AddEntryGuiLogic(database);
	guiLogic.ShowGui();
}

void MainGuiLogic::ManageMails()
{
	ManageMailsGuiLogic guiLogic = ManageMailsGuiLogic(database);
	guiLogic.ShowGui();
}

void MainGuiLogic::Initialize()
{
	gui->SetCBFunction(MainGuiAction::ADD_ENTRY, [&] { AddEntry(); });
	gui->SetCBFunction(MainGuiAction::MANAGE_MAILS, [&] { ManageMails(); });
}

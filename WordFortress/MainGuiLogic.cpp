#include "mainGuiLogic.h"

#include <iostream>

using namespace std;

MainGuiLogic::MainGuiLogic(Database* db)
	: database(db)
{
}

MainGuiLogic::~MainGuiLogic()
{
}

void MainGuiLogic::AddEntry()
{
	WordFortressAddEntryGui* subGui = new WordFortressAddEntryGui(NULL, wxID_ANY);
	AddEntryGuiLogic guiLogic = AddEntryGuiLogic(database);

	ConnectViewWithLogic(subGui, guiLogic);
	subGui->ShowModal();
	delete subGui;
}

void MainGuiLogic::ConnectViewWithLogic(WordFortressAddEntryGui* gui, AddEntryGuiLogic& logic)
{
	gui->SetCBFunction(AddEntryGuiAction::ADD_ENTRY, [&] { logic.AddEntry(gui); });
	gui->SetCBFunction(AddEntryGuiAction::CANCEL, [&] { gui->Close(); });
}

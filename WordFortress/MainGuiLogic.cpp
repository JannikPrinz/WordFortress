#include "mainGuiLogic.h"
#include "GUI\wordFortressAddEntryGui.h"

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
	subGui->ShowModal();
	delete subGui;
}

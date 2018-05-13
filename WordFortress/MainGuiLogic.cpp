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
	cout << "Add Entry called!";
}

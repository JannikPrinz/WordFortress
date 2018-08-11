#pragma once

#include "mainGuiLogic.h"
#include "database.h"

class WordFortress : public wxApp
{
public:
	/*
	 * Initializes the program and the main GUI.
	 */
	virtual bool OnInit() wxOVERRIDE;

private:
	MainGuiLogic* mainGuiLogic = NULL;
	Database database;
};

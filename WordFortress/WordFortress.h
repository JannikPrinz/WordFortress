#ifndef LOGIC_WORDFORTRESS_H
#define LOGIC_WORDFORTRESS_H

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

#endif // !LOGIC_WORDFORTRESS_H

#ifndef LOGIC_WORDFORTRESS_H
#define LOGIC_WORDFORTRESS_H

#include "GUI\wordFortressMainGui.h"
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
	/*
	 * Sets the callbacks of the view with corresponding methods of the corresponding logic.
	 */
	void ConnectViewWithLogic();

	WordFortressMainGui* mainGui;
	MainGuiLogic* mainGuiLogic;
	Database database;
};

#endif // !LOGIC_WORDFORTRESS_H

#ifndef LOGIC_WORDFORTRESS_H
#define LOGIC_WORDFORTRESS_H

#include "GUI\wordFortressMainGui.h"

using namespace std;

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
};

#endif // !LOGIC_WORDFORTRESS_H

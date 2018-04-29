#ifndef LOGIC_WORDFORTRESS_H
#define LOGIC_WORDFORTRESS_H

#include "GUI\WordFortressMainGui.h"

class WordFortress : public wxApp
{
public:
	virtual bool OnInit() wxOVERRIDE;

private:
	void ConnectViewWithLogic();

	WordFortressMainGui* mainGui;
};

#endif // !LOGIC_WORDFORTRESS_H

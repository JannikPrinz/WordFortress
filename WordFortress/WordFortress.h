#ifndef LOGIC_WORDFORTRESS_H
#define LOGIC_WORDFORTRESS_H

#include <iostream>
#include "cryptopp\modes.h"
#include "cryptopp\osrng.h"
#include "cryptopp\aes.h"
#include "GUI\WordFortressMainGui.h"
#include "sqlite\sqlite3.h"

class WordFortress : public wxApp
{
public:
	virtual bool OnInit() wxOVERRIDE;

private:
	void ConnectViewWithLogic();

	WordFortressMainGui* mainGui;
};

#endif // !LOGIC_WORDFORTRESS_H

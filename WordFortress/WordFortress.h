#ifndef LOGIC_WORDFORTRESS_H
#define LOGIC_WORDFORTRESS_H

#include <iostream>
#include "cryptopp\modes.h"
#include "cryptopp\osrng.h"
#include "cryptopp\aes.h"
#include "GUI\WordFortressMainGui.h"

class WordFortress : public wxApp
{
public:
	virtual bool OnInit() wxOVERRIDE;
};

#endif // !LOGIC_WORDFORTRESS_H

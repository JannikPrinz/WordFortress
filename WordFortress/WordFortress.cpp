#ifdef _DEBUG
#  pragma comment ( lib, "cryptlibd" )
#else
#  pragma comment ( lib, "cryptlib" )
#endif

#include "WordFortress.h"

wxIMPLEMENT_APP(WordFortress);

bool WordFortress::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	mainGui = new WordFortressMainGui(NULL, wxID_ANY);
	ConnectViewWithLogic();

	mainGui->Show();

	return true;
}

void WordFortress::ConnectViewWithLogic()
{

}

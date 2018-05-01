#ifdef _DEBUG
#  pragma comment ( lib, "cryptlibd" )
#else
#  pragma comment ( lib, "cryptlib" )
#endif

#include "wordFortress.h"

wxIMPLEMENT_APP_NO_MAIN(WordFortress);

int main()
{
	wxEntry();

	return 0;
}

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

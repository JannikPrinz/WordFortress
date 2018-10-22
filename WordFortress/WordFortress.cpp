#include "wordFortress.h"

using namespace std;

#ifdef _DEBUG

wxIMPLEMENT_APP_NO_MAIN(WordFortress);

int main()
{
	wxEntry();

	return 0;
}

#else

wxIMPLEMENT_APP(WordFortress);

#endif // _DEBUG

bool WordFortress::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	mainGuiLogic = new MainGuiLogic(&database);
	mainGuiLogic->ShowGui();

	return true;
}

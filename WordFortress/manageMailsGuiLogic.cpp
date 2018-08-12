#include "manageMailsGuiLogic.h"
#include "addMailGuiLogic.h"

using namespace std;

ManageMailsGuiLogic::ManageMailsGuiLogic(Database * database)
	: BaseLogic(database)
{
}

ManageMailsGuiLogic::~ManageMailsGuiLogic()
{
}

void ManageMailsGuiLogic::AddMail()
{
	AddMailGuiLogic guiLogic = AddMailGuiLogic(database);
	guiLogic.ShowGui();
	RefreshGuiContent();
}

void ManageMailsGuiLogic::RefreshGuiContent()
{
	shownMails = database->GetMailAccountsWithTimesUsed();
	shownMails.erase(shownMails.begin());
	gui->SetShownMails(shownMails);
}

void ManageMailsGuiLogic::Initialize()
{
	gui->SetCBFunction(ManageMailsGuiAction::ADD_MAIL, [&] { AddMail(); });
	gui->SetCBFunction(ManageMailsGuiAction::BACK, [&] { gui->Close(); });

	RefreshGuiContent();
}

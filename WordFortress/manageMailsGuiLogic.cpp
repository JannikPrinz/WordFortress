#include "manageMailsGuiLogic.h"
#include "addMailGuiLogic.h"

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
}

void ManageMailsGuiLogic::ConnectViewWithLogic()
{
	gui->SetCBFunction(ManageMailsGuiAction::ADD_MAIL, [&] { AddMail(); });
	gui->SetCBFunction(ManageMailsGuiAction::BACK, [&] { gui->Close(); });
}

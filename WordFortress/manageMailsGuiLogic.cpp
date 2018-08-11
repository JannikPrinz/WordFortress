#include "manageMailsGuiLogic.h"

ManageMailsGuiLogic::ManageMailsGuiLogic(Database * database)
	: BaseLogic(database)
{
}

ManageMailsGuiLogic::~ManageMailsGuiLogic()
{
}

void ManageMailsGuiLogic::AddMail()
{
}

void ManageMailsGuiLogic::ConnectViewWithLogic()
{
	gui->SetCBFunction(ManageMailsGuiAction::ADD_MAIL, [&] { AddMail(); });
	gui->SetCBFunction(ManageMailsGuiAction::BACK, [&] { gui->Close(); });
}

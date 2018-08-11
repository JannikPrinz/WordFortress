#include "addMailGuiLogic.h"

AddMailGuiLogic::AddMailGuiLogic(Database * database)
	: BaseLogic(database)
{
}

AddMailGuiLogic::~AddMailGuiLogic()
{
}

void AddMailGuiLogic::AddMail()
{
}

void AddMailGuiLogic::ConnectViewWithLogic()
{
	gui->SetCBFunction(AddMailGuiAction::ADD_MAIL, [&] { AddMail(); });
	gui->SetCBFunction(AddMailGuiAction::CANCEL, [&] { gui->Close(); });
}

#include "addMailGuiLogic.h"

using namespace std;

AddMailGuiLogic::AddMailGuiLogic(Database * database)
	: BaseLogic(database)
{
}

AddMailGuiLogic::~AddMailGuiLogic()
{
}

void AddMailGuiLogic::AddMail()
{
	string mail = gui->GetMail();

	// Remove whitespaces:
	mail.erase(remove_if(mail.begin(), mail.end(), isspace), mail.end());

	// Check if mail already exists:
	MailMap existingMails = database->GetMailAccounts();
	auto& it = std::find_if(existingMails.begin(), existingMails.end(), [&mail](auto& entry) { return mail == entry.second; });
	
	if (it == existingMails.end())
	{
		database->AddMailAccount(mail);
	}
	else
	{
		wxMessageBox(wxString(_("The mail address already exists.")), wxString(_("Mail exists")), wxICON_EXCLAMATION);
		return;
	}
}

void AddMailGuiLogic::ConnectViewWithLogic()
{
	gui->SetCBFunction(AddMailGuiAction::ADD_MAIL, [&] { AddMail(); });
	gui->SetCBFunction(AddMailGuiAction::CANCEL, [&] { gui->Close(); });
}

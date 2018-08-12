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

	if (mail == "")
	{
		wxMessageBox(wxString(_("An empty mail address is not allowed.")), wxString(_("Empty mail not allowed")), wxICON_EXCLAMATION);
		return;
	}

	// Check if mail already exists:
	MailVector existingMails = database->GetMailAccounts();
	auto& it = std::find_if(existingMails.begin(), existingMails.end(), [&mail](auto& entry) { return mail == get<1>(entry); });
	
	if (it == existingMails.end())
	{
		database->AddMailAccount(mail);
		gui->Close();
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

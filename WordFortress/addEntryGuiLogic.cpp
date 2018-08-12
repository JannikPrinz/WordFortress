#include "addEntryGuiLogic.h"
#include "addMailGuiLogic.h"

#include <iostream>

using namespace std;

AddEntryGuiLogic::AddEntryGuiLogic(Database* db)
	: BaseLogic(db)
{
}

AddEntryGuiLogic::~AddEntryGuiLogic()
{
}

void AddEntryGuiLogic::AddEntry()
{
	if (gui->GetService() == "")
	{
		wxMessageBox(wxString(_("Please enter an identifiert for the service.")), wxString(_("Service needed")), wxICON_EXCLAMATION);
		return;
	}
	if (gui->GetPassword() == "")
	{
		wxMessageBox(wxString(_("Please enter a password.")), wxString(_("Password needed")), wxICON_EXCLAMATION);
		return;
	}
	if (gui->GetKey() == "")
	{
		wxMessageBox(wxString(_("Please enter a key.")), wxString(_("Key needed")), wxICON_EXCLAMATION);
		return;
	}
	if (gui->GetKey() != gui->GetKeyRepeat())
	{
		wxMessageBox(wxString(_("The content of the two key fields have to be the same.")), wxString(_("Keys must match")), wxICON_EXCLAMATION);
		return;
	}

	int mailId = 1;
	int mailIndex = gui->GetMailIndex();
	if (mailIndex > -1)
	{
		mailId = get<0>(shownMails[mailIndex]);
	}
	database->AddEntry(gui->GetService(), gui->GetUser(), mailId, gui->GetNotes(), gui->GetPassword(), gui->GetKey());

	gui->Close();
}

void AddEntryGuiLogic::AddMail()
{
	AddMailGuiLogic guiLogic = AddMailGuiLogic(database);
	guiLogic.ShowGui();

	auto oldMails = shownMails;

	RefreshGuiContent();

	if (shownMails.size() > oldMails.size())
	{
		int index = 0;
		for (const auto& newMail : shownMails)
		{
			auto& it = std::find_if(oldMails.begin(), oldMails.end(), [&newMail](auto& oldMail) { return get<0>(newMail) == get<0>(oldMail); });

			if (it == oldMails.end())
			{
				gui->SetMailIndex(index);
			}
			++index;
		}
	}
}

void AddEntryGuiLogic::RefreshGuiContent()
{
	shownMails = database->GetMailAccounts();
	gui->SetMails(shownMails);
	if (gui->GetMailIndex() == -1)
	{
		gui->SetMailIndex(0);
	}
}

void AddEntryGuiLogic::Initialize()
{
	gui->SetCBFunction(AddEntryGuiAction::ADD_ENTRY, [&] { AddEntry(); });
	gui->SetCBFunction(AddEntryGuiAction::ADD_MAIL, [&] { AddMail(); });
	gui->SetCBFunction(AddEntryGuiAction::CANCEL, [&] { gui->Close(); });

	RefreshGuiContent();
}

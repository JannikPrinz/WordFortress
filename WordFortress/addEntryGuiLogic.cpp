#include "addEntryGuiLogic.h"

#include <iostream>

using namespace std;

AddEntryGuiLogic::AddEntryGuiLogic(Database* db)
	: database(db)
{
}

AddEntryGuiLogic::~AddEntryGuiLogic()
{
}

void AddEntryGuiLogic::AddEntry(WordFortressAddEntryGui* gui)
{
	if (gui->GetKey() == "")
	{
		wxMessageBox(wxString(_("Please enter a key.")), wxString(_("Key needed")), wxICON_EXCLAMATION);
		return;
	}
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
	if (gui->GetKey() != gui->GetKeyRepeat())
	{
		wxMessageBox(wxString(_("The content of the two key fields have to be the same.")), wxString(_("Keys must match")), wxICON_EXCLAMATION);
		return;
	}
}

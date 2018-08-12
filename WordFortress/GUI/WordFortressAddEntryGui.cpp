///-----------------------------------------------------------------
///
/// @file      WordFortressAddEntryGui.cpp
/// @author    Jannik Prinz
/// Created:   29.04.2018 13:23:41
/// @section   DESCRIPTION
///            WordFortressAddEntryGui class implementation
///
///------------------------------------------------------------------

#include "wordFortressAddEntryGui.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// WordFortressAddEntryGui
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(WordFortressAddEntryGui,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(WordFortressAddEntryGui::OnClose)
	EVT_BUTTON(ID_WXBUTTONADDENTRY,WordFortressAddEntryGui::WxButtonAddEntryClick)
	EVT_BUTTON(ID_WXBUTTONCANCEL,WordFortressAddEntryGui::WxButtonCancelClick)
	EVT_BUTTON(ID_WXBUTTONADDMAIL,WordFortressAddEntryGui::WxButtonAddMailClick)
END_EVENT_TABLE()
////Event Table End

WordFortressAddEntryGui::WordFortressAddEntryGui(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

WordFortressAddEntryGui::~WordFortressAddEntryGui()
{
} 

void WordFortressAddEntryGui::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizerMain = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(WxBoxSizerMain);
	this->SetAutoLayout(true);

	WxFlexGridSizerStandardInputs = new wxFlexGridSizer(0, 2, 0, 0);
	WxBoxSizerMain->Add(WxFlexGridSizerStandardInputs, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextService = new wxStaticText(this, ID_WXSTATICTEXTSERVICE, _("Service"), wxPoint(5, 7), wxDefaultSize, 0, _("WxStaticTextService"));
	WxFlexGridSizerStandardInputs->Add(WxStaticTextService, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditService = new wxTextCtrl(this, ID_WXEDITSERVICE, _(""), wxPoint(56, 5), wxSize(200, 23), 0, wxDefaultValidator, _("WxEditService"));
	WxFlexGridSizerStandardInputs->Add(WxEditService, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextUser = new wxStaticText(this, ID_WXSTATICTEXTUSER, _("User"), wxPoint(12, 40), wxDefaultSize, 0, _("WxStaticTextUser"));
	WxFlexGridSizerStandardInputs->Add(WxStaticTextUser, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditUser = new wxTextCtrl(this, ID_WXEDITUSER, _(""), wxPoint(56, 38), wxSize(200, 23), 0, wxDefaultValidator, _("WxEditUser"));
	WxFlexGridSizerStandardInputs->Add(WxEditUser, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextEMail = new wxStaticText(this, ID_WXSTATICTEXTEMAIL, _("E-Mail"), wxPoint(6, 73), wxDefaultSize, 0, _("WxStaticTextEMail"));
	WxFlexGridSizerStandardInputs->Add(WxStaticTextEMail, 0, wxALIGN_CENTER | wxALL, 5);

	wxArrayString arrayStringFor_WxComboBoxMail;
	WxComboBoxMail = new wxComboBox(this, ID_WXCOMBOBOXMAIL, _(""), wxPoint(56, 71), wxSize(200, 23), arrayStringFor_WxComboBoxMail, wxCB_READONLY, wxDefaultValidator, _("WxComboBoxMail"));
	WxFlexGridSizerStandardInputs->Add(WxComboBoxMail, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextNotes = new wxStaticText(this, ID_WXSTATICTEXTNOTES, _("Notes"), wxPoint(8, 117), wxDefaultSize, 0, _("WxStaticTextNotes"));
	WxFlexGridSizerStandardInputs->Add(WxStaticTextNotes, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditNotes = new wxTextCtrl(this, ID_WXEDITNOTES, _(""), wxPoint(56, 104), wxSize(200, 46), wxTE_MULTILINE, wxDefaultValidator, _("WxEditNotes"));
	WxFlexGridSizerStandardInputs->Add(WxEditNotes, 1, wxEXPAND | wxALL, 5);

	WxFlexGridSizerSecretInputs = new wxFlexGridSizer(0, 2, 0, 0);
	WxBoxSizerMain->Add(WxFlexGridSizerSecretInputs, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextPassword = new wxStaticText(this, ID_WXSTATICTEXTPASSWORD, _("Password"), wxPoint(11, 7), wxDefaultSize, 0, _("WxStaticTextPassword"));
	WxFlexGridSizerSecretInputs->Add(WxStaticTextPassword, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditPassword = new wxTextCtrl(this, ID_WXEDITPASSWORD, _(""), wxPoint(82, 5), wxSize(200, 23), 0, wxDefaultValidator, _("WxEditPassword"));
	WxFlexGridSizerSecretInputs->Add(WxEditPassword, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextKey = new wxStaticText(this, ID_WXSTATICTEXTKEY, _("Key"), wxPoint(27, 40), wxDefaultSize, 0, _("WxStaticTextKey"));
	WxFlexGridSizerSecretInputs->Add(WxStaticTextKey, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditKey = new wxTextCtrl(this, ID_WXEDITKEY, _(""), wxPoint(82, 38), wxSize(200, 23), wxTE_PASSWORD, wxDefaultValidator, _("WxEditKey"));
	WxFlexGridSizerSecretInputs->Add(WxEditKey, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextKeyRepeat = new wxStaticText(this, ID_WXSTATICTEXTKEYREPEAT, _("Key (repeat)"), wxPoint(5, 73), wxDefaultSize, 0, _("WxStaticTextKeyRepeat"));
	WxFlexGridSizerSecretInputs->Add(WxStaticTextKeyRepeat, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditKeyRepeat = new wxTextCtrl(this, ID_WXEDITKEYREPEAT, _(""), wxPoint(82, 71), wxSize(200, 23), wxTE_PASSWORD, wxDefaultValidator, _("WxEditKeyRepeat"));
	WxFlexGridSizerSecretInputs->Add(WxEditKeyRepeat, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizerButtonBar = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizerMain->Add(WxBoxSizerButtonBar, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonAddMail = new wxButton(this, ID_WXBUTTONADDMAIL, _("Add Mail"), wxPoint(5, 5), wxSize(75, 25), 0, wxDefaultValidator, _("WxButtonAddMail"));
	WxBoxSizerButtonBar->Add(WxButtonAddMail, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizerButtonBarFiller = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizerButtonBar->Add(WxBoxSizerButtonBarFiller, 1, wxEXPAND | wxALL, 5);

	WxButtonCancel = new wxButton(this, ID_WXBUTTONCANCEL, _("Cancel"), wxPoint(120, 5), wxSize(75, 25), 0, wxDefaultValidator, _("WxButtonCancel"));
	WxBoxSizerButtonBar->Add(WxButtonCancel, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonAddEntry = new wxButton(this, ID_WXBUTTONADDENTRY, _("Add Entry"), wxPoint(205, 5), wxSize(75, 25), 0, wxDefaultValidator, _("WxButtonAddEntry"));
	WxBoxSizerButtonBar->Add(WxButtonAddEntry, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("Add Entry"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
}

std::string WordFortressAddEntryGui::GetKeyRepeat()
{
	return WxEditKeyRepeat->GetValue().ToStdString();
}

std::string WordFortressAddEntryGui::GetKey()
{
	return WxEditKey->GetValue().ToStdString();
}

std::string WordFortressAddEntryGui::GetPassword()
{
	return WxEditPassword->GetValue().ToStdString();
}

std::string WordFortressAddEntryGui::GetNotes()
{
	return WxEditNotes->GetValue().ToStdString();
}

int WordFortressAddEntryGui::GetMailIndex()
{
	return WxComboBoxMail->GetCurrentSelection();
}

std::string WordFortressAddEntryGui::GetUser()
{
	return WxEditUser->GetValue().ToStdString();
}

std::string WordFortressAddEntryGui::GetService()
{
	return WxEditService->GetValue().ToStdString();
}

void WordFortressAddEntryGui::SetMails(const std::list<std::tuple<int, std::string>>& mails)
{
	WxComboBoxMail->Clear();

	for (const auto& mail : mails)
	{
		WxComboBoxMail->Append(std::get<1>(mail));
	}
}

void WordFortressAddEntryGui::SetMailIndex(int index)
{
	if (WxComboBoxMail->GetCount() > index)
	{
		WxComboBoxMail->SetSelection(index);
	}
#ifdef _DEBUG
	else
	{
		std::cout << "SetMailIndex in WordFortressAddEntryGui failed. ItemCount (" << WxComboBoxMail->GetCount() << ") should be higher than the new index (" << index << ")." << std::endl;
	}
#endif
}

void WordFortressAddEntryGui::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxButtonAddEntryClick
 */
void WordFortressAddEntryGui::WxButtonAddEntryClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(AddEntryGuiAction::ADD_ENTRY);
}

/*
 * WxButtonCancelClick
 */
void WordFortressAddEntryGui::WxButtonCancelClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(AddEntryGuiAction::CANCEL);
}

/*
 * WxButtonAddMailClick
 */
void WordFortressAddEntryGui::WxButtonAddMailClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(AddEntryGuiAction::ADD_MAIL);
}

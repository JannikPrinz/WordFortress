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

	WxStaticTextService = new wxStaticText(this, ID_WXSTATICTEXTSERVICE, _("Service"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticTextService"));
	WxFlexGridSizerStandardInputs->Add(WxStaticTextService, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditService = new wxTextCtrl(this, ID_WXEDITSERVICE, _(""), wxPoint(56, 5), wxSize(121, 19), 0, wxDefaultValidator, _("WxEditService"));
	WxFlexGridSizerStandardInputs->Add(WxEditService, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextUser = new wxStaticText(this, ID_WXSTATICTEXTUSER, _("User"), wxPoint(12, 34), wxDefaultSize, 0, _("WxStaticTextUser"));
	WxFlexGridSizerStandardInputs->Add(WxStaticTextUser, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditUser = new wxTextCtrl(this, ID_WXEDITUSER, _(""), wxPoint(56, 34), wxSize(121, 19), 0, wxDefaultValidator, _("WxEditUser"));
	WxFlexGridSizerStandardInputs->Add(WxEditUser, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextEMail = new wxStaticText(this, ID_WXSTATICTEXTEMAIL, _("E-Mail"), wxPoint(6, 63), wxDefaultSize, 0, _("WxStaticTextEMail"));
	WxFlexGridSizerStandardInputs->Add(WxStaticTextEMail, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditEMail = new wxTextCtrl(this, ID_WXEDITEMAIL, _(""), wxPoint(56, 63), wxSize(121, 19), 0, wxDefaultValidator, _("WxEditEMail"));
	WxFlexGridSizerStandardInputs->Add(WxEditEMail, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextNotes = new wxStaticText(this, ID_WXSTATICTEXTNOTES, _("Notes"), wxPoint(8, 92), wxDefaultSize, 0, _("WxStaticTextNotes"));
	WxFlexGridSizerStandardInputs->Add(WxStaticTextNotes, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditNotes = new wxTextCtrl(this, ID_WXEDITNOTES, _(""), wxPoint(56, 92), wxSize(121, 19), wxTE_MULTILINE, wxDefaultValidator, _("WxEditNotes"));
	WxFlexGridSizerStandardInputs->Add(WxEditNotes, 1, wxEXPAND | wxALL, 5);

	WxFlexGridSizerSecretInputs = new wxFlexGridSizer(0, 2, 0, 0);
	WxBoxSizerMain->Add(WxFlexGridSizerSecretInputs, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextPassword = new wxStaticText(this, ID_WXSTATICTEXTPASSWORD, _("Password"), wxPoint(11, 5), wxDefaultSize, 0, _("WxStaticTextPassword"));
	WxFlexGridSizerSecretInputs->Add(WxStaticTextPassword, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditPassword = new wxTextCtrl(this, ID_WXEDITPASSWORD, _(""), wxPoint(82, 5), wxSize(121, 19), 0, wxDefaultValidator, _("WxEditPassword"));
	WxFlexGridSizerSecretInputs->Add(WxEditPassword, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextKey = new wxStaticText(this, ID_WXSTATICTEXTKEY, _("Key"), wxPoint(27, 34), wxDefaultSize, 0, _("WxStaticTextKey"));
	WxFlexGridSizerSecretInputs->Add(WxStaticTextKey, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditKey = new wxTextCtrl(this, ID_WXEDITKEY, _(""), wxPoint(82, 34), wxSize(121, 19), wxTE_PASSWORD, wxDefaultValidator, _("WxEditKey"));
	WxFlexGridSizerSecretInputs->Add(WxEditKey, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextKeyRepeat = new wxStaticText(this, ID_WXSTATICTEXTKEYREPEAT, _("Key (repeat)"), wxPoint(5, 63), wxDefaultSize, 0, _("WxStaticTextKeyRepeat"));
	WxFlexGridSizerSecretInputs->Add(WxStaticTextKeyRepeat, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditKeyRepeat = new wxTextCtrl(this, ID_WXEDITKEYREPEAT, _(""), wxPoint(82, 63), wxSize(121, 19), wxTE_PASSWORD, wxDefaultValidator, _("WxEditKeyRepeat"));
	WxFlexGridSizerSecretInputs->Add(WxEditKeyRepeat, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizerButtonBar = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizerMain->Add(WxBoxSizerButtonBar, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizerButtonBarFiller = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizerButtonBar->Add(WxBoxSizerButtonBarFiller, 1, wxEXPAND | wxALL, 5);

	WxButtonCancel = new wxButton(this, ID_WXBUTTONCANCEL, _("Cancel"), wxPoint(35, 5), wxSize(75, 25), 0, wxDefaultValidator, _("WxButtonCancel"));
	WxBoxSizerButtonBar->Add(WxButtonCancel, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonAddEntry = new wxButton(this, ID_WXBUTTONADDENTRY, _("Add Entry"), wxPoint(120, 5), wxSize(75, 25), 0, wxDefaultValidator, _("WxButtonAddEntry"));
	WxBoxSizerButtonBar->Add(WxButtonAddEntry, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("Add Entry"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
}

void WordFortressAddEntryGui::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

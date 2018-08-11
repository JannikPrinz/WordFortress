///-----------------------------------------------------------------
///
/// @file      WordFortressAddMailGui.cpp
/// @author    Jannik Prinz
/// Created:   21.05.2018 21:13:55
/// @section   DESCRIPTION
///            WordFortressAddMailGui class implementation
///
///------------------------------------------------------------------

#include "WordFortressAddMailGui.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// WordFortressAddMailGui
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(WordFortressAddMailGui,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(WordFortressAddMailGui::OnClose)
	EVT_BUTTON(ID_WXBUTTONADDMAIL,WordFortressAddMailGui::WxButtonAddMailClick)
	EVT_BUTTON(ID_WXBUTTONCANCEL,WordFortressAddMailGui::WxButtonCancelClick)
END_EVENT_TABLE()
////Event Table End

WordFortressAddMailGui::WordFortressAddMailGui(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

WordFortressAddMailGui::~WordFortressAddMailGui()
{
} 

void WordFortressAddMailGui::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizerMain = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(WxBoxSizerMain);
	this->SetAutoLayout(true);

	WxBoxSizerMailEntry = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizerMain->Add(WxBoxSizerMailEntry, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticTextMailaddress = new wxStaticText(this, ID_WXSTATICTEXTMAILADDRESS, _("Mailaddress:"), wxPoint(5, 5), wxDefaultSize, 0, _("WxStaticTextMailaddress"));
	WxBoxSizerMailEntry->Add(WxStaticTextMailaddress, 0, wxALIGN_CENTER | wxALL, 5);

	WxEditMailaddress = new wxTextCtrl(this, ID_WXEDITMAILADDRESS, _(""), wxPoint(85, 5), wxSize(121, 19), 0, wxDefaultValidator, _("WxEditMailaddress"));
	WxBoxSizerMailEntry->Add(WxEditMailaddress, 1, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizerButtons = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizerMain->Add(WxBoxSizerButtons, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizerButtonFiller = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizerButtons->Add(WxBoxSizerButtonFiller, 1, wxALIGN_CENTER | wxALL, 5);

	WxButtonCancel = new wxButton(this, ID_WXBUTTONCANCEL, _("Cancel"), wxPoint(35, 5), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonCancel"));
	WxBoxSizerButtons->Add(WxButtonCancel, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonAddMail = new wxButton(this, ID_WXBUTTONADDMAIL, _("Add Mail"), wxPoint(145, 5), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonAddMail"));
	WxBoxSizerButtons->Add(WxButtonAddMail, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("Add Mail"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
}

std::string WordFortressAddMailGui::GetMail()
{
	return WxEditMailaddress->GetValue().ToStdString();
}

void WordFortressAddMailGui::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxButtonAddMailClick
 */
void WordFortressAddMailGui::WxButtonAddMailClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(AddMailGuiAction::ADD_MAIL);
}

/*
 * WxButtonCancelClick
 */
void WordFortressAddMailGui::WxButtonCancelClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(AddMailGuiAction::CANCEL);
}

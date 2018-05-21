///-----------------------------------------------------------------
///
/// @file      WordFortressManageMailsGui.cpp
/// @author    Jannik Prinz
/// Created:   21.05.2018 21:02:35
/// @section   DESCRIPTION
///            WordFortressManageMailsGui class implementation
///
///------------------------------------------------------------------

#include "WordFortressManageMailsGui.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// WordFortressManageMailsGui
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(WordFortressManageMailsGui,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(WordFortressManageMailsGui::OnClose)
	EVT_BUTTON(ID_WXBUTTONBACK,WordFortressManageMailsGui::WxButtonBackClick)
	EVT_BUTTON(ID_WXBUTTONDELETEMAIL,WordFortressManageMailsGui::WxButtonDeleteMailClick)
	EVT_BUTTON(ID_WXBUTTONCHANGEMAIL,WordFortressManageMailsGui::WxButtonChangeMailClick)
	EVT_BUTTON(ID_WXBUTTONADDMAIL,WordFortressManageMailsGui::WxButtonAddMailClick)
END_EVENT_TABLE()
////Event Table End

WordFortressManageMailsGui::WordFortressManageMailsGui(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

WordFortressManageMailsGui::~WordFortressManageMailsGui()
{
} 

void WordFortressManageMailsGui::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizerMain = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizerMain);
	this->SetAutoLayout(true);

	WxBoxSizerMailOverview = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizerMain->Add(WxBoxSizerMailOverview, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizerButtons = new wxBoxSizer(wxVERTICAL);
	WxBoxSizerMain->Add(WxBoxSizerButtons, 0, wxALIGN_CENTER | wxALL, 5);

	WxListCtrlMails = new wxListCtrl(this, ID_WXLISTCTRLMAILS, wxPoint(5, 5), wxSize(257, 153), wxLC_REPORT, wxDefaultValidator, _("WxListCtrlMails"));
	WxListCtrlMails->InsertColumn(0, _("Mailaddress"), wxLIST_FORMAT_LEFT, 200);
	WxListCtrlMails->InsertColumn(1, _("Times used"), wxLIST_FORMAT_LEFT, 75);
	WxBoxSizerMailOverview->Add(WxListCtrlMails, 1, wxALIGN_CENTER | wxALL, 5);

	WxButtonAddMail = new wxButton(this, ID_WXBUTTONADDMAIL, _("Add Mail"), wxPoint(5, 5), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonAddMail"));
	WxBoxSizerButtons->Add(WxButtonAddMail, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonChangeMail = new wxButton(this, ID_WXBUTTONCHANGEMAIL, _("Change Mail"), wxPoint(5, 40), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonChangeMail"));
	WxBoxSizerButtons->Add(WxButtonChangeMail, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonDeleteMail = new wxButton(this, ID_WXBUTTONDELETEMAIL, _("Delete Mail"), wxPoint(5, 75), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonDeleteMail"));
	WxBoxSizerButtons->Add(WxButtonDeleteMail, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizerButtonFiller = new wxBoxSizer(wxVERTICAL);
	WxBoxSizerButtons->Add(WxBoxSizerButtonFiller, 1, wxALIGN_CENTER | wxALL, 5);

	WxButtonBack = new wxButton(this, ID_WXBUTTONBACK, _("Back"), wxPoint(5, 140), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonBack"));
	WxBoxSizerButtons->Add(WxButtonBack, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("Mailaddress Manager"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
}

void WordFortressManageMailsGui::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxButtonAddMailClick
 */
void WordFortressManageMailsGui::WxButtonAddMailClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(ManageMailsGuiAction::ADD_MAIL);
}

/*
 * WxButtonChangeMailClick
 */
void WordFortressManageMailsGui::WxButtonChangeMailClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(ManageMailsGuiAction::CHANGE_MAIL);
}

/*
 * WxButtonDeleteMailClick
 */
void WordFortressManageMailsGui::WxButtonDeleteMailClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(ManageMailsGuiAction::DELETE_MAIL);
}

/*
 * WxButtonBackClick
 */
void WordFortressManageMailsGui::WxButtonBackClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(ManageMailsGuiAction::BACK);
}

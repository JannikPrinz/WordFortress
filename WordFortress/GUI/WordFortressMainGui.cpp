///-----------------------------------------------------------------
///
/// @file      WordFortressMainGui.cpp
/// @author    Jannik Prinz
/// Created:   23.04.2018 20:48:36
/// @section   DESCRIPTION
///            WordFortressMainGui class implementation
///
///------------------------------------------------------------------

#include "wordFortressMainGui.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// WordFortressMainGui
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(WordFortressMainGui,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(WordFortressMainGui::OnClose)
	EVT_BUTTON(ID_WXBUTTONCHANGEKEY,WordFortressMainGui::WxButtonChangeKeyClick)
	EVT_BUTTON(ID_WXBUTTONDELETEENTRY,WordFortressMainGui::WxButtonDeleteEntryClick)
	EVT_BUTTON(ID_WXBUTTONCHANGEENTRY,WordFortressMainGui::WxButtonChangeEntryClick)
	EVT_BUTTON(ID_WXBUTTONMANAGEMAILS,WordFortressMainGui::WxButtonManageMailsClick)
	EVT_BUTTON(ID_WXBUTTONCHANGEPASSWORD,WordFortressMainGui::WxButtonChangePasswordClick)
	EVT_BUTTON(ID_WXBUTTONSHOWPASSWORD,WordFortressMainGui::WxButtonShowPasswordClick)
	EVT_BUTTON(ID_WXBUTTONADDENTRY,WordFortressMainGui::WxButtonAddEntryClick)
END_EVENT_TABLE()
////Event Table End

WordFortressMainGui::WordFortressMainGui(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

WordFortressMainGui::~WordFortressMainGui()
{
}

void WordFortressMainGui::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizerMain = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizerMain);
	this->SetAutoLayout(true);

	WxBoxSizerLeft = new wxBoxSizer(wxVERTICAL);
	WxBoxSizerMain->Add(WxBoxSizerLeft, 1, wxEXPAND | wxALL, 5);

	WxBoxSizerSearchBar = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizerLeft->Add(WxBoxSizerSearchBar, 0, wxEXPAND | wxALL, 5);

	WxEditSearch = new wxTextCtrl(this, ID_WXEDITSEARCH, _(""), wxPoint(5, 8), wxSize(121, 19), 0, wxDefaultValidator, _("WxEditSearch"));
	WxBoxSizerSearchBar->Add(WxEditSearch, 1, wxEXPAND | wxALL, 5);

	WxButtonSearch = new wxButton(this, ID_WXBUTTONSEARCH, _("Search"), wxPoint(136, 5), wxSize(75, 25), 0, wxDefaultValidator, _("WxButtonSearch"));
	WxBoxSizerSearchBar->Add(WxButtonSearch, 0, wxALIGN_CENTER | wxALL, 5);

	WxListEntries = new wxListCtrl(this, ID_WXLISTENTRIES, wxPoint(5, 50), wxSize(250, 157), wxLC_REPORT | wxLC_SINGLE_SEL, wxDefaultValidator, _("WxListEntries"));
	WxListEntries->InsertColumn(0, _("Service"), wxLIST_FORMAT_LEFT, -1);
	WxListEntries->InsertColumn(1, _("Username"), wxLIST_FORMAT_LEFT, -1);
	WxListEntries->InsertColumn(2, _("E-Mail"), wxLIST_FORMAT_LEFT, -1);
	WxListEntries->InsertColumn(3, _("Notes"), wxLIST_FORMAT_LEFT, -1);
	WxBoxSizerLeft->Add(WxListEntries, 1, wxEXPAND | wxALL, 5);

	WxBoxSizerRight = new wxBoxSizer(wxVERTICAL);
	WxBoxSizerMain->Add(WxBoxSizerRight, 0, wxALIGN_CENTER | wxALL, 5);

	wxArrayString arrayStringFor_WxBitmapComboBoxLanguageSelector;
	arrayStringFor_WxBitmapComboBoxLanguageSelector.Add(_("English"));
	arrayStringFor_WxBitmapComboBoxLanguageSelector.Add(_("Deutsch"));
	WxBitmapComboBoxLanguageSelector = new wxBitmapComboBox(this, ID_WXBITMAPCOMBOBOXLANGUAGESELECTOR, _("WxBitmapComboBoxLanguageSelector"), wxPoint(5, 5), wxSize(100, 23), arrayStringFor_WxBitmapComboBoxLanguageSelector, wxCB_READONLY, wxDefaultValidator, _("WxBitmapComboBoxLanguageSelector"));
	WxBoxSizerRight->Add(WxBitmapComboBoxLanguageSelector, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonAddEntry = new wxButton(this, ID_WXBUTTONADDENTRY, _("Add Entry"), wxPoint(5, 38), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonAddEntry"));
	WxBoxSizerRight->Add(WxButtonAddEntry, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonShowPassword = new wxButton(this, ID_WXBUTTONSHOWPASSWORD, _("Show Password"), wxPoint(5, 73), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonShowPassword"));
	WxBoxSizerRight->Add(WxButtonShowPassword, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonChangePassword = new wxButton(this, ID_WXBUTTONCHANGEPASSWORD, _("Change Password"), wxPoint(5, 108), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonChangePassword"));
	WxBoxSizerRight->Add(WxButtonChangePassword, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonManageMails = new wxButton(this, ID_WXBUTTONMANAGEMAILS, _("Manage Mails"), wxPoint(5, 143), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonManageMails"));
	WxBoxSizerRight->Add(WxButtonManageMails, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonChangeEntry = new wxButton(this, ID_WXBUTTONCHANGEENTRY, _("Change Entry"), wxPoint(5, 178), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonChangeEntry"));
	WxBoxSizerRight->Add(WxButtonChangeEntry, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonDeleteEntry = new wxButton(this, ID_WXBUTTONDELETEENTRY, _("Delete Entry"), wxPoint(5, 213), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonDeleteEntry"));
	WxBoxSizerRight->Add(WxButtonDeleteEntry, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonChangeKey = new wxButton(this, ID_WXBUTTONCHANGEKEY, _("Change Key"), wxPoint(5, 248), wxSize(100, 25), 0, wxDefaultValidator, _("WxButtonChangeKey"));
	WxBoxSizerRight->Add(WxButtonChangeKey, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("WordFortress"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End

	// Set default language selection:
	WxBitmapComboBoxLanguageSelector->SetSelection(0);
}

int WordFortressMainGui::GetEntryIndex()
{
	int itemIndex = -1;

	while ((itemIndex = WxListEntries->GetNextItem(itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED)) != wxNOT_FOUND) {
		return itemIndex;
	}
}

void WordFortressMainGui::SetEntries(const std::vector<std::tuple<int, std::string, std::string, int, std::string, int>>& entries, const std::vector<std::tuple<int, std::string>>& mails)
{
	WxListEntries->DeleteAllItems();

	int id = 0;
	for (const auto& entry : entries)
	{
		WxListEntries->InsertItem(id, std::get<1>(entry));
		WxListEntries->SetItem(id, 1, std::get<2>(entry));
		int mailId = std::get<3>(entry);
		auto& it = std::find_if(mails.begin(), mails.end(), [&mailId](const auto& mail) { return mailId == std::get<0>(mail); });
		WxListEntries->SetItem(id, 2, it != mails.end() ? std::get<1>(*it) : "");
		WxListEntries->SetItem(id++, 3, std::get<4>(entry));
	}
}

void WordFortressMainGui::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * WxButtonAddEntryClick
 */
void WordFortressMainGui::WxButtonAddEntryClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(MainGuiAction::ADD_ENTRY);
}

/*
 * WxButtonChangeEntryClick
 */
void WordFortressMainGui::WxButtonChangeEntryClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(MainGuiAction::CHANGE_ENTRY);
}

/*
 * WxButtonDeleteEntryClick
 */
void WordFortressMainGui::WxButtonDeleteEntryClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(MainGuiAction::DELETE_ENTRY);
}

/*
 * WxButtonShowPasswordClick
 */
void WordFortressMainGui::WxButtonShowPasswordClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(MainGuiAction::SHOW_PASSWORD);
}

/*
 * WxButtonChangePasswordClick
 */
void WordFortressMainGui::WxButtonChangePasswordClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(MainGuiAction::CHANGE_PASSWORD);
}

/*
 * WxButtonChangeKeyClick
 */
void WordFortressMainGui::WxButtonChangeKeyClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(MainGuiAction::CHANGE_KEY);
}

/*
 * WxButtonManageMailsClick
 */
void WordFortressMainGui::WxButtonManageMailsClick(wxCommandEvent& event)
{
	// insert your code here
	CallCBFunction(MainGuiAction::MANAGE_MAILS);
}

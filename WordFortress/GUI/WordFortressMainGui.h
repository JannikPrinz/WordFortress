///-----------------------------------------------------------------
///
/// @file      WordFortressMainGui.h
/// @author    Jannik Prinz
/// Created:   23.04.2018 20:48:36
/// @section   DESCRIPTION
///            WordFortressMainGui class declaration
///
///------------------------------------------------------------------

#ifndef __WORDFORTRESSMAINGUI_H__
#define __WORDFORTRESSMAINGUI_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/bmpcbox.h>
#include <wx/listctrl.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
////Header Include End

#include "../callbackMap.h"

////Dialog Style Start
#undef WordFortressMainGui_STYLE
#define WordFortressMainGui_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

enum class MainGuiAction
{
	CHANGE_KEY, CHANGE_PASSWORD, SHOW_PASSWORD, DELETE_ENTRY, CHANGE_ENTRY, ADD_ENTRY, CHANGE_LANGUAGE, FILTER_ENTRIES, MANAGE_MAILS
};

class WordFortressMainGui : public wxFrame, public CallbackMap<MainGuiAction>
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		WordFortressMainGui(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Unbenannt1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = WordFortressMainGui_STYLE);
		virtual ~WordFortressMainGui();
		void WxButtonAddEntryClick(wxCommandEvent& event);
		void WxButtonChangeEntryClick(wxCommandEvent& event);
		void WxButtonDeleteEntryClick(wxCommandEvent& event);
		void WxButtonShowPasswordClick(wxCommandEvent& event);
		void WxButtonChangePasswordClick(wxCommandEvent& event);
		void WxButtonChangeKeyClick(wxCommandEvent& event);
		void WxButtonManageMailsClick(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButtonChangeKey;
		wxButton *WxButtonDeleteEntry;
		wxButton *WxButtonChangeEntry;
		wxButton *WxButtonManageMails;
		wxButton *WxButtonChangePassword;
		wxButton *WxButtonShowPassword;
		wxButton *WxButtonAddEntry;
		wxBitmapComboBox *WxBitmapComboBoxLanguageSelector;
		wxBoxSizer *WxBoxSizerRight;
		wxListCtrl *WxListEntries;
		wxButton *WxButtonSearch;
		wxTextCtrl *WxEditSearch;
		wxBoxSizer *WxBoxSizerSearchBar;
		wxBoxSizer *WxBoxSizerLeft;
		wxBoxSizer *WxBoxSizerMain;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXBUTTONCHANGEKEY = 1017,
			ID_WXBUTTONDELETEENTRY = 1019,
			ID_WXBUTTONCHANGEENTRY = 1018,
			ID_WXBUTTONMANAGEMAILS = 1021,
			ID_WXBUTTONCHANGEPASSWORD = 1016,
			ID_WXBUTTONSHOWPASSWORD = 1015,
			ID_WXBUTTONADDENTRY = 1008,
			ID_WXBITMAPCOMBOBOXLANGUAGESELECTOR = 1020,
			ID_WXLISTENTRIES = 1010,
			ID_WXBUTTONSEARCH = 1014,
			ID_WXEDITSEARCH = 1013,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();

		// Not automatically generated stuff:
	public:
		int GetEntryIndex();

		void SetEntries(const std::vector<std::tuple<int, std::string, std::string, int, std::string, int>>& entries, const std::vector<std::tuple<int, std::string>>& mails);
};

#endif

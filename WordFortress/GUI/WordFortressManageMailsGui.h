///-----------------------------------------------------------------
///
/// @file      WordFortressManageMailsGui.h
/// @author    Jannik Prinz
/// Created:   21.05.2018 21:02:35
/// @section   DESCRIPTION
///            WordFortressManageMailsGui class declaration
///
///------------------------------------------------------------------

#ifndef __WORDFORTRESSMANAGEMAILSGUI_H__
#define __WORDFORTRESSMANAGEMAILSGUI_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/button.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
////Header Include End

#include "../callbackMap.h"
#include <list>

////Dialog Style Start
#undef WordFortressManageMailsGui_STYLE
#define WordFortressManageMailsGui_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

enum class ManageMailsGuiAction
{
	BACK, DELETE_MAIL, CHANGE_MAIL, ADD_MAIL
};

class WordFortressManageMailsGui : public wxDialog, public CallbackMap<ManageMailsGuiAction>
{
	private:
		DECLARE_EVENT_TABLE();
		void WxButtonAddMailClick(wxCommandEvent& event);
		
	public:
		WordFortressManageMailsGui(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Mailaddress Manager"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = WordFortressManageMailsGui_STYLE);
		virtual ~WordFortressManageMailsGui();
		void WxButtonChangeMailClick(wxCommandEvent& event);
		void WxButtonDeleteMailClick(wxCommandEvent& event);
		void WxButtonBackClick(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButtonBack;
		wxBoxSizer *WxBoxSizerButtonFiller;
		wxButton *WxButtonDeleteMail;
		wxButton *WxButtonChangeMail;
		wxButton *WxButtonAddMail;
		wxListCtrl *WxListCtrlMails;
		wxBoxSizer *WxBoxSizerButtons;
		wxBoxSizer *WxBoxSizerMailOverview;
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
			ID_WXBUTTONBACK = 1009,
			ID_WXBUTTONDELETEMAIL = 1007,
			ID_WXBUTTONCHANGEMAIL = 1006,
			ID_WXBUTTONADDMAIL = 1005,
			ID_WXLISTCTRLMAILS = 1004,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();

		// Not automatically generated stuff:
	public:
		void SetShownMails(const std::list<std::tuple<int, std::string, int>>& mails);
};

#endif

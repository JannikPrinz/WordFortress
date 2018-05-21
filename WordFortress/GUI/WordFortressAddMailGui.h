///-----------------------------------------------------------------
///
/// @file      WordFortressAddMailGui.h
/// @author    Jannik Prinz
/// Created:   21.05.2018 21:13:55
/// @section   DESCRIPTION
///            WordFortressAddMailGui class declaration
///
///------------------------------------------------------------------

#ifndef __WORDFORTRESSADDMAILGUI_H__
#define __WORDFORTRESSADDMAILGUI_H__

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
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
////Header Include End

#include "../callbackMap.h"

////Dialog Style Start
#undef WordFortressAddMailGui_STYLE
#define WordFortressAddMailGui_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxCLOSE_BOX
////Dialog Style End

enum class AddMailGuiAction
{
	ADD_MAIL, CANCEL
};

class WordFortressAddMailGui : public wxDialog, public CallbackMap<AddMailGuiAction>
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		WordFortressAddMailGui(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Add Mail"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = WordFortressAddMailGui_STYLE);
		virtual ~WordFortressAddMailGui();
		void WxButtonAddMailClick(wxCommandEvent& event);
		void WxButtonCancelClick(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButtonAddMail;
		wxButton *WxButtonCancel;
		wxBoxSizer *WxBoxSizerButtonFiller;
		wxBoxSizer *WxBoxSizerButtons;
		wxTextCtrl *WxEditMailaddress;
		wxStaticText *WxStaticTextMailaddress;
		wxBoxSizer *WxBoxSizerMailEntry;
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
			ID_WXBUTTONADDMAIL = 1006,
			ID_WXBUTTONCANCEL = 1007,
			ID_WXEDITMAILADDRESS = 1005,
			ID_WXSTATICTEXTMAILADDRESS = 1004,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif

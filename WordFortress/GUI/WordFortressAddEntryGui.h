///-----------------------------------------------------------------
///
/// @file      WordFortressAddEntryGui.h
/// @author    Jannik Prinz
/// Created:   29.04.2018 13:23:41
/// @section   DESCRIPTION
///            WordFortressAddEntryGui class declaration
///
///------------------------------------------------------------------

#ifndef __WORDFORTRESSADDENTRYGUI_H__
#define __WORDFORTRESSADDENTRYGUI_H__

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
#include <wx/combobox.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
////Header Include End

#include "../callbackMap.h"

////Dialog Style Start
#undef WordFortressAddEntryGui_STYLE
#define WordFortressAddEntryGui_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

enum class AddEntryGuiAction
{
	ADD_ENTRY, CANCEL, ADD_MAIL
};

class WordFortressAddEntryGui : public wxDialog, public CallbackMap<AddEntryGuiAction>
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		WordFortressAddEntryGui(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Add Entry"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = WordFortressAddEntryGui_STYLE);
		virtual ~WordFortressAddEntryGui();
		void WxButtonAddEntryClick(wxCommandEvent& event);
		void WxButtonCancelClick(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButtonAddEntry;
		wxButton *WxButtonCancel;
		wxBoxSizer *WxBoxSizerButtonBarFiller;
		wxButton *WxButtonAddMail;
		wxBoxSizer *WxBoxSizerButtonBar;
		wxTextCtrl *WxEditKeyRepeat;
		wxStaticText *WxStaticTextKeyRepeat;
		wxTextCtrl *WxEditKey;
		wxStaticText *WxStaticTextKey;
		wxTextCtrl *WxEditPassword;
		wxStaticText *WxStaticTextPassword;
		wxFlexGridSizer *WxFlexGridSizerSecretInputs;
		wxTextCtrl *WxEditNotes;
		wxStaticText *WxStaticTextNotes;
		wxComboBox *WxComboBoxMail;
		wxStaticText *WxStaticTextEMail;
		wxTextCtrl *WxEditUser;
		wxStaticText *WxStaticTextUser;
		wxTextCtrl *WxEditService;
		wxStaticText *WxStaticTextService;
		wxFlexGridSizer *WxFlexGridSizerStandardInputs;
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
			ID_WXBUTTONADDENTRY = 1005,
			ID_WXBUTTONCANCEL = 1004,
			ID_WXBUTTONADDMAIL = 1029,
			ID_WXEDITKEYREPEAT = 1027,
			ID_WXSTATICTEXTKEYREPEAT = 1026,
			ID_WXEDITKEY = 1025,
			ID_WXSTATICTEXTKEY = 1024,
			ID_WXEDITPASSWORD = 1023,
			ID_WXSTATICTEXTPASSWORD = 1022,
			ID_WXEDITNOTES = 1020,
			ID_WXSTATICTEXTNOTES = 1015,
			ID_WXCOMBOBOXMAIL = 1028,
			ID_WXSTATICTEXTEMAIL = 1014,
			ID_WXEDITUSER = 1017,
			ID_WXSTATICTEXTUSER = 1013,
			ID_WXEDITSERVICE = 1016,
			ID_WXSTATICTEXTSERVICE = 1012,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();

		// Not automatically generated stuff:
	public:
		std::string GetKeyRepeat();
		std::string GetKey();
		std::string GetPassword();
		std::string GetNotes();
		int GetMailIndex();
		std::string GetUser();
		std::string GetService();
		void WxButtonAddMailClick(wxCommandEvent& event);
};

#endif

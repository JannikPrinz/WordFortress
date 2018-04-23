///-----------------------------------------------------------------
///
/// @file      WordFortressMainGui.h
/// @author    Jannik
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
#include <wx/button.h>
#include <wx/grid.h>
////Header Include End

////Dialog Style Start
#undef WordFortressMainGui_STYLE
#define WordFortressMainGui_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class WordFortressMainGui : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
		void WxButton1Click(wxCommandEvent& event);
	public:
		WordFortressMainGui(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Unbenannt1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = WordFortressMainGui_STYLE);
		virtual ~WordFortressMainGui();
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButton1;
		wxGrid *WxGrid1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXBUTTON1 = 1003,
			ID_WXGRID1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif

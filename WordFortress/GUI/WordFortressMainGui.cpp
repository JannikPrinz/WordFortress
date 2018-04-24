///-----------------------------------------------------------------
///
/// @file      WordFortressMainGui.cpp
/// @author    Jannik
/// Created:   23.04.2018 20:48:36
/// @section   DESCRIPTION
///            WordFortressMainGui class implementation
///
///------------------------------------------------------------------

#include "WordFortressMainGui.h"

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
	EVT_BUTTON(ID_WXBUTTON1,WordFortressMainGui::WxButton1Click)
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

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("WxButton1"), wxPoint(467, 116), wxSize(291, 25), 0, wxDefaultValidator, _("WxButton1"));

	WxGrid1 = new wxGrid(this, ID_WXGRID1, wxPoint(95, 199), wxSize(710, 218));
	WxGrid1->SetDefaultColSize(50);
	WxGrid1->SetDefaultRowSize(25);
	WxGrid1->SetRowLabelSize(50);
	WxGrid1->SetColLabelSize(25);
	WxGrid1->CreateGrid(5,5,wxGrid::wxGridSelectCells);

	SetTitle(_("Unbenannt1"));
	SetIcon(wxNullIcon);
	SetSize(8,8,983,491);
	Center();
	
	////GUI Items Creation End
}

void WordFortressMainGui::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * WxButton1Click
 */
void WordFortressMainGui::WxButton1Click(wxCommandEvent& event)
{
	// insert your code here
	this->WxButton1->SetLabelText("You clicked at the right place ;)");
}

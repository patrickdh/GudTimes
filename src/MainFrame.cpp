///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "MainFrame.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 1170,-1 ), wxDefaultSize );

	wxGridBagSizer* gbSizer3;
	gbSizer3 = new wxGridBagSizer( 0, 0 );
	gbSizer3->SetFlexibleDirection( wxBOTH );
	gbSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_splitter3 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxSize( 1150,730 ), wxSP_3D );
	m_splitter3->Connect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter3OnIdle ), NULL, this );
	m_splitter3->SetMinimumPaneSize( 1 );

	m_splitter3->SetMinSize( wxSize( 1150,-1 ) );

	m_panel5 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER|wxTAB_TRAVERSAL );
	m_panel5->SetMinSize( wxSize( 15,-1 ) );
	m_panel5->SetMaxSize( wxSize( 50,-1 ) );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	bSizer3->SetMinSize( wxSize( 50,-1 ) );
	m_staticText451 = new wxStaticText( m_panel5, wxID_ANY, wxT("Menu"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText451->Wrap( -1 );
	m_staticText451->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	bSizer3->Add( m_staticText451, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	m_staticline42 = new wxStaticLine( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline42, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	m_button11 = new wxButton( m_panel5, wxID_ANY, wxT("REFRESH"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button11->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	bSizer3->Add( m_button11, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	datePicker = new wxCalendarCtrl( m_panel5, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_MONDAY_FIRST|wxCAL_SHOW_HOLIDAYS );
	bSizer3->Add( datePicker, 0, wxALL, 5 );

	m_button10 = new wxButton( m_panel5, wxID_ANY, wxT("Add Calendar"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button10->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );

	bSizer3->Add( m_button10, 0, wxALL, 5 );

	m_button2 = new wxButton( m_panel5, wxID_ANY, wxT("Add Calendar URL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button2->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );

	bSizer3->Add( m_button2, 0, wxALL, 5 );

	m_staticText46 = new wxStaticText( m_panel5, wxID_ANY, wxT("My Calendars:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	m_staticText46->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	bSizer3->Add( m_staticText46, 0, wxALIGN_TOP|wxLEFT, 5 );

	calendarList = new wxListBox( m_panel5, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_MULTIPLE|wxLB_NEEDED_SB );
	bSizer3->Add( calendarList, 0, wxALL, 5 );

	m_button12 = new wxButton( m_panel5, wxID_ANY, wxT("Delete Calendar"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button12->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );

	bSizer3->Add( m_button12, 0, wxALL, 5 );

	m_button6 = new wxButton( m_panel5, wxID_ANY, wxT("Add Event"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button6->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );

	bSizer3->Add( m_button6, 0, wxALL, 5 );

	m_button7 = new wxButton( m_panel5, wxID_ANY, wxT("Schedule Event"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button7->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );

	bSizer3->Add( m_button7, 0, wxALL, 5 );

	m_button8 = new wxButton( m_panel5, wxID_ANY, wxT("Delete Event"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button8->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );

	bSizer3->Add( m_button8, 0, wxALL, 5 );

	notificationButton = new wxButton( m_panel5, wxID_ANY, wxT("Notifications"), wxDefaultPosition, wxDefaultSize, 0 );
	notificationButton->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );

	bSizer3->Add( notificationButton, 0, wxALL, 5 );


	bSizer3->Add( 0, 0, 1, wxEXPAND, 5 );

	LogoutButton = new wxButton( m_panel5, wxID_ANY, wxT("Logout"), wxDefaultPosition, wxDefaultSize, 0 );
	LogoutButton->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );

	bSizer3->Add( LogoutButton, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	m_panel5->SetSizer( bSizer3 );
	m_panel5->Layout();
	m_panel41 = new wxPanel( m_splitter3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer41;
	gbSizer41 = new wxGridBagSizer( 0, 0 );
	gbSizer41->SetFlexibleDirection( wxBOTH );
	gbSizer41->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_panel4 = new wxPanel( m_panel41, wxID_ANY, wxDefaultPosition, wxSize( -1,20 ), wxTAB_TRAVERSAL );
	m_panel4->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	m_panel4->SetMaxSize( wxSize( -1,50 ) );

	wxGridBagSizer* gbSizer4;
	gbSizer4 = new wxGridBagSizer( 0, 0 );
	gbSizer4->SetFlexibleDirection( wxBOTH );
	gbSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	gbSizer4->SetEmptyCellSize( wxSize( 0,0 ) );

	m_staticline267 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer4->Add( m_staticline267, wxGBPosition( 0, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText57 = new wxStaticText( m_panel4, wxID_ANY, wxT("Monday"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText57->Wrap( -1 );
	m_staticText57->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText57->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	m_staticText57->SetMinSize( wxSize( -1,20 ) );

	gbSizer4->Add( m_staticText57, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticline268 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer4->Add( m_staticline268, wxGBPosition( 0, 3 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText58 = new wxStaticText( m_panel4, wxID_ANY, wxT("Tuesday"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText58->Wrap( -1 );
	m_staticText58->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText58->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer4->Add( m_staticText58, wxGBPosition( 0, 4 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticline269 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer4->Add( m_staticline269, wxGBPosition( 0, 5 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText59 = new wxStaticText( m_panel4, wxID_ANY, wxT("Wednesday"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText59->Wrap( -1 );
	m_staticText59->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText59->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer4->Add( m_staticText59, wxGBPosition( 0, 6 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticline270 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer4->Add( m_staticline270, wxGBPosition( 0, 7 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText60 = new wxStaticText( m_panel4, wxID_ANY, wxT("Thursday"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText60->Wrap( -1 );
	m_staticText60->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText60->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer4->Add( m_staticText60, wxGBPosition( 0, 8 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticline27123 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer4->Add( m_staticline27123, wxGBPosition( 0, 9 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText61 = new wxStaticText( m_panel4, wxID_ANY, wxT("Friday"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText61->Wrap( -1 );
	m_staticText61->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText61->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer4->Add( m_staticText61, wxGBPosition( 0, 10 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticline2721 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer4->Add( m_staticline2721, wxGBPosition( 0, 11 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText62 = new wxStaticText( m_panel4, wxID_ANY, wxT("Saturday"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText62->Wrap( -1 );
	m_staticText62->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText62->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer4->Add( m_staticText62, wxGBPosition( 0, 12 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticline273 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer4->Add( m_staticline273, wxGBPosition( 0, 13 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText63 = new wxStaticText( m_panel4, wxID_ANY, wxT("Sunday"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText63->Wrap( -1 );
	m_staticText63->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText63->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer4->Add( m_staticText63, wxGBPosition( 0, 14 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticline274 = new wxStaticLine( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer4->Add( m_staticline274, wxGBPosition( 0, 15 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText50 = new wxStaticText( m_panel4, wxID_ANY, wxT("00:00"), wxDefaultPosition, wxSize( -1,0 ), 0 );
	m_staticText50->Wrap( -1 );
	m_staticText50->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText50->SetForegroundColour( wxColour( 255, 255, 255 ) );

	gbSizer4->Add( m_staticText50, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxLEFT|wxRIGHT, 5 );

	m_textCtrl3391 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxTE_MULTILINE|wxTE_NO_VSCROLL|wxNO_BORDER );
	gbSizer4->Add( m_textCtrl3391, wxGBPosition( 1, 2 ), wxGBSpan( 1, 1 ), wxLEFT|wxRIGHT, 5 );

	m_textCtrl3401 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxTE_MULTILINE|wxTE_NO_VSCROLL|wxNO_BORDER );
	gbSizer4->Add( m_textCtrl3401, wxGBPosition( 1, 4 ), wxGBSpan( 1, 1 ), wxLEFT|wxRIGHT, 5 );

	m_textCtrl34110 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxTE_MULTILINE|wxTE_NO_VSCROLL|wxNO_BORDER );
	gbSizer4->Add( m_textCtrl34110, wxGBPosition( 1, 6 ), wxGBSpan( 1, 1 ), wxLEFT|wxRIGHT, 5 );

	m_textCtrl3422 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxTE_MULTILINE|wxTE_NO_VSCROLL|wxNO_BORDER );
	gbSizer4->Add( m_textCtrl3422, wxGBPosition( 1, 8 ), wxGBSpan( 1, 1 ), wxLEFT|wxRIGHT, 5 );

	m_textCtrl3431 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxTE_MULTILINE|wxTE_NO_VSCROLL|wxNO_BORDER );
	gbSizer4->Add( m_textCtrl3431, wxGBPosition( 1, 10 ), wxGBSpan( 1, 1 ), wxLEFT|wxRIGHT, 5 );

	m_textCtrl3441 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxTE_MULTILINE|wxTE_NO_VSCROLL|wxNO_BORDER );
	gbSizer4->Add( m_textCtrl3441, wxGBPosition( 1, 12 ), wxGBSpan( 1, 1 ), wxLEFT|wxRIGHT, 5 );

	m_textCtrl3451 = new wxTextCtrl( m_panel4, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxTE_MULTILINE|wxTE_NO_VSCROLL|wxNO_BORDER );
	gbSizer4->Add( m_textCtrl3451, wxGBPosition( 1, 14 ), wxGBSpan( 1, 1 ), wxLEFT|wxRIGHT, 5 );

	m_staticText52 = new wxStaticText( m_panel4, wxID_ANY, wxT("00:00"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText52->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	m_staticText52->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer4->Add( m_staticText52, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );


	gbSizer4->Add( 20, 0, wxGBPosition( 0, 16 ), wxGBSpan( 2, 1 ), 0, 5 );


	gbSizer4->AddGrowableCol( 2 );
	gbSizer4->AddGrowableCol( 4 );
	gbSizer4->AddGrowableCol( 6 );
	gbSizer4->AddGrowableCol( 8 );
	gbSizer4->AddGrowableCol( 10 );
	gbSizer4->AddGrowableCol( 12 );
	gbSizer4->AddGrowableCol( 14 );

	m_panel4->SetSizer( gbSizer4 );
	m_panel4->Layout();
	gbSizer41->Add( m_panel4, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_scrolledWindow3 = new wxScrolledWindow( m_panel41, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow3->SetScrollRate( 5, 5 );
	m_scrolledWindow3->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 2, 0 );
	gbSizer1->SetFlexibleDirection( wxBOTH );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	mon00 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	mon00->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Arial") ) );
	mon00->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	mon00->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	gbSizer1->Add( mon00, wxGBPosition( 2, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	m_staticline234 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline234->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Arial") ) );

	gbSizer1->Add( m_staticline234, wxGBPosition( 3, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline235 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline235, wxGBPosition( 5, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline236 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline236, wxGBPosition( 7, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline237 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline237, wxGBPosition( 9, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline238 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline238, wxGBPosition( 11, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline239 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline239, wxGBPosition( 13, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline240 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline240, wxGBPosition( 15, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline241 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline241, wxGBPosition( 17, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline242 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline242, wxGBPosition( 19, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline243 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline243, wxGBPosition( 21, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline244 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline244, wxGBPosition( 23, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline245 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline245, wxGBPosition( 25, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline246 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline246, wxGBPosition( 27, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline247 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline247, wxGBPosition( 29, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline248 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline248, wxGBPosition( 31, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline249 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline249, wxGBPosition( 33, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline250 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline250, wxGBPosition( 35, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline251 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline251, wxGBPosition( 37, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline252 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline252, wxGBPosition( 39, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline253 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline253, wxGBPosition( 41, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline254 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline254, wxGBPosition( 43, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline255 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline255, wxGBPosition( 45, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline256 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline256, wxGBPosition( 47, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	m_staticline257 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline257, wxGBPosition( 49, 0 ), wxGBSpan( 1, 15 ), wxEXPAND, 5 );

	tues00 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	tues00->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gbSizer1->Add( tues00, wxGBPosition( 2, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed00 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	wed00->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	gbSizer1->Add( wed00, wxGBPosition( 2, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs00 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxNO_BORDER );
	gbSizer1->Add( thurs00, wxGBPosition( 2, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri00 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri00, wxGBPosition( 2, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat00 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat00, wxGBPosition( 2, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun00 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun00, wxGBPosition( 2, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticline7771 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer1->Add( m_staticline7771, wxGBPosition( 0, 7 ), wxGBSpan( 51, 1 ), wxEXPAND | wxALL, 0 );

	m_staticline224 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL|wxLI_VERTICAL );
	gbSizer1->Add( m_staticline224, wxGBPosition( 0, 9 ), wxGBSpan( 51, 1 ), wxEXPAND | wxALL, 0 );

	time00 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("0:00"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	time00->Wrap( -1 );
	time00->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time00, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time01 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("01:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time01->Wrap( -1 );
	time01->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time01, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time02 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("02:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time02->Wrap( -1 );
	time02->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time02, wxGBPosition( 6, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time03 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("03:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time03->Wrap( -1 );
	time03->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time03, wxGBPosition( 8, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time04 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("04:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time04->Wrap( -1 );
	time04->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time04, wxGBPosition( 10, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time05 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("05:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time05->Wrap( -1 );
	time05->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time05, wxGBPosition( 12, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time06 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("06:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time06->Wrap( -1 );
	time06->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time06, wxGBPosition( 14, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time07 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("07:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time07->Wrap( -1 );
	time07->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time07, wxGBPosition( 16, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time08 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("08:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time08->Wrap( -1 );
	time08->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time08, wxGBPosition( 18, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time09 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("09:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time09->Wrap( -1 );
	time09->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time09, wxGBPosition( 20, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time10 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("10:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time10->Wrap( -1 );
	time10->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time10, wxGBPosition( 22, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time11 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("11:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time11->Wrap( -1 );
	time11->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time11, wxGBPosition( 24, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time12 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("12:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time12->Wrap( -1 );
	time12->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time12, wxGBPosition( 26, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time13 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("13:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time13->Wrap( -1 );
	time13->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time13, wxGBPosition( 28, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time14 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("14:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time14->Wrap( -1 );
	time14->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time14, wxGBPosition( 30, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time15 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("15:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time15->Wrap( -1 );
	time15->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time15, wxGBPosition( 32, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time16 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("16:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time16->Wrap( -1 );
	time16->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time16, wxGBPosition( 34, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time17 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("17:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time17->Wrap( -1 );
	time17->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time17, wxGBPosition( 36, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time18 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("18:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time18->Wrap( -1 );
	time18->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time18, wxGBPosition( 38, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time19 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("19:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time19->Wrap( -1 );
	time19->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time19, wxGBPosition( 40, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time20 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("20:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time20->Wrap( -1 );
	time20->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time20, wxGBPosition( 42, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time21 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("21:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time21->Wrap( -1 );
	time21->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time21, wxGBPosition( 44, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time22 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("22:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time22->Wrap( -1 );
	time22->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time22, wxGBPosition( 46, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	time23 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxT("23:00"), wxDefaultPosition, wxDefaultSize, 0 );
	time23->Wrap( -1 );
	time23->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	gbSizer1->Add( time23, wxGBPosition( 48, 0 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_staticline777 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer1->Add( m_staticline777, wxGBPosition( 0, 5 ), wxGBSpan( 51, 1 ), wxEXPAND | wxALL, 0 );

	m_staticline776 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer1->Add( m_staticline776, wxGBPosition( 0, 3 ), wxGBSpan( 51, 1 ), wxALL|wxEXPAND, 0 );

	m_staticText64 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxALIGN_CENTRE );
	m_staticText64->Wrap( -1 );
	m_staticText64->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText64->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer1->Add( m_staticText64, wxGBPosition( 0, 2 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText49 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), 0 );
	m_staticText49->Wrap( -1 );
	m_staticText49->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer1->Add( m_staticText49, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticline783 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer1->Add( m_staticline783, wxGBPosition( 0, 1 ), wxGBSpan( 51, 1 ), wxALL|wxEXPAND, 0 );

	m_staticline781 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	gbSizer1->Add( m_staticline781, wxGBPosition( 1, 0 ), wxGBSpan( 1, 15 ), wxEXPAND | wxALL, 0 );

	m_staticText65 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxALIGN_CENTRE );
	m_staticText65->Wrap( -1 );
	m_staticText65->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText65->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer1->Add( m_staticText65, wxGBPosition( 0, 4 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText66 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxALIGN_CENTRE );
	m_staticText66->Wrap( -1 );
	m_staticText66->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText66->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer1->Add( m_staticText66, wxGBPosition( 0, 6 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText25 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxALIGN_CENTRE );
	m_staticText25->Wrap( -1 );
	m_staticText25->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText25->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer1->Add( m_staticText25, wxGBPosition( 0, 8 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText26 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxALIGN_CENTRE );
	m_staticText26->Wrap( -1 );
	m_staticText26->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText26->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer1->Add( m_staticText26, wxGBPosition( 0, 10 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText27 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxALIGN_CENTRE );
	m_staticText27->Wrap( -1 );
	m_staticText27->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText27->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer1->Add( m_staticText27, wxGBPosition( 0, 12 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	m_staticText29 = new wxStaticText( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,0 ), wxALIGN_CENTRE );
	m_staticText29->Wrap( -1 );
	m_staticText29->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	m_staticText29->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	gbSizer1->Add( m_staticText29, wxGBPosition( 0, 14 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );

	mon01 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	mon01->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	gbSizer1->Add( mon01, wxGBPosition( 4, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon02 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon02, wxGBPosition( 6, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues02 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues02, wxGBPosition( 6, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed02 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed02, wxGBPosition( 6, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs02 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs02, wxGBPosition( 6, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri02 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri02, wxGBPosition( 6, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat02 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat02, wxGBPosition( 6, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun02 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun02, wxGBPosition( 6, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues01 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues01, wxGBPosition( 4, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed01 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed01, wxGBPosition( 4, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs01 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs01, wxGBPosition( 4, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri01 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri01, wxGBPosition( 4, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat01 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat01, wxGBPosition( 4, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun01 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun01, wxGBPosition( 4, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticline2241 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer1->Add( m_staticline2241, wxGBPosition( 0, 11 ), wxGBSpan( 51, 1 ), wxEXPAND | wxALL, 0 );

	m_staticline22411 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer1->Add( m_staticline22411, wxGBPosition( 0, 13 ), wxGBSpan( 51, 1 ), wxEXPAND | wxALL, 0 );

	m_staticline232 = new wxStaticLine( m_scrolledWindow3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	gbSizer1->Add( m_staticline232, wxGBPosition( 0, 15 ), wxGBSpan( 51, 1 ), wxEXPAND | wxALL, 0 );

	mon03 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon03, wxGBPosition( 8, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues03 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues03, wxGBPosition( 8, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed03 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed03, wxGBPosition( 8, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs03 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs03, wxGBPosition( 8, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri03 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri03, wxGBPosition( 8, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat03 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat03, wxGBPosition( 8, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun03 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun03, wxGBPosition( 8, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon04 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon04, wxGBPosition( 10, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues04 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues04, wxGBPosition( 10, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed04 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed04, wxGBPosition( 10, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs04 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs04, wxGBPosition( 10, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri04 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri04, wxGBPosition( 10, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat04 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat04, wxGBPosition( 10, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun04 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun04, wxGBPosition( 10, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon05 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon05, wxGBPosition( 12, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues05 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues05, wxGBPosition( 12, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed05 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed05, wxGBPosition( 12, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs05 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs05, wxGBPosition( 12, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri05 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri05, wxGBPosition( 12, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat05 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat05, wxGBPosition( 12, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun05 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun05, wxGBPosition( 12, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon06 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon06, wxGBPosition( 14, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues06 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues06, wxGBPosition( 14, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed06 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed06, wxGBPosition( 14, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs06 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs06, wxGBPosition( 14, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri06 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri06, wxGBPosition( 14, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat06 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat06, wxGBPosition( 14, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun06 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun06, wxGBPosition( 14, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon07 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon07, wxGBPosition( 16, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues07 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues07, wxGBPosition( 16, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed07 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed07, wxGBPosition( 16, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs07 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs07, wxGBPosition( 16, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri07 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri07, wxGBPosition( 16, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat07 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat07, wxGBPosition( 16, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun07 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun07, wxGBPosition( 16, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon08 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon08, wxGBPosition( 18, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues08 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues08, wxGBPosition( 18, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed08 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed08, wxGBPosition( 18, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs08 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs08, wxGBPosition( 18, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri08 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri08, wxGBPosition( 18, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat08 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat08, wxGBPosition( 18, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun08 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun08, wxGBPosition( 18, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon09 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon09, wxGBPosition( 20, 2 ), wxGBSpan( 1, 1 ), wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues09 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues09, wxGBPosition( 20, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed09 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed09, wxGBPosition( 20, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs09 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs09, wxGBPosition( 20, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri09 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri09, wxGBPosition( 20, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat09 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat09, wxGBPosition( 20, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun09 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun09, wxGBPosition( 20, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon10 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon10, wxGBPosition( 22, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues10 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues10, wxGBPosition( 22, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed10 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed10, wxGBPosition( 22, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs10 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs10, wxGBPosition( 22, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri10 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri10, wxGBPosition( 22, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat10 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat10, wxGBPosition( 22, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun10 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun10, wxGBPosition( 22, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon11 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon11, wxGBPosition( 24, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues11 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues11, wxGBPosition( 24, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed11 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed11, wxGBPosition( 24, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs11 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs11, wxGBPosition( 24, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri11 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri11, wxGBPosition( 24, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat11 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat11, wxGBPosition( 24, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun11 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun11, wxGBPosition( 24, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon12 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon12, wxGBPosition( 26, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues12 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues12, wxGBPosition( 26, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed12 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed12, wxGBPosition( 26, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs12 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs12, wxGBPosition( 26, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri12 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri12, wxGBPosition( 26, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat12 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat12, wxGBPosition( 26, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun12 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun12, wxGBPosition( 26, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon13 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon13, wxGBPosition( 28, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon14 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon14, wxGBPosition( 30, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon15 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon15, wxGBPosition( 32, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon16 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon16, wxGBPosition( 34, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues16 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues16, wxGBPosition( 34, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed16 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed16, wxGBPosition( 34, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs16 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs16, wxGBPosition( 34, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri16 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri16, wxGBPosition( 34, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat16 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat16, wxGBPosition( 34, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun16 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun16, wxGBPosition( 34, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon17 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon17, wxGBPosition( 36, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues17 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues17, wxGBPosition( 36, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed17 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed17, wxGBPosition( 36, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs17 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs17, wxGBPosition( 36, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri17 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri17, wxGBPosition( 36, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat17 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat17, wxGBPosition( 36, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun17 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun17, wxGBPosition( 36, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon18 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon18, wxGBPosition( 38, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues18 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues18, wxGBPosition( 38, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed18 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed18, wxGBPosition( 38, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs18 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs18, wxGBPosition( 38, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri18 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri18, wxGBPosition( 38, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat18 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat18, wxGBPosition( 38, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun18 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun18, wxGBPosition( 38, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon19 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon19, wxGBPosition( 40, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues19 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues19, wxGBPosition( 40, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed19 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed19, wxGBPosition( 40, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs19 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs19, wxGBPosition( 40, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri19 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri19, wxGBPosition( 40, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat19 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat19, wxGBPosition( 40, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun19 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun19, wxGBPosition( 40, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon20 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon20, wxGBPosition( 42, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues20 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues20, wxGBPosition( 42, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed20 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed20, wxGBPosition( 42, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs20 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs20, wxGBPosition( 42, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri20 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri20, wxGBPosition( 42, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat20 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat20, wxGBPosition( 42, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun20 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun20, wxGBPosition( 42, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon21 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon21, wxGBPosition( 44, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues21 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues21, wxGBPosition( 44, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed21 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed21, wxGBPosition( 44, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs21 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs21, wxGBPosition( 44, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri21 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri21, wxGBPosition( 44, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat21 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat21, wxGBPosition( 44, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun21 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun21, wxGBPosition( 44, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon22 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon22, wxGBPosition( 46, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues22 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues22, wxGBPosition( 46, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed22 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed22, wxGBPosition( 46, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs22 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs22, wxGBPosition( 46, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri22 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri22, wxGBPosition( 46, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat22 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat22, wxGBPosition( 46, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun22 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun22, wxGBPosition( 46, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	mon23 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( mon23, wxGBPosition( 48, 2 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues23 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues23, wxGBPosition( 48, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed23 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed23, wxGBPosition( 48, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs23 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs23, wxGBPosition( 48, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri23 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri23, wxGBPosition( 48, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat23 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat23, wxGBPosition( 48, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun23 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun23, wxGBPosition( 48, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues15 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues15, wxGBPosition( 32, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed15 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed15, wxGBPosition( 32, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs15 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs15, wxGBPosition( 32, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri15 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri15, wxGBPosition( 32, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat15 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat15, wxGBPosition( 32, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun15 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun15, wxGBPosition( 32, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues14 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues14, wxGBPosition( 30, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed14 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed14, wxGBPosition( 30, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs14 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs14, wxGBPosition( 30, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri14 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri14, wxGBPosition( 30, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat14 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat14, wxGBPosition( 30, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun14 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun14, wxGBPosition( 30, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	tues13 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( tues13, wxGBPosition( 28, 4 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	wed13 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( wed13, wxGBPosition( 28, 6 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	thurs13 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( thurs13, wxGBPosition( 28, 8 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	fri13 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( fri13, wxGBPosition( 28, 10 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sat13 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sat13, wxGBPosition( 28, 12 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );

	sun13 = new wxTextCtrl( m_scrolledWindow3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_MULTILINE|wxTE_NO_VSCROLL|wxTE_READONLY|wxNO_BORDER );
	gbSizer1->Add( sun13, wxGBPosition( 28, 14 ), wxGBSpan( 1, 1 ), wxEXPAND|wxLEFT|wxRIGHT, 5 );


	gbSizer1->AddGrowableCol( 2 );
	gbSizer1->AddGrowableCol( 4 );
	gbSizer1->AddGrowableCol( 6 );
	gbSizer1->AddGrowableCol( 8 );
	gbSizer1->AddGrowableCol( 10 );
	gbSizer1->AddGrowableCol( 12 );
	gbSizer1->AddGrowableCol( 14 );
	gbSizer1->AddGrowableRow( 0 );
	gbSizer1->AddGrowableRow( 1 );
	gbSizer1->AddGrowableRow( 2 );
	gbSizer1->AddGrowableRow( 3 );
	gbSizer1->AddGrowableRow( 4 );
	gbSizer1->AddGrowableRow( 5 );
	gbSizer1->AddGrowableRow( 6 );
	gbSizer1->AddGrowableRow( 7 );
	gbSizer1->AddGrowableRow( 8 );
	gbSizer1->AddGrowableRow( 9 );
	gbSizer1->AddGrowableRow( 10 );
	gbSizer1->AddGrowableRow( 11 );
	gbSizer1->AddGrowableRow( 12 );
	gbSizer1->AddGrowableRow( 13 );
	gbSizer1->AddGrowableRow( 14 );
	gbSizer1->AddGrowableRow( 15 );
	gbSizer1->AddGrowableRow( 16 );
	gbSizer1->AddGrowableRow( 17 );
	gbSizer1->AddGrowableRow( 18 );
	gbSizer1->AddGrowableRow( 19 );
	gbSizer1->AddGrowableRow( 20 );
	gbSizer1->AddGrowableRow( 21 );
	gbSizer1->AddGrowableRow( 22 );
	gbSizer1->AddGrowableRow( 23 );
	gbSizer1->AddGrowableRow( 24 );
	gbSizer1->AddGrowableRow( 25 );
	gbSizer1->AddGrowableRow( 26 );
	gbSizer1->AddGrowableRow( 27 );
	gbSizer1->AddGrowableRow( 28 );
	gbSizer1->AddGrowableRow( 29 );
	gbSizer1->AddGrowableRow( 30 );
	gbSizer1->AddGrowableRow( 31 );
	gbSizer1->AddGrowableRow( 32 );
	gbSizer1->AddGrowableRow( 33 );
	gbSizer1->AddGrowableRow( 34 );
	gbSizer1->AddGrowableRow( 35 );
	gbSizer1->AddGrowableRow( 36 );
	gbSizer1->AddGrowableRow( 37 );
	gbSizer1->AddGrowableRow( 38 );
	gbSizer1->AddGrowableRow( 39 );
	gbSizer1->AddGrowableRow( 40 );
	gbSizer1->AddGrowableRow( 41 );
	gbSizer1->AddGrowableRow( 42 );
	gbSizer1->AddGrowableRow( 43 );
	gbSizer1->AddGrowableRow( 44 );
	gbSizer1->AddGrowableRow( 45 );
	gbSizer1->AddGrowableRow( 46 );
	gbSizer1->AddGrowableRow( 47 );
	gbSizer1->AddGrowableRow( 48 );

	m_scrolledWindow3->SetSizer( gbSizer1 );
	m_scrolledWindow3->Layout();
	gbSizer1->Fit( m_scrolledWindow3 );
	gbSizer41->Add( m_scrolledWindow3, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );


	gbSizer41->AddGrowableCol( 0 );
	gbSizer41->AddGrowableRow( 1 );

	m_panel41->SetSizer( gbSizer41 );
	m_panel41->Layout();
	gbSizer41->Fit( m_panel41 );
	m_splitter3->SplitVertically( m_panel5, m_panel41, 195 );
	gbSizer3->Add( m_splitter3, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );


	gbSizer3->AddGrowableCol( 0 );
	gbSizer3->AddGrowableRow( 0 );

	this->SetSizer( gbSizer3 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( MainFrame::OnActivate ) );
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnClose ) );
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::refreshButton ), NULL, this );
	datePicker->Connect( wxEVT_CALENDAR_DAY_CHANGED, wxCalendarEventHandler( MainFrame::onDateSelect ), NULL, this );
	datePicker->Connect( wxEVT_CALENDAR_SEL_CHANGED, wxCalendarEventHandler( MainFrame::onDateSelect ), NULL, this );
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::addCalendarButton ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::addCalendarURLButton ), NULL, this );
	calendarList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainFrame::onCalendarSelect ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::deleteCalendarButton ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::addEventButton ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::scheduleEventButton ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::deleteEventButton ), NULL, this );
	notificationButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::viewNotificationsButton ), NULL, this );
	LogoutButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::logoutButton ), NULL, this );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( MainFrame::OnActivate ) );
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MainFrame::OnClose ) );
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::refreshButton ), NULL, this );
	datePicker->Disconnect( wxEVT_CALENDAR_DAY_CHANGED, wxCalendarEventHandler( MainFrame::onDateSelect ), NULL, this );
	datePicker->Disconnect( wxEVT_CALENDAR_SEL_CHANGED, wxCalendarEventHandler( MainFrame::onDateSelect ), NULL, this );
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::addCalendarButton ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::addCalendarURLButton ), NULL, this );
	calendarList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainFrame::onCalendarSelect ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::deleteCalendarButton ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::addEventButton ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::scheduleEventButton ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::deleteEventButton ), NULL, this );
	notificationButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::viewNotificationsButton ), NULL, this );
	LogoutButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrame::logoutButton ), NULL, this );

}

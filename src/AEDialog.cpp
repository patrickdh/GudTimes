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

#include "AEDialog.h"

///////////////////////////////////////////////////////////////////////////

AEDialog::AEDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 480,443 ), wxDefaultSize );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Add Event"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 18, 74, 90, 90, false, wxT("Arial") ) );

	bSizer3->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridBagSizer* gbSizer1;
	gbSizer1 = new wxGridBagSizer( 1, 1 );
	gbSizer1->SetFlexibleDirection( wxBOTH );
	gbSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );

	m_staticText3 = new wxStaticText( m_panel2, wxID_ANY, wxT("Title"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	gbSizer1->Add( m_staticText3, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	eventTitle = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gbSizer1->Add( eventTitle, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	m_staticText4 = new wxStaticText( m_panel2, wxID_ANY, wxT("Date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	gbSizer1->Add( m_staticText4, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	DatePicker = new wxDatePickerCtrl( m_panel2, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	gbSizer1->Add( DatePicker, wxGBPosition( 3, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	m_staticText5 = new wxStaticText( m_panel2, wxID_ANY, wxT("Start Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gbSizer1->Add( m_staticText5, wxGBPosition( 4, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	wxString eventStartChoices[] = { wxT("00:00"), wxT("00:30"), wxT("01:00"), wxT("01:30"), wxT("02:00"), wxT("02:30"), wxT("03:00"), wxT("03:30"), wxT("04:00"), wxT("04:30"), wxT("05:00"), wxT("05:30"), wxT("06:00"), wxT("06:30"), wxT("07:00"), wxT("07:30"), wxT("08:00"), wxT("08:30"), wxT("09:00"), wxT("09:30"), wxT("10:00"), wxT("10:30"), wxT("11:00"), wxT("11:30"), wxT("12:00"), wxT("12:30"), wxT("13:00"), wxT("13:30"), wxT("14:00"), wxT("14:30"), wxT("15:00"), wxT("15:30"), wxT("16:00"), wxT("16:30"), wxT("17:00"), wxT("17:30"), wxT("18:00"), wxT("18:30"), wxT("19:00"), wxT("19:30"), wxT("20:00"), wxT("20:30"), wxT("21:00"), wxT("21:30"), wxT("22:00"), wxT("22:30"), wxT("23:00"), wxT("23:30"), wxEmptyString };
	int eventStartNChoices = sizeof( eventStartChoices ) / sizeof( wxString );
	eventStart = new wxChoice( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, eventStartNChoices, eventStartChoices, 0 );
	eventStart->SetSelection( 0 );
	gbSizer1->Add( eventStart, wxGBPosition( 5, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	m_staticText6 = new wxStaticText( m_panel2, wxID_ANY, wxT("End Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	gbSizer1->Add( m_staticText6, wxGBPosition( 6, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	wxString eventEndChoices[] = { wxT("00:00"), wxT("00:30"), wxT("01:00"), wxT("01:30"), wxT("02:00"), wxT("02:30"), wxT("03:00"), wxT("03:30"), wxT("04:00"), wxT("04:30"), wxT("05:00"), wxT("05:30"), wxT("06:00"), wxT("06:30"), wxT("07:00"), wxT("07:30"), wxT("08:00"), wxT("08:30"), wxT("09:00"), wxT("09:30"), wxT("10:00"), wxT("10:30"), wxT("11:00"), wxT("11:30"), wxT("12:00"), wxT("12:30"), wxT("13:00"), wxT("13:30"), wxT("14:00"), wxT("14:30"), wxT("15:00"), wxT("15:30"), wxT("16:00"), wxT("16:30"), wxT("17:00"), wxT("17:30"), wxT("18:00"), wxT("18:30"), wxT("19:00"), wxT("19:30"), wxT("20:00"), wxT("20:30"), wxT("21:00"), wxT("21:30"), wxT("22:00"), wxT("22:30"), wxT("23:00"), wxT("23:30"), wxEmptyString };
	int eventEndNChoices = sizeof( eventEndChoices ) / sizeof( wxString );
	eventEnd = new wxChoice( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, eventEndNChoices, eventEndChoices, 0 );
	eventEnd->SetSelection( 0 );
	gbSizer1->Add( eventEnd, wxGBPosition( 7, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	m_staticText7 = new wxStaticText( m_panel2, wxID_ANY, wxT("Frequency"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	gbSizer1->Add( m_staticText7, wxGBPosition( 8, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	wxString eventFrequencyChoices[] = { wxT("NONE"), wxT("DAILY"), wxT("WEEKLY"), wxT("MONTHLY"), wxT("ANUALLY"), wxEmptyString };
	int eventFrequencyNChoices = sizeof( eventFrequencyChoices ) / sizeof( wxString );
	eventFrequency = new wxChoice( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, eventFrequencyNChoices, eventFrequencyChoices, 0 );
	eventFrequency->SetSelection( 0 );
	gbSizer1->Add( eventFrequency, wxGBPosition( 9, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	Repeat = new wxSpinCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0 );
	gbSizer1->Add( Repeat, wxGBPosition( 9, 1 ), wxGBSpan( 1, 1 ), wxALL, 5 );

	m_sdbSizer1 = new wxStdDialogButtonSizer();
	m_sdbSizer1OK = new wxButton( m_panel2, wxID_OK );
	m_sdbSizer1->AddButton( m_sdbSizer1OK );
	m_sdbSizer1Cancel = new wxButton( m_panel2, wxID_CANCEL );
	m_sdbSizer1->AddButton( m_sdbSizer1Cancel );
	m_sdbSizer1->Realize();

	gbSizer1->Add( m_sdbSizer1, wxGBPosition( 10, 2 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );


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

	m_panel2->SetSizer( gbSizer1 );
	m_panel2->Layout();
	gbSizer1->Fit( m_panel2 );
	bSizer3->Add( m_panel2, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 10 );


	this->SetSizer( bSizer3 );
	this->Layout();

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AEDialog::OnClose ) );
	m_sdbSizer1Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AEDialog::onCancel ), NULL, this );
	m_sdbSizer1OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AEDialog::onOK ), NULL, this );
}

AEDialog::~AEDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AEDialog::OnClose ) );
	m_sdbSizer1Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AEDialog::onCancel ), NULL, this );
	m_sdbSizer1OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AEDialog::onOK ), NULL, this );

}

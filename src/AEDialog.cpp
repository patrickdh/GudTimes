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
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmap2 = new wxStaticBitmap( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_bitmap2, 0, wxRIGHT, 10 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Add Event"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 18, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer3->Add( m_staticText2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	
	bSizer31->Add( bSizer3, 1, wxALIGN_CENTER, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Title"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer31->Add( m_staticText3, 0, wxALL, 5 );
	
	eventTitle = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	eventTitle->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );
	
	bSizer31->Add( eventTitle, 0, wxALL, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Date"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	m_staticText4->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer31->Add( m_staticText4, 0, wxALL, 5 );
	
	DatePicker = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	bSizer31->Add( DatePicker, 0, wxALL, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Start Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer31->Add( m_staticText5, 0, wxALL, 5 );
	
	wxString eventStartChoices[] = { wxT("00:00"), wxT("00:30"), wxT("01:00"), wxT("01:30"), wxT("02:00"), wxT("02:30"), wxT("03:00"), wxT("03:30"), wxT("04:00"), wxT("04:30"), wxT("05:00"), wxT("05:30"), wxT("06:00"), wxT("06:30"), wxT("07:00"), wxT("07:30"), wxT("08:00"), wxT("08:30"), wxT("09:00"), wxT("09:30"), wxT("10:00"), wxT("10:30"), wxT("11:00"), wxT("11:30"), wxT("12:00"), wxT("12:30"), wxT("13:00"), wxT("13:30"), wxT("14:00"), wxT("14:30"), wxT("15:00"), wxT("15:30"), wxT("16:00"), wxT("16:30"), wxT("17:00"), wxT("17:30"), wxT("18:00"), wxT("18:30"), wxT("19:00"), wxT("19:30"), wxT("20:00"), wxT("20:30"), wxT("21:00"), wxT("21:30"), wxT("22:00"), wxT("22:30"), wxT("23:00"), wxT("23:30"), wxEmptyString };
	int eventStartNChoices = sizeof( eventStartChoices ) / sizeof( wxString );
	eventStart = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, eventStartNChoices, eventStartChoices, 0 );
	eventStart->SetSelection( 0 );
	eventStart->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );
	
	bSizer31->Add( eventStart, 0, wxALL, 5 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("End Time"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	m_staticText6->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer31->Add( m_staticText6, 0, wxALL, 5 );
	
	wxString eventEndChoices[] = { wxT("00:00"), wxT("00:30"), wxT("01:00"), wxT("01:30"), wxT("02:00"), wxT("02:30"), wxT("03:00"), wxT("03:30"), wxT("04:00"), wxT("04:30"), wxT("05:00"), wxT("05:30"), wxT("06:00"), wxT("06:30"), wxT("07:00"), wxT("07:30"), wxT("08:00"), wxT("08:30"), wxT("09:00"), wxT("09:30"), wxT("10:00"), wxT("10:30"), wxT("11:00"), wxT("11:30"), wxT("12:00"), wxT("12:30"), wxT("13:00"), wxT("13:30"), wxT("14:00"), wxT("14:30"), wxT("15:00"), wxT("15:30"), wxT("16:00"), wxT("16:30"), wxT("17:00"), wxT("17:30"), wxT("18:00"), wxT("18:30"), wxT("19:00"), wxT("19:30"), wxT("20:00"), wxT("20:30"), wxT("21:00"), wxT("21:30"), wxT("22:00"), wxT("22:30"), wxT("23:00"), wxT("23:30"), wxEmptyString };
	int eventEndNChoices = sizeof( eventEndChoices ) / sizeof( wxString );
	eventEnd = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, eventEndNChoices, eventEndChoices, 0 );
	eventEnd->SetSelection( 0 );
	eventEnd->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );
	
	bSizer31->Add( eventEnd, 0, wxALL, 5 );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Frequency"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	m_staticText7->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer31->Add( m_staticText7, 0, wxALL, 5 );
	
	wxString eventFrequencyChoices[] = { wxT("None"), wxT("Daily"), wxT("Weekly"), wxT("Monthly"), wxT("Yearly") };
	int eventFrequencyNChoices = sizeof( eventFrequencyChoices ) / sizeof( wxString );
	eventFrequency = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, eventFrequencyNChoices, eventFrequencyChoices, 0 );
	eventFrequency->SetSelection( 0 );
	eventFrequency->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );
	
	bSizer31->Add( eventFrequency, 0, wxALL, 5 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Number of recurrences"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	m_staticText12->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer31->Add( m_staticText12, 0, wxALL, 5 );
	
	Repeat = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0 );
	Repeat->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );
	
	bSizer31->Add( Repeat, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button1 = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button1->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer2->Add( m_button1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_button2 = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button2->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer2->Add( m_button2, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer31->Add( bSizer2, 1, wxALIGN_CENTER, 5 );
	
	
	this->SetSizer( bSizer31 );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AEDialog::OnClose ) );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AEDialog::onOK ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AEDialog::onCancel ), NULL, this );
}

AEDialog::~AEDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( AEDialog::OnClose ) );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AEDialog::onOK ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AEDialog::onCancel ), NULL, this );
	
}

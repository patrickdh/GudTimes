///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "SEDialog.h"

///////////////////////////////////////////////////////////////////////////

SEDialog::SEDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetIcon(wxICON(aaaaa_logo));

	wxBoxSizer* bSizerMain;
	bSizerMain = new wxBoxSizer( wxVERTICAL );

	panelMain = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerComponents;
	bSizerComponents = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer2;
	fgSizer2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer2->SetFlexibleDirection( wxBOTH );
	fgSizer2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	wxFlexGridSizer* fgSizerEventDescription;
	fgSizerEventDescription = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizerEventDescription->SetFlexibleDirection( wxBOTH );
	fgSizerEventDescription->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	labelUsers = new wxStaticText( panelMain, wxID_ANY, wxT("Users to invite (comma separated): "), wxDefaultPosition, wxDefaultSize, 0 );
	labelUsers->Wrap( -1 );
	labelUsers->SetFont(wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ));

	fgSizerEventDescription->Add( labelUsers, 0, wxALL, 5 );

	textboxUsers = new wxTextCtrl( panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerEventDescription->Add( textboxUsers, 0, wxALL, 5 );
	textboxUsers->SetFont(wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ));

	labelEventName = new wxStaticText( panelMain, wxID_ANY, wxT("Name/Description of Event: "), wxDefaultPosition, wxDefaultSize, 0 );
	labelEventName->Wrap( -1 );
	labelEventName->SetFont(wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ));
	fgSizerEventDescription->Add( labelEventName, 0, wxALL, 5 );

	textboxEventName = new wxTextCtrl( panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerEventDescription->Add( textboxEventName, 0, wxALL, 5 );
	textboxEventName->SetFont(wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ));

	labelEventDuration = new wxStaticText( panelMain, wxID_ANY, wxT("Duration of Event (minutes): "), wxDefaultPosition, wxDefaultSize, 0 );
	labelEventDuration->Wrap( -1 );
	labelEventDuration->SetFont(wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ));
	fgSizerEventDescription->Add( labelEventDuration, 0, wxALL, 5 );

	textboxDuration = new wxTextCtrl( panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	textboxDuration->SetFont(wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ));

	fgSizerEventDescription->Add( textboxDuration, 0, wxALL, 5 );


	fgSizer2->Add( fgSizerEventDescription, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizerDate;
	bSizerDate = new wxBoxSizer( wxHORIZONTAL );

	calendarSelect = new wxCalendarCtrl( panelMain, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_SHOW_HOLIDAYS );
	calendarSelect->SetFont(wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ));
	bSizerDate->Add( calendarSelect, 0, wxALL, 5 );


	fgSizer2->Add( bSizerDate, 1, wxEXPAND, 5 );


	bSizerComponents->Add( fgSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizerEventList;
	bSizerEventList = new wxBoxSizer( wxVERTICAL );

	eventChoiceList = new wxListBox( panelMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizerEventList->Add( eventChoiceList, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	eventChoiceList->SetFont(wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ));

    m_staticline42 = new wxStaticLine( panelMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizerComponents->Add( m_staticline42, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	choiceList = new wxStaticText( panelMain, wxID_ANY, wxT("Available times: "), wxDefaultPosition, wxDefaultSize, 0 );
	choiceList->Wrap( -1 );
	choiceList->SetFont(wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ));
	bSizerComponents->Add( choiceList, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizerComponents->Add( bSizerEventList, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizerButtons;
	bSizerButtons = new wxBoxSizer( wxHORIZONTAL );

	buttonFind = new wxButton( panelMain, wxID_ANY, wxT("&Find Available Times"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonFind->SetFont(wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ));
	bSizerButtons->Add( buttonFind, 0, wxALL, 5 );

	buttonExit = new wxButton( panelMain, wxID_ANY, wxT("&Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonExit->SetFont(wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ));
	bSizerButtons->Add( buttonExit, 0, wxALL, 5 );

	buttonCreate = new wxButton( panelMain, wxID_ANY, wxT("&Schedule and Invite"), wxDefaultPosition, wxDefaultSize, 0 );
	buttonCreate->SetFont(wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ));
	bSizerButtons->Add( buttonCreate, 0, wxALL, 5 );


	bSizerComponents->Add( bSizerButtons, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	panelMain->SetSizer( bSizerComponents );
	panelMain->Layout();
	bSizerComponents->Fit( panelMain );
	bSizerMain->Add( panelMain, 1, wxEXPAND, 5 );


	this->SetSizer( bSizerMain );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	textboxUsers->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SEDialog::OnFindTimes ), NULL, this );
	textboxEventName->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SEDialog::OnFormChange ), NULL, this );
	textboxEventName->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SEDialog::OnFindTimes ), NULL, this );
	textboxDuration->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SEDialog::OnFormChange ), NULL, this );
	textboxDuration->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SEDialog::OnFindTimes ), NULL, this );
	calendarSelect->Connect( wxEVT_CALENDAR_DAY_CHANGED, wxCalendarEventHandler( SEDialog::OnFormChange ), NULL, this );
	calendarSelect->Connect( wxEVT_CALENDAR_SEL_CHANGED, wxCalendarEventHandler( SEDialog::OnFormChange ), NULL, this );
	buttonFind->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SEDialog::OnFindTimes ), NULL, this );
	buttonExit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SEDialog::OnExit ), NULL, this );
	buttonCreate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SEDialog::OnCreate ), NULL, this );
}

SEDialog::~SEDialog()
{
	// Disconnect Events
	textboxUsers->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SEDialog::OnFindTimes ), NULL, this );
	textboxEventName->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SEDialog::OnFormChange ), NULL, this );
	textboxEventName->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SEDialog::OnFindTimes ), NULL, this );
	textboxDuration->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SEDialog::OnFormChange ), NULL, this );
	textboxDuration->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SEDialog::OnFindTimes ), NULL, this );
	calendarSelect->Disconnect( wxEVT_CALENDAR_DAY_CHANGED, wxCalendarEventHandler( SEDialog::OnFormChange ), NULL, this );
	calendarSelect->Disconnect( wxEVT_CALENDAR_SEL_CHANGED, wxCalendarEventHandler( SEDialog::OnFormChange ), NULL, this );
	buttonFind->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SEDialog::OnFindTimes ), NULL, this );
	buttonExit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SEDialog::OnExit ), NULL, this );
	buttonCreate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SEDialog::OnCreate ), NULL, this );

}

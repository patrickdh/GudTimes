///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "scheduleGui.h"

///////////////////////////////////////////////////////////////////////////

SEDialog::SEDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

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
	fgSizerEventDescription->Add( labelUsers, 0, wxALL, 5 );

	textboxUsers = new wxTextCtrl( panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerEventDescription->Add( textboxUsers, 0, wxALL, 5 );

	labelEventName = new wxStaticText( panelMain, wxID_ANY, wxT("Name/Description of Event: "), wxDefaultPosition, wxDefaultSize, 0 );
	labelEventName->Wrap( -1 );
	fgSizerEventDescription->Add( labelEventName, 0, wxALL, 5 );

	textboxEventName = new wxTextCtrl( panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizerEventDescription->Add( textboxEventName, 0, wxALL, 5 );

	labelEventDuration = new wxStaticText( panelMain, wxID_ANY, wxT("Duration of Event (minutes): "), wxDefaultPosition, wxDefaultSize, 0 );
	labelEventDuration->Wrap( -1 );
	fgSizerEventDescription->Add( labelEventDuration, 0, wxALL, 5 );

	textboxDuration = new wxTextCtrl( panelMain, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );

	fgSizerEventDescription->Add( textboxDuration, 0, wxALL, 5 );


	fgSizer2->Add( fgSizerEventDescription, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizerDate;
	bSizerDate = new wxBoxSizer( wxHORIZONTAL );

	calendarSelect = new wxCalendarCtrl( panelMain, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_SHOW_HOLIDAYS );
	bSizerDate->Add( calendarSelect, 0, wxALL, 5 );


	fgSizer2->Add( bSizerDate, 1, wxEXPAND, 5 );


	bSizerComponents->Add( fgSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizerEventList;
	bSizerEventList = new wxBoxSizer( wxVERTICAL );

	eventChoiceList = new wxListBox( panelMain, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	eventChoiceList->Append( wxT("08:00:00-13:00:00") );
	bSizerEventList->Add( eventChoiceList, 1, wxALL|wxEXPAND, 5 );


	bSizerComponents->Add( bSizerEventList, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizerButtons;
	bSizerButtons = new wxBoxSizer( wxHORIZONTAL );

	buttonFind = new wxButton( panelMain, wxID_ANY, wxT("&Find"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( buttonFind, 0, wxALL, 5 );

	buttonExit = new wxButton( panelMain, wxID_ANY, wxT("&Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizerButtons->Add( buttonExit, 0, wxALL, 5 );

	buttonCreate = new wxButton( panelMain, wxID_ANY, wxT("&Create"), wxDefaultPosition, wxDefaultSize, 0 );
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
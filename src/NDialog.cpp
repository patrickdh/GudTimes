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

#include "NDialog.h"

///////////////////////////////////////////////////////////////////////////

NDialog::NDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Notifications"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer1->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	notificationsListBox = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	notificationsListBox->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer1->Add( notificationsListBox, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	acceptButton = new wxButton( this, wxID_ANY, wxT("Accept"), wxDefaultPosition, wxDefaultSize, 0 );
	acceptButton->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	acceptButton->Enable( false );
	
	bSizer2->Add( acceptButton, 0, wxALL, 5 );
	
	dismissButton = new wxButton( this, wxID_ANY, wxT("Dismiss"), wxDefaultPosition, wxDefaultSize, 0 );
	dismissButton->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	dismissButton->Enable( false );
	
	bSizer2->Add( dismissButton, 0, wxALL, 5 );
	
	rejectButton = new wxButton( this, wxID_ANY, wxT("Reject"), wxDefaultPosition, wxDefaultSize, 0 );
	rejectButton->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	rejectButton->Enable( false );
	
	bSizer2->Add( rejectButton, 0, wxALL, 5 );
	
	
	bSizer3->Add( bSizer2, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	okayButton = new wxButton( this, wxID_ANY, wxT("Okay"), wxDefaultPosition, wxDefaultSize, 0 );
	okayButton->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer4->Add( okayButton, 0, wxALL, 5 );
	
	cancelButton = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	cancelButton->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer4->Add( cancelButton, 0, wxALL, 5 );
	
	
	bSizer3->Add( bSizer4, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	notificationsListBox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( NDialog::OnSelection ), NULL, this );
	acceptButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NDialog::onAcceptButton ), NULL, this );
	dismissButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NDialog::onDismissButton ), NULL, this );
	rejectButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NDialog::onDeclineButton ), NULL, this );
	okayButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NDialog::onOK ), NULL, this );
	cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NDialog::onCancel ), NULL, this );
}

NDialog::~NDialog()
{
	// Disconnect Events
	notificationsListBox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( NDialog::OnSelection ), NULL, this );
	acceptButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NDialog::onAcceptButton ), NULL, this );
	dismissButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NDialog::onDismissButton ), NULL, this );
	rejectButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NDialog::onDeclineButton ), NULL, this );
	okayButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NDialog::onOK ), NULL, this );
	cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NDialog::onCancel ), NULL, this );
	
}

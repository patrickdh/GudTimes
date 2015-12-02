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

#include "DEDialog.h"

///////////////////////////////////////////////////////////////////////////

DEDialog::DEDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* DEBox;
	DEBox = new wxBoxSizer( wxVERTICAL );
	
	deleteEventListBox = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_NEEDED_SB ); 
	deleteEventListBox->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	DEBox->Add( deleteEventListBox, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Please choose a calendar event to delete"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );
	
	bSizer5->Add( m_staticText1, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );
	
	deleteButton = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	deleteButton->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer41->Add( deleteButton, 0, wxALL, 5 );
	
	cancelButton = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	cancelButton->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );
	
	bSizer41->Add( cancelButton, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer41, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	DEBox->Add( bSizer4, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( DEBox );
	this->Layout();
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DEDialog::OnClose ) );
	deleteEventListBox->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( DEDialog::onSelection ), NULL, this );
	deleteButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DEDialog::onOK ), NULL, this );
	cancelButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DEDialog::onCancel ), NULL, this );
}

DEDialog::~DEDialog()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( DEDialog::OnClose ) );
	deleteEventListBox->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( DEDialog::onSelection ), NULL, this );
	deleteButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DEDialog::onOK ), NULL, this );
	cancelButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DEDialog::onCancel ), NULL, this );
	
}

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

#include "LoginFrame.h"

///////////////////////////////////////////////////////////////////////////

LoginFrame::LoginFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_staticText3 = new wxStaticText( m_panel1, wxID_ANY, wxT("Welcome to GudTimes. Please login below."), wxDefaultPosition, wxDefaultSize, 0|wxSIMPLE_BORDER );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( 16, 74, 90, 92, false, wxT("Century Gothic") ) );

	bSizer2->Add( m_staticText3, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText1 = new wxStaticText( m_panel1, wxID_ANY, wxT("Username:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	bSizer2->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );

	usernameText = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( usernameText, 0, wxALIGN_CENTER|wxALL, 5 );
	usernameText->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );

	m_staticText2 = new wxStaticText( m_panel1, wxID_ANY, wxT("Password:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Century Gothic") ) );

	bSizer2->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 5 );

	passwordText = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	bSizer2->Add( passwordText, 0, wxALIGN_CENTER|wxALL, 5 );
    passwordText->SetFont( wxFont( 9, 74, 90, 90, false, wxT("Century Gothic") ) );


	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );


	bSizer6->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button1 = new wxButton( m_panel1, wxID_ANY, wxT("Login"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button1->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Arial") ) );

	bSizer6->Add( m_button1, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer6->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button5 = new wxButton( m_panel1, wxID_ANY, wxT("Create Account"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button5->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Arial") ) );

	bSizer6->Add( m_button5, 0, wxALL, 5 );


	bSizer6->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer6, 1, wxEXPAND, 5 );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );


	m_panel1->SetSizer( bSizer2 );
	m_panel1->Layout();
	bSizer2->Fit( m_panel1 );
	bSizer1->Add( m_panel1, 1, wxEXPAND | wxALL, 0 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( LoginFrame::OnClose ) );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginFrame::loginButton ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginFrame::createAccountButton ), NULL, this );
}

LoginFrame::~LoginFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( LoginFrame::OnClose ) );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginFrame::loginButton ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginFrame::createAccountButton ), NULL, this );

}

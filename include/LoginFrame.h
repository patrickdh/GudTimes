///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __LOGINFRAME_H__
#define __LOGINFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/statline.h>
#include <wx/calctrl.h>
#include <wx/listbox.h>
#include <wx/gbsizer.h>
#include <wx/scrolwin.h>
#include <wx/splitter.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class LoginFrame
///////////////////////////////////////////////////////////////////////////////
class LoginFrame : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel1;
		wxStaticText* m_staticText3;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrl1;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrl2;
		wxButton* m_button1;
		wxButton* m_button5;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void loginButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void createAccountButton( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		LoginFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GudTimes - Login"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~LoginFrame();
	
};

#endif //__LOGINFRAME_H__

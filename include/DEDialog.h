///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __DEDIALOG_H__
#define __DEDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class DEDialog
///////////////////////////////////////////////////////////////////////////////
class DEDialog : public wxDialog 
{
	private:
	
	protected:
		wxListBox* deleteEventListBox;
		wxStaticText* m_staticText1;
		wxButton* deleteButton;
		wxButton* cancelButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		DEDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Delete Event"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 407,327 ), long style = 0 ); 
		~DEDialog();
	
};

#endif //__DEDIALOG_H__

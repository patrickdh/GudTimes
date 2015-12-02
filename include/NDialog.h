///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NDIALOG_H__
#define __NDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class NDialog
///////////////////////////////////////////////////////////////////////////////
class NDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxListBox* notificationsListBox;
		wxButton* acceptButton;
		wxButton* dismissButton;
		wxButton* rejectButton;
		wxButton* okayButton;
		wxButton* cancelButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void onAcceptButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void onDismissButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void onDeclineButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		NDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Notifications"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 399,326 ), long style = 0 ); 
		~NDialog();
	
};

#endif //__NDIALOG_H__

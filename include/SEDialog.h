///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __SCHEDULEGUI_H__
#define __SCHEDULEGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/calctrl.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/dialog.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class SEDialog
///////////////////////////////////////////////////////////////////////////////
class SEDialog : public wxDialog 
{
	private:
	
	protected:
		wxPanel* panelMain;
		wxStaticText* labelUsers;
		wxTextCtrl* textboxUsers;
		wxStaticText* labelEventName;
		wxTextCtrl* textboxEventName;
		wxStaticText* labelEventDuration;
		wxTextCtrl* textboxDuration;
		wxCalendarCtrl* calendarSelect;
		wxListBox* eventChoiceList;
		wxButton* buttonFind;
		wxButton* buttonExit;
		wxButton* buttonCreate;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFindTimes( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnFormChange( wxCalendarEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCreate( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxString wxUsers; 
		wxString wxEventName; 
		int eventDuration; 
		
		SEDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Schedule Event"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 644,495 ), long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP ); 
		~SEDialog();
	
};

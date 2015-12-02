///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __AEDIALOG_H__
#define __AEDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/choice.h>
#include <wx/spinctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class AEDialog
///////////////////////////////////////////////////////////////////////////////
class AEDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap2;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxTextCtrl* eventTitle;
		wxStaticText* m_staticText4;
		wxDatePickerCtrl* DatePicker;
		wxStaticText* m_staticText5;
		wxChoice* eventStart;
		wxStaticText* m_staticText6;
		wxChoice* eventEnd;
		wxStaticText* m_staticText7;
		wxChoice* eventFrequency;
		wxStaticText* m_staticText12;
		wxSpinCtrl* Repeat;
		wxButton* m_button1;
		wxButton* m_button2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		AEDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add Event"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 480,467 ), long style = 0 ); 
		~AEDialog();
	
};

#endif //__AEDIALOG_H__

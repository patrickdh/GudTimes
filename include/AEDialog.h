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
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/choice.h>
#include <wx/spinctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/gbsizer.h>
#include <wx/panel.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class AEDialog
///////////////////////////////////////////////////////////////////////////////
class AEDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxPanel* m_panel2;
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
		wxSpinCtrl* Repeat;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void onCancel( wxCommandEvent& event ) { event.Skip(); }
		virtual void onOK( wxCommandEvent& event ) { event.Skip(); }


	public:

		AEDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add Event"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 480,443 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER );
		~AEDialog();

};

#endif //__AEDIALOG_H__

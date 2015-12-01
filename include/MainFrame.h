///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

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
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxSplitterWindow* m_splitter3;
		wxPanel* m_panel5;
		wxStaticText* m_staticText451;
		wxStaticLine* m_staticline42;
		wxButton* m_button11;
		wxCalendarCtrl* m_calendar3;
		wxButton* m_button10;
		wxButton* m_button2;
		wxStaticText* m_staticText46;
		wxListBox* calendarList;
		wxButton* m_button12;
		wxButton* m_button6;
		wxButton* m_button7;
		wxButton* m_button8;
		wxButton* notificationButton;
		wxPanel* m_panel41;
		wxPanel* m_panel4;
		wxStaticLine* m_staticline267;
		wxStaticText* m_staticText57;
		wxStaticLine* m_staticline268;
		wxStaticText* m_staticText58;
		wxStaticLine* m_staticline269;
		wxStaticText* m_staticText59;
		wxStaticLine* m_staticline270;
		wxStaticText* m_staticText60;
		wxStaticLine* m_staticline27123;
		wxStaticText* m_staticText61;
		wxStaticLine* m_staticline2721;
		wxStaticText* m_staticText62;
		wxStaticLine* m_staticline273;
		wxStaticText* m_staticText63;
		wxStaticLine* m_staticline274;
		wxStaticText* m_staticText50;
		wxTextCtrl* m_textCtrl3391;
		wxTextCtrl* m_textCtrl3401;
		wxTextCtrl* m_textCtrl34110;
		wxTextCtrl* m_textCtrl3422;
		wxTextCtrl* m_textCtrl3431;
		wxTextCtrl* m_textCtrl3441;
		wxTextCtrl* m_textCtrl3451;
		wxStaticText* m_staticText52;
		wxScrolledWindow* m_scrolledWindow3;
		wxTextCtrl* mon00;
		wxStaticLine* m_staticline234;
		wxStaticLine* m_staticline235;
		wxStaticLine* m_staticline236;
		wxStaticLine* m_staticline237;
		wxStaticLine* m_staticline238;
		wxStaticLine* m_staticline239;
		wxStaticLine* m_staticline240;
		wxStaticLine* m_staticline241;
		wxStaticLine* m_staticline242;
		wxStaticLine* m_staticline243;
		wxStaticLine* m_staticline244;
		wxStaticLine* m_staticline245;
		wxStaticLine* m_staticline246;
		wxStaticLine* m_staticline247;
		wxStaticLine* m_staticline248;
		wxStaticLine* m_staticline249;
		wxStaticLine* m_staticline250;
		wxStaticLine* m_staticline251;
		wxStaticLine* m_staticline252;
		wxStaticLine* m_staticline253;
		wxStaticLine* m_staticline254;
		wxStaticLine* m_staticline255;
		wxStaticLine* m_staticline256;
		wxStaticLine* m_staticline257;
		wxTextCtrl* tues00;
		wxTextCtrl* wed00;
		wxTextCtrl* thurs00;
		wxTextCtrl* fri00;
		wxTextCtrl* sat00;
		wxTextCtrl* sun00;
		wxStaticLine* m_staticline7771;
		wxStaticLine* m_staticline224;
		wxStaticText* time00;
		wxStaticText* time01;
		wxStaticText* time02;
		wxStaticText* time03;
		wxStaticText* time04;
		wxStaticText* time05;
		wxStaticText* time06;
		wxStaticText* time07;
		wxStaticText* time08;
		wxStaticText* time09;
		wxStaticText* time10;
		wxStaticText* time11;
		wxStaticText* time12;
		wxStaticText* time13;
		wxStaticText* time14;
		wxStaticText* time15;
		wxStaticText* time16;
		wxStaticText* time17;
		wxStaticText* time18;
		wxStaticText* time19;
		wxStaticText* time20;
		wxStaticText* time21;
		wxStaticText* time22;
		wxStaticText* time23;
		wxStaticLine* m_staticline777;
		wxStaticLine* m_staticline776;
		wxStaticText* m_staticText64;
		wxStaticText* m_staticText49;
		wxStaticLine* m_staticline783;
		wxStaticLine* m_staticline781;
		wxStaticText* m_staticText65;
		wxStaticText* m_staticText66;
		wxStaticText* m_staticText25;
		wxStaticText* m_staticText26;
		wxStaticText* m_staticText27;
		wxStaticText* m_staticText29;
		wxTextCtrl* mon01;
		wxTextCtrl* mon02;
		wxTextCtrl* tues02;
		wxTextCtrl* wed02;
		wxTextCtrl* thurs02;
		wxTextCtrl* fri02;
		wxTextCtrl* sat02;
		wxTextCtrl* sun02;
		wxTextCtrl* tues01;
		wxTextCtrl* wed01;
		wxTextCtrl* thurs01;
		wxTextCtrl* fri01;
		wxTextCtrl* sat01;
		wxTextCtrl* sun01;
		wxStaticLine* m_staticline2241;
		wxStaticLine* m_staticline22411;
		wxStaticLine* m_staticline232;
		wxTextCtrl* mon03;
		wxTextCtrl* tues03;
		wxTextCtrl* wed03;
		wxTextCtrl* thurs03;
		wxTextCtrl* fri03;
		wxTextCtrl* sat03;
		wxTextCtrl* sun03;
		wxTextCtrl* mon04;
		wxTextCtrl* tues04;
		wxTextCtrl* wed04;
		wxTextCtrl* thurs04;
		wxTextCtrl* fri04;
		wxTextCtrl* sat04;
		wxTextCtrl* sun04;
		wxTextCtrl* mon05;
		wxTextCtrl* tues05;
		wxTextCtrl* wed05;
		wxTextCtrl* thurs05;
		wxTextCtrl* fri05;
		wxTextCtrl* sat05;
		wxTextCtrl* sun05;
		wxTextCtrl* mon06;
		wxTextCtrl* tues06;
		wxTextCtrl* wed06;
		wxTextCtrl* thurs06;
		wxTextCtrl* fri06;
		wxTextCtrl* sat06;
		wxTextCtrl* sun06;
		wxTextCtrl* mon07;
		wxTextCtrl* tues07;
		wxTextCtrl* wed07;
		wxTextCtrl* thurs07;
		wxTextCtrl* fri07;
		wxTextCtrl* sat07;
		wxTextCtrl* sun07;
		wxTextCtrl* mon08;
		wxTextCtrl* tues08;
		wxTextCtrl* wed08;
		wxTextCtrl* thurs08;
		wxTextCtrl* fri08;
		wxTextCtrl* sat08;
		wxTextCtrl* sun08;
		wxTextCtrl* mon09;
		wxTextCtrl* tues09;
		wxTextCtrl* wed09;
		wxTextCtrl* thurs09;
		wxTextCtrl* fri09;
		wxTextCtrl* sat09;
		wxTextCtrl* sun09;
		wxTextCtrl* mon10;
		wxTextCtrl* tues10;
		wxTextCtrl* wed10;
		wxTextCtrl* thurs10;
		wxTextCtrl* fri10;
		wxTextCtrl* sat10;
		wxTextCtrl* sun10;
		wxTextCtrl* mon11;
		wxTextCtrl* tues11;
		wxTextCtrl* wed11;
		wxTextCtrl* thurs11;
		wxTextCtrl* fri11;
		wxTextCtrl* sat11;
		wxTextCtrl* sun11;
		wxTextCtrl* mon12;
		wxTextCtrl* tues12;
		wxTextCtrl* wed12;
		wxTextCtrl* thurs12;
		wxTextCtrl* fri12;
		wxTextCtrl* sat12;
		wxTextCtrl* sun12;
		wxTextCtrl* mon13;
		wxTextCtrl* mon14;
		wxTextCtrl* mon15;
		wxTextCtrl* mon16;
		wxTextCtrl* tues16;
		wxTextCtrl* wed16;
		wxTextCtrl* thurs16;
		wxTextCtrl* fri16;
		wxTextCtrl* sat16;
		wxTextCtrl* sun16;
		wxTextCtrl* mon17;
		wxTextCtrl* tues17;
		wxTextCtrl* wed17;
		wxTextCtrl* thurs17;
		wxTextCtrl* fri17;
		wxTextCtrl* sat17;
		wxTextCtrl* sun17;
		wxTextCtrl* mon18;
		wxTextCtrl* tues18;
		wxTextCtrl* wed18;
		wxTextCtrl* thurs18;
		wxTextCtrl* fri18;
		wxTextCtrl* sat18;
		wxTextCtrl* sun18;
		wxTextCtrl* mon19;
		wxTextCtrl* tues19;
		wxTextCtrl* wed19;
		wxTextCtrl* thurs19;
		wxTextCtrl* fri19;
		wxTextCtrl* sat19;
		wxTextCtrl* sun19;
		wxTextCtrl* mon20;
		wxTextCtrl* tues20;
		wxTextCtrl* wed20;
		wxTextCtrl* thurs20;
		wxTextCtrl* fri20;
		wxTextCtrl* sat20;
		wxTextCtrl* sun20;
		wxTextCtrl* mon21;
		wxTextCtrl* tues21;
		wxTextCtrl* wed21;
		wxTextCtrl* thurs21;
		wxTextCtrl* fri21;
		wxTextCtrl* sat21;
		wxTextCtrl* sun21;
		wxTextCtrl* mon22;
		wxTextCtrl* tues22;
		wxTextCtrl* wed22;
		wxTextCtrl* thurs22;
		wxTextCtrl* fri22;
		wxTextCtrl* sat22;
		wxTextCtrl* sun22;
		wxTextCtrl* mon23;
		wxTextCtrl* tues23;
		wxTextCtrl* wed23;
		wxTextCtrl* thurs23;
		wxTextCtrl* fri23;
		wxTextCtrl* sat23;
		wxTextCtrl* sun23;
		wxTextCtrl* tues15;
		wxTextCtrl* wed15;
		wxTextCtrl* thurs15;
		wxTextCtrl* fri15;
		wxTextCtrl* sat15;
		wxTextCtrl* sun15;
		wxTextCtrl* tues14;
		wxTextCtrl* wed14;
		wxTextCtrl* thurs14;
		wxTextCtrl* fri14;
		wxTextCtrl* sat14;
		wxTextCtrl* sun14;
		wxTextCtrl* tues13;
		wxTextCtrl* wed13;
		wxTextCtrl* thurs13;
		wxTextCtrl* fri13;
		wxTextCtrl* sat13;
		wxTextCtrl* sun13;

		// Virtual event handlers, overide them in your derived class
		virtual void OnActivate( wxActivateEvent& event ) { event.Skip(); }
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void refreshButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void addCalendarButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void addCalendarURLButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void deleteCalendarButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void addEventButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void scheduleEventButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void deleteEventButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void viewNotificationsButton( wxCommandEvent& event ) { event.Skip(); }


	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GudTimes"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1170,730 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MainFrame();

		void m_splitter3OnIdle( wxIdleEvent& )
		{
			m_splitter3->SetSashPosition( 195 );
			m_splitter3->Disconnect( wxEVT_IDLE, wxIdleEventHandler( MainFrame::m_splitter3OnIdle ), NULL, this );
		}

};

#endif //__MAINFRAME_H__

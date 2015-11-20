// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

#include "MainGUI.h"

using namespace std;

MainGUI::MainGUI(wxWindow* parent, SSHConnection* sshconn, const std::string& user)
: MainFrame(parent)
{
    //ctor
}

void MainGUI::onClose(wxCloseEvent& event)
{

}

void MainGUI::refreshButton(wxCommandEvent& event)
{

}

void MainGUI::addEventButton(wxCommandEvent& event)
{

}

void MainGUI::scheduleEventButton(wxCommandEvent& event)
{

}

void MainGUI::deleteEventButton(wxCommandEvent& event)
{

}

void MainGUI::viewNotificationsButton(wxCommandEvent& event)
{

}

void MainGUI::addCalendarButton(wxCommandEvent& event)
{

}

void MainGUI::addCalendarURLButton(wxCommandEvent& event)
{

}

void MainGUI::deleteCalendarButton(wxCommandEvent& event)
{

}

void MainGUI::logoutButton(wxCommandEvent& event)
{

}

void MainGUI::onCalendarSelect(wxCommandEvent& event)
{

}

void MainGUI::onDateSelect(wxCommandEvent& event)
{

}

void MainGUI::fetchNotifications()
{

}

void MainGUI::updateNotificationsFlag()
{

}

void MainGUI::fetchCalendars()
{

}

void MainGUI::listCalendars()
{

}

void MainGUI::drawSchedule()
{

}

void MainGUI::clearLocalData()
{

}

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

#include "ScheduleEventDialog.h"

using namespace std;

ScheduleEventDialog::ScheduleEventDialog(wxWindow* parent, SSHConnection* sshconn, std::string user)
: SEDialog(parent)
{
    //ctor
}

Event ScheduleEventDialog::getEvent()
{

}

std::vector<std::string> ScheduleEventDialog::getUsers()
{

}

void ScheduleEventDialog::onChange(wxCommandEvent& event)
{

}

void ScheduleEventDialog::onFindTimes(wxCommandEvent& event)
{

}

void ScheduleEventDialog::onOK(wxCommandEvent& event)
{

}

void ScheduleEventDialog::onCancel(wxCommandEvent& event)
{

}

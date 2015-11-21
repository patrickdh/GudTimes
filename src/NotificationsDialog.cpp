// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

#include "NotificationsDialog.h"

using namespace std;

NotificationsDialog::NotificationsDialog(wxWindow* parent, const std::vector<Notification>& notices, const std::string& user)
: NDialog(parent)
{
    //ctor
}

std::vector<int> NotificationsDialog::getClearedNotifications() const
{

}

std::vector<Event> NotificationsDialog::getEvents() const
{

}

std::vector<std::pair<Notification,std::string>> NotificationsDialog::getOutgoingNotifications() const
{

}

void NotificationsDialog::onAcceptButton(wxCommandEvent& event)
{

}

void NotificationsDialog::onDeclineButton(wxCommandEvent& event)
{

}

void NotificationsDialog::onDismissButton(wxCommandEvent& event)
{

}

void NotificationsDialog::onSelection(wxCommandEvent& event)
{

}

void NotificationsDialog::onOK(wxCommandEvent& event)
{

}

void NotificationsDialog::onCancel(wxCommandEvent& event)
{

}

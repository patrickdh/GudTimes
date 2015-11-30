// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

#include "Notification.h"
#include "NotificationsDialog.h"
#include "Event.h"

using namespace std;

NotificationsDialog::NotificationsDialog(wxWindow* parent, const std::vector<Notification>& notices, const std::string& user)
: NDialog(parent)
{
    username = user;
    notificationData = notices;
    wxString a;
    for (unsigned int i =0 ; i < notices.size() ; ++i){
        if (notices[i].getType()==NotificationTypeEnum::NEWEVENT){
            a = notices[i].getFrom();
            a.Append(" sent you an invite to \"");
            a.Append(notices[i].getEvent().getTitle());
            a.Append("\" from ");
            Event evnt = notices[i].getEvent();
            a.Append(evnt.getStart().FormatISOTime());
            a.Append(" - ");
            a.Append(evnt.getEnd().FormatISOTime());
        }
        else if (notices[i].getType()==NotificationTypeEnum::ACCEPTEDEVENT){
            a = notices[i].getFrom();
            a.Append(" accepted your invitation to \"");
            a.Append(notices[i].getEvent().getTitle());
            a.Append("\".");
        }
        else {
            a = notices[i].getFrom();
            a.Append(" declined your invitation to \"");
            a.Append(notices[i].getEvent().getTitle());
            a.Append("\".");
        }
        notificationsListBox->Append(a);
    }
}

std::vector<int> NotificationsDialog::getClearedNotifications() const
{
    return clearedNotifications;
}

std::vector<Event> NotificationsDialog::getEvents() const
{
    return eventsToAdd;
}

std::vector<std::pair<Notification,std::string>> NotificationsDialog::getOutgoingNotifications() const
{
    return notificationsToSend;
}

void NotificationsDialog::onAcceptButton(wxCommandEvent& event)
{
    clearedNotifications.push_back(notificationsListBox->GetSelection());
    eventsToAdd.push_back(notificationData[notificationsListBox->GetSelection()].getEvent());
    Notification declineNotif(username,NotificationTypeEnum::ACCEPTEDEVENT,notificationData[notificationsListBox->GetSelection()].getEvent());
    notificationsToSend.push_back(std::pair<Notification,string>(declineNotif,"ACCEPT"));
    notificationData.erase(notificationData.begin() + notificationsListBox->GetSelection());
    acceptButton->Enable(false);
    dismissButton->Enable(false);
    rejectButton->Enable(false);
    notificationsListBox->Delete(notificationsListBox->GetSelection());
}

void NotificationsDialog::onDeclineButton(wxCommandEvent& event)
{
    clearedNotifications.push_back(notificationsListBox->GetSelection());
    Notification declineNotif(username,NotificationTypeEnum::DECLINEDEVENT,notificationData[notificationsListBox->GetSelection()].getEvent());
    notificationsToSend.push_back(std::pair<Notification,string>(declineNotif,"DECLINE"));
    notificationData.erase(notificationData.begin() + notificationsListBox->GetSelection());
    acceptButton->Enable(false);
    dismissButton->Enable(false);
    rejectButton->Enable(false);
    notificationsListBox->Delete(notificationsListBox->GetSelection());
}

void NotificationsDialog::onDismissButton(wxCommandEvent& event)
{
    clearedNotifications.push_back(notificationsListBox->GetSelection());
    notificationData.erase(notificationData.begin() + notificationsListBox->GetSelection());
    acceptButton->Enable(false);
    dismissButton->Enable(false);
    rejectButton->Enable(false);
    notificationsListBox->Delete(notificationsListBox->GetSelection());
}

void NotificationsDialog::OnSelection(wxCommandEvent& event)
{
    int a = notificationsListBox->GetSelection();
    if (notificationData.size()>notificationsListBox->GetSelection()){
        if (notificationData[a].getType()==NotificationTypeEnum::NEWEVENT){
            acceptButton->Enable(true);
            rejectButton->Enable(true);
            dismissButton->Enable(false);
        }else{
            acceptButton->Enable(false);
            rejectButton->Enable(false);
            dismissButton->Enable(true);
        }
    }
}

void NotificationsDialog::onOK(wxCommandEvent& event)
{
    EndModal(wxID_OK);
}

void NotificationsDialog::onCancel(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
}

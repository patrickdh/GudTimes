#pragma once

#include <wx/event.h>
#include <wx/window.h>

#include <string>
#include <utility>
#include <vector>

#include "Event.h"
#include "NDialog.h"
#include "Notification.h"

class NotificationsDialog : public NDialog
{
    public:
        NotificationsDialog(wxWindow* parent, std::vector<Notification> notices, std::string user);
        std::vector<int> getClearedNotifications();
        std::vector<Event> getEvents();
        std::vector<std::pair<Notification,std::string>> getOutgoingNotifications();
    protected:
        void onAcceptButton(wxCommandEvent& event);
        void onDeclineButton(wxCommandEvent& event);
        void onDismissButton(wxCommandEvent& event);
        void onSelection(wxCommandEvent& event);
        void onOK(wxCommandEvent& event);
        void onCancel(wxCommandEvent& event);
    private:
        std::vector<Notification> notificationData;
        std::vector<int> clearedNotifications;
        std::string username;
        std::vector<std::pair<Notification,std::string>> notificationsToSend;
        std::vector<Event> eventsToAdd;
};

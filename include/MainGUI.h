#pragma once

#include <wx/event.h>
#include <wx/wx.h>

#include <string>

#include "Calendar.h"
#include "Notification.h"
//#include "MainFrame.h"
#include "SSHConnection.h"

#include "MainFrame.h"
#include <vector>

class MainGUI: public MainFrame
{
   public:
        MainGUI(wxWindow* parent, SSHConnection* sshconn, const std::string& user);
        ~MainGUI();
    protected:
        void onClose(wxCloseEvent& event);
        void refreshButton(wxCommandEvent& event);
        void addEventButton(wxCommandEvent& event);
        void scheduleEventButton(wxCommandEvent& event);
        void deleteEventButton(wxCommandEvent& event);
        void viewNotificationsButton(wxCommandEvent& event);
        void addCalendarButton(wxCommandEvent& event);
        void addCalendarURLButton(wxCommandEvent& event);
        void deleteCalendarButton(wxCommandEvent& event);
        void logoutButton(wxCommandEvent& event);
        void onCalendarSelect(wxCommandEvent& event);
        void onDateSelect(wxCommandEvent& event);
    private:
        SSHConnection* connection;
        std::string username;
        std::vector<Calendar> calendars;
        std::vector<Notification> notifications;
        void fetchNotifications();
        void updateNotificationsFlag();
        void fetchCalendars();
        void listCalendars();
        void drawSchedule();
        void clearLocalData();
};

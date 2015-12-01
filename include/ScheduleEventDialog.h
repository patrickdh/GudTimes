#pragma once

#include <wx/event.h>
#include <wx/window.h>

#include <string>
#include <vector>

#include "Event.h"
#include "SEDialog.h"
#include "SSHConnection.h"

class ScheduleEventDialog : public SEDialog
{
    public:
        ScheduleEventDialog(wxWindow* parent, SSHConnection* sshconn, const std::string& user);
        Event getEvent() const;
        std::vector<std::string> getUsers() const;
    protected:
        void OnFormChange(wxCommandEvent& event);
        void OnFindTimes(wxCommandEvent& event);
        void OnCreate(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        wxArrayString generateTimeRanges (vector<wxDateTime>, int duration);
    private:
        SSHConnection* connection;
        std::string username;
        Event createdEvent;
        std::vector<std::string> userList;
};

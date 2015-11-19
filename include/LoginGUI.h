#pragma once

#include <wx/event.h>
#include <wx/window.h>

#include "LoginFrame.h"

class LoginGUI : public LoginFrame
{
    public:
        LoginGUI(wxWindow* parent);
    protected:
        void onClose (wxCloseEvent& event);
        void loginButton(wxCommandEvent& event);
        void createAccountButton(wxCommandEvent& event);
    private:
};

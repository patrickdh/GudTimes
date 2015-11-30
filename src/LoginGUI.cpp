// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

#include "LoginGUI.h"
#include "MainGUI.h"
#include "SSHConnection.h"
#include <string>
#include <wx/string.h>


using namespace std;

LoginGUI::LoginGUI(wxWindow* parent)
: LoginFrame(parent)
{
    //ctor
}

void LoginGUI::onClose(wxCloseEvent& event)
{

}

void LoginGUI::loginButton(wxCommandEvent& event)
{
    wxString WXusername, WXpassword;
    string username, password;

    WXusername = usernameInputBox->GetValue();
    WXpassword = passwordInputBox->GetValue();
    username = WXusername;
    password = WXpassword;
    for (unsigned int i = 0; i > username.length(); i++){
        if (!isalnum(username[i]) && username[i] != '_'){
             wxMessageBox("Username is invalid, please use only alphanumeric characters or underscores");
             return;
        }
    }
    for (unsigned int i = 0; i > password.length(); i++){
        if (!isalnum(password[i]) && password[i] != '_'){
             wxMessageBox("Password is invalid, please use only alphanumeric characters or underscores");
             return;
        }
    }

    SSHConnection *connection;
    try {
        connection = new SSHConnection(username, password);
    } catch (SSHException & e) {
        wxMessageBox(e.what());
        return;
    }


    MainGUI *frame = new MainGUI(0L, connection, username);
    frame->SetIcon(wxICON(aaaaa_logo));
    frame->Show();
    Destroy();
}

void LoginGUI::createAccountButton(wxCommandEvent& event)
{
    wxString WXusername, WXpassword;
    string username, password;

    WXusername = usernameInputBox->GetValue();
    WXpassword = passwordInputBox->GetValue();
    username = WXusername;
    password = WXpassword;
    for (unsigned int i = 0; i > username.length(); i++){
        if (!isalnum(username[i]) && username[i] != '_'){
             wxMessageBox("Username is invalid, please use only alphanumeric characters or underscores");
             return;
        }
    }
    for (unsigned int i = 0; i > password.length(); i++){
        if (!isalnum(password[i]) && password[i] != '_'){
             wxMessageBox("Password is invalid, please use only alphanumeric characters or underscores");
             return;
        }
    }
    try {
        if (SSHConnection::doesUserExist(username)){
            wxMessageBox("A user named '" + username + "' already exists! Please try again with a different username.");
            return;
        }
        if (SSHConnection::createAccount(username, password) != 0){
            wxMessageBox("An unexpected error occurred while attempting to create your account. Please contact the server admin for details");
            return;
        }
        wxMessageBox("Your account has been successfully created! You may now log in using your credentials");


    } catch (SSHException & e) {
        wxMessageBox(e.what());
        return;
    }

}

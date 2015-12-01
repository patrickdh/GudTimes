#include "MainGUI.h"
#include "LoginGUI.h"
#include "Calendar.h"
#include "NotificationAccess.h"
#include "AddEventDialog.h"
#include "ScheduleEventDialog.h"
#include "DeleteEventDialog.h"
#include "NotificationsDialog.h"
#include <wx/filedlg.h>
#include <wx/textdlg.h>
#include <wx/msgdlg.h>
#include <fstream>
#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <windows.h>
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

using namespace std;

MainGUI::MainGUI(wxWindow *frame, SSHConnection *conn, const std::string& uname)
    : MainFrame(frame)
{
    connection = conn;
    username = uname;
    wxCommandEvent dummy;
    refreshButton(dummy);
}

MainGUI::~MainGUI()
{
    //dtor
}

void MainGUI::onClose(wxCloseEvent &event)
{
    clearLocalData();
    delete connection;
    Destroy();
}

void MainGUI::refreshButton(wxCommandEvent &event)
{
    clearLocalData();
    fetchNotifications();
    fetchCalendars();
}

void MainGUI::addEventButton(wxCommandEvent &event)
{
    wxArrayInt cldrList;
    int num = calendarList->GetSelections(cldrList);
    if(num != 1) {
        wxMessageBox("Please select a single calendar!");
    }
    else {
        if(!calendars.at(cldrList.Item(0)).getIsEditable()) {
            wxMessageBox("Calendar is read-only, please enter a valid calendar!");
        }
        else {
            AddEventDialog *dialog = new AddEventDialog(this);
            if (dialog->ShowModal() == wxID_OK) {
                   calendars.at(cldrList.Item(0)).addEvent(dialog->getEvent());
                   drawSchedule();
            }
        }
    }


}

void MainGUI::scheduleEventButton(wxCommandEvent &event)
{
    wxArrayInt cldrList;
    int num = calendarList->GetSelections(cldrList);
    if(num != 1) {
        wxMessageBox("Please select a single calendar!");
    }
    else {
        if(!calendars.at(cldrList.Item(0)).getIsEditable()) {
            wxMessageBox("Calendar is read-only, please enter a valid calendar!");
        }
        else {
            ScheduleEventDialog *dialog = new ScheduleEventDialog(this, connection, username);
            if(dialog->ShowModal()== wxID_OK) {
                Event evt = dialog->getEvent();
                vector<string> users = dialog->getUsers();
                Notification newNot(username,NotificationTypeEnum::NEWEVENT, evt);
                try {
                    connection->sendNotification(newNot, users);
                } catch (SSHException &e) {
                    wxMessageBox(e.what());
                }
                calendars.at(cldrList.Item(0)).addEvent(evt);
                string fileName = calendars.at(cldrList.Item(0)).getFileName();
                wxFileName calName(fileName);
                connection->uploadFile(calName);
                drawSchedule();
            }
        }
    }
}

void MainGUI::deleteEventButton(wxCommandEvent &event)
{
    wxArrayInt cldrList;
    int num = calendarList->GetSelections(cldrList);
    if(num != 1) {
        wxMessageBox("Please select a single calendar!");
    }
    else {
        if(!calendars.at(cldrList.Item(0)).getIsEditable()) {
            wxMessageBox("Calendar is read-only, please enter a valid calendar!");
        }
        else {
            DeleteEventDialog *dialog = new DeleteEventDialog(this,calendars.at(cldrList.Item(0)));
            if (dialog->ShowModal() == wxID_OK) {
                Calendar calTest = calendars.at(cldrList.Item(0));
                int indx = dialog->getIndex();
                calTest.addEvent(calTest.getEvents().at(indx));
                string calName = calTest.getFileName();
                wxFileName cal(calName);
                connection->uploadFile(cal);
                drawSchedule();
            }

        }
    }

}

void MainGUI::viewNotificationsButton(wxCommandEvent &event)
{
    wxArrayInt cldrList;
    int num = calendarList->GetSelections(cldrList);
    if(num != 1) {
        wxMessageBox("Please select a single calendar!");
    }
    else {
        if(!calendars.at(cldrList.Item(0)).getIsEditable()) {
            wxMessageBox("Calendar is read-only, please enter a valid calendar!");
        }
        else {
            NotificationsDialog *dialog = new NotificationsDialog(this,notifications,username);
            if (dialog->ShowModal() == wxID_OK) {
                vector<Event> events = dialog->getEvents();
                //add each to calendar
                vector<int> clearedEvents = dialog->getClearedNotifications();
                NotificationAccess *notAccess = new NotificationAccess(connection);
                notAccess->clearNotifications(clearedEvents);
                vector<pair<Notification,string>> outNot = dialog->getOutgoingNotifications();
                typedef vector<pair<Notification, string> > vector_type;
                for (vector_type::const_iterator pos = outNot.begin();
                     pos != outNot.end(); ++pos) {

                        try {
                            connection->sendNotification(pos->first,pos->second);
                        }catch(SSHException &e) {
                            wxMessageBox(e.what());
                        }
                }
                    drawSchedule();
            }
        }
    }
}

void MainGUI::addCalendarButton(wxCommandEvent &event)
{
    wxString caption = wxT("Choose a file");
    wxString wildcard = wxT("ICS files (*.ics)|*.ics");
    wxString defaultDir = wxT("c:\\temp");
    wxString defaultFilename = wxEmptyString;

    wxFileDialog dialog(this, caption, defaultDir, defaultFilename,
        wildcard, wxOPEN);
    if (dialog.ShowModal() == wxID_OK)
    {
        wxString path = dialog.GetPath();
        string dest = "./data/";
        dest += dialog.GetFilename().mb_str();
        std::ifstream  src(path.mb_str(), std::ios::binary);
        std::ofstream  dst(dest,   std::ios::binary);
        dst << src.rdbuf();
        Calendar cal1(dest,true);
        wxFileName file1(dest);
        connection->uploadFile(file1);
        calendars.push_back(cal1);
        listCalendars();
    }
}

void MainGUI::addCalendarURLButton(wxCommandEvent &event)
{
    wxTextEntryDialog dialog(this,
            wxT("Please enter a calendar URL for a .ics file"),
            wxT("Please enter a URL"),
            wxT("Enter here"),
            wxOK | wxCANCEL);

    if (dialog.ShowModal() == wxID_OK) {
        int test = connection->addURL(dialog.GetValue().mb_str());
        if(test == 0) {
            connection->addURL(dialog.GetValue().mb_str());
            wxCommandEvent dummy;
            refreshButton(dummy);
        }
        else if(test == 1) {
            wxMessageBox("Cannot access URL, please enter a valid URL.");
        }
        else {
            wxMessageBox("Incorrect file found, please provide a link to a valid .ics file.");
        }
    }
}

void MainGUI::deleteCalendarButton(wxCommandEvent &event)
{
    wxArrayInt cldrList;
    int num = calendarList->GetSelections(cldrList);
    if(num != 1) {
        wxMessageBox("Please select a single calendar for deletion!");
    }
    else {
        calendars.at(cldrList.Item(0)).deleteCalendar();
        try {
            wxFileName cal(calendars.at(cldrList.Item(0)).getFileName());
            connection->deleteFile(cal.GetFullName().mb_str());
        } catch(SSHException &e) {
            wxMessageBox(e.what());
        }
        calendars.erase(calendars.begin()+cldrList.Item(0));
        listCalendars();
        drawSchedule();
    }
}

void MainGUI::logoutButton(wxCommandEvent &event)
{
    clearLocalData();
    delete connection;
    LoginGUI* frame = new LoginGUI(0L);
    frame->SetIcon(wxICON(aaaaa_logo)); // To Set App Icon
    frame->Show();
    Destroy();
}

void MainGUI::onCalendarSelect(wxCommandEvent &event)
{
    drawSchedule();
}

void MainGUI::onDateSelect(wxCommandEvent &event)
{
    drawSchedule();
}

void MainGUI::fetchNotifications()
{
    try {
        connection->getNotifications();
    } catch(SSHException &e) {
        wxMessageBox(e.what());
    }

    updateNotificationsFlag();
}

void MainGUI::updateNotificationsFlag()
{
    ifstream inputFile("notify.txt");
    if ( !inputFile.peek() == ifstream::traits_type::eof() )
    {
        notificationButton->SetOwnBackgroundColour(*wxRED);

    }
    else {
        notificationButton->SetOwnBackgroundColour(wxColour(224,224,224));
    }


}

void MainGUI::fetchCalendars()
{
    //Confused of purpose here
    calendars.clear();
    int cals;
    try {
        cals = connection->getCalendars();
    } catch(SSHException &e) {
        wxMessageBox(e.what());
    }
    DIR           *d;
    struct dirent *dir;
    vector<string> dirlist;
    int i=0;
    d = opendir("./data");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
        i++;
        cout<<dir->d_name<<endl;
        dirlist.push_back(dir->d_name);
        }
        for (size_t n = 0; n < dirlist.size(); n++)
            cout << dirlist[ n ] << " ";
            cout << endl;

        closedir(d);
    }
    listCalendars();
    drawSchedule();


}

void MainGUI::listCalendars()
{
    calendarList->Clear();
    for(int i = 0; i < calendars.size() ; i++)
    {
        string cal1 = calendars.at(i).getFileName();
        string name = cal1.substr(7,cal1.size()-11);
        string subcal1 = name.substr(0,3);
        if (subcal1.compare("ro_") == 0 ){
            name = cal1.substr(10,cal1.size()-14);
        }
        calendarList->Append(name);
    }

}

void MainGUI::drawSchedule()
{

}

void MainGUI::clearLocalData()
{
    DIR           *d;
    struct dirent *dir;
    vector<string> dirlist;
    d = opendir("./data");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
        dirlist.push_back(dir->d_name);
        }
        for (size_t n = 0; n < dirlist.size(); n++)
            //remove(dirlist[ n ]);

        closedir(d);
    }


}



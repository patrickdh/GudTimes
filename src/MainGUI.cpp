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
#include <sstream>
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
    {
        displayVect.push_back(sun00);
        displayVect.push_back(sun01);
        displayVect.push_back(sun02);
        displayVect.push_back(sun03);
        displayVect.push_back(sun04);
        displayVect.push_back(sun05);
        displayVect.push_back(sun06);
        displayVect.push_back(sun07);
        displayVect.push_back(sun08);
        displayVect.push_back(sun09);
        displayVect.push_back(sun10);
        displayVect.push_back(sun11);
        displayVect.push_back(sun12);
        displayVect.push_back(sun13);
        displayVect.push_back(sun14);
        displayVect.push_back(sun15);
        displayVect.push_back(sun16);
        displayVect.push_back(sun17);
        displayVect.push_back(sun18);
        displayVect.push_back(sun19);
        displayVect.push_back(sun20);
        displayVect.push_back(sun21);
        displayVect.push_back(sun22);
        displayVect.push_back(sun23);
        displayVect.push_back(mon00);
        displayVect.push_back(mon01);
        displayVect.push_back(mon02);
        displayVect.push_back(mon03);
        displayVect.push_back(mon04);
        displayVect.push_back(mon05);
        displayVect.push_back(mon06);
        displayVect.push_back(mon07);
        displayVect.push_back(mon08);
        displayVect.push_back(mon09);
        displayVect.push_back(mon10);
        displayVect.push_back(mon11);
        displayVect.push_back(mon12);
        displayVect.push_back(mon13);
        displayVect.push_back(mon14);
        displayVect.push_back(mon15);
        displayVect.push_back(mon16);
        displayVect.push_back(mon17);
        displayVect.push_back(mon18);
        displayVect.push_back(mon19);
        displayVect.push_back(mon20);
        displayVect.push_back(mon21);
        displayVect.push_back(mon22);
        displayVect.push_back(mon23);
        displayVect.push_back(tues00);
        displayVect.push_back(tues01);
        displayVect.push_back(tues02);
        displayVect.push_back(tues03);
        displayVect.push_back(tues04);
        displayVect.push_back(tues05);
        displayVect.push_back(tues06);
        displayVect.push_back(tues07);
        displayVect.push_back(tues08);
        displayVect.push_back(tues09);
        displayVect.push_back(tues10);
        displayVect.push_back(tues11);
        displayVect.push_back(tues12);
        displayVect.push_back(tues13);
        displayVect.push_back(tues14);
        displayVect.push_back(tues15);
        displayVect.push_back(tues16);
        displayVect.push_back(tues17);
        displayVect.push_back(tues18);
        displayVect.push_back(tues19);
        displayVect.push_back(tues20);
        displayVect.push_back(tues21);
        displayVect.push_back(tues22);
        displayVect.push_back(tues23);
        displayVect.push_back(wed00);
        displayVect.push_back(wed01);
        displayVect.push_back(wed02);
        displayVect.push_back(wed03);
        displayVect.push_back(wed04);
        displayVect.push_back(wed05);
        displayVect.push_back(wed06);
        displayVect.push_back(wed07);
        displayVect.push_back(wed08);
        displayVect.push_back(wed09);
        displayVect.push_back(wed10);
        displayVect.push_back(wed11);
        displayVect.push_back(wed12);
        displayVect.push_back(wed13);
        displayVect.push_back(wed14);
        displayVect.push_back(wed15);
        displayVect.push_back(wed16);
        displayVect.push_back(wed17);
        displayVect.push_back(wed18);
        displayVect.push_back(wed19);
        displayVect.push_back(wed20);
        displayVect.push_back(wed21);
        displayVect.push_back(wed22);
        displayVect.push_back(wed23);
        displayVect.push_back(thurs00);
        displayVect.push_back(thurs01);
        displayVect.push_back(thurs02);
        displayVect.push_back(thurs03);
        displayVect.push_back(thurs04);
        displayVect.push_back(thurs05);
        displayVect.push_back(thurs06);
        displayVect.push_back(thurs07);
        displayVect.push_back(thurs08);
        displayVect.push_back(thurs09);
        displayVect.push_back(thurs10);
        displayVect.push_back(thurs11);
        displayVect.push_back(thurs12);
        displayVect.push_back(thurs13);
        displayVect.push_back(thurs14);
        displayVect.push_back(thurs15);
        displayVect.push_back(thurs16);
        displayVect.push_back(thurs17);
        displayVect.push_back(thurs18);
        displayVect.push_back(thurs19);
        displayVect.push_back(thurs20);
        displayVect.push_back(thurs21);
        displayVect.push_back(thurs22);
        displayVect.push_back(thurs23);
        displayVect.push_back(fri00);
        displayVect.push_back(fri01);
        displayVect.push_back(fri02);
        displayVect.push_back(fri03);
        displayVect.push_back(fri04);
        displayVect.push_back(fri05);
        displayVect.push_back(fri06);
        displayVect.push_back(fri07);
        displayVect.push_back(fri08);
        displayVect.push_back(fri09);
        displayVect.push_back(fri10);
        displayVect.push_back(fri11);
        displayVect.push_back(fri12);
        displayVect.push_back(fri13);
        displayVect.push_back(fri14);
        displayVect.push_back(fri15);
        displayVect.push_back(fri16);
        displayVect.push_back(fri17);
        displayVect.push_back(fri18);
        displayVect.push_back(fri19);
        displayVect.push_back(fri20);
        displayVect.push_back(fri21);
        displayVect.push_back(fri22);
        displayVect.push_back(fri23);
        displayVect.push_back(sat00);
        displayVect.push_back(sat01);
        displayVect.push_back(sat02);
        displayVect.push_back(sat03);
        displayVect.push_back(sat04);
        displayVect.push_back(sat05);
        displayVect.push_back(sat06);
        displayVect.push_back(sat07);
        displayVect.push_back(sat08);
        displayVect.push_back(sat09);
        displayVect.push_back(sat10);
        displayVect.push_back(sat11);
        displayVect.push_back(sat12);
        displayVect.push_back(sat13);
        displayVect.push_back(sat14);
        displayVect.push_back(sat15);
        displayVect.push_back(sat16);
        displayVect.push_back(sat17);
        displayVect.push_back(sat18);
        displayVect.push_back(sat19);
        displayVect.push_back(sat20);
        displayVect.push_back(sat21);
        displayVect.push_back(sat22);
        displayVect.push_back(sat23);
    }
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
                   string fileName = calendars.at(cldrList.Item(0)).getFileName();
                wxFileName calName(fileName);
                connection->uploadFile(calName);
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
                int indx = dialog->getIndex();
                calendars.at(cldrList.Item(0)).deleteEvent(indx);
                string calName = calendars.at(cldrList.Item(0)).getFileName();
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
                for(auto event : events){
                    calendars.at(cldrList.Item(0)).addEvent(event);
                }
                string fileName = calendars.at(cldrList.Item(0)).getFileName();
                wxFileName calName(fileName);
                connection->uploadFile(calName);

                vector<int> clearedEvents = dialog->getClearedNotifications();
                NotificationAccess *notAccess = new NotificationAccess(connection);
                notAccess->clearNotifications(clearedEvents);
                notifications = NotificationAccess::readNotifications();
                updateNotificationsFlag();
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

void MainGUI::onDateSelect(wxCalendarEvent &event)
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

    notifications = NotificationAccess::readNotifications();

    updateNotificationsFlag();
}

void MainGUI::updateNotificationsFlag()
{
    if (notifications.size() != 0)
    {
        notificationButton->SetOwnBackgroundColour(*wxRED);

    }
    else {
        notificationButton->SetOwnBackgroundColour(wxColour(224,224,224));
    }


}

void MainGUI::fetchCalendars()
{
    calendars.clear();
     try{
        connection->getCalendars();
    }
    catch (SSHException& e)
    {
        wxMessageBox(e.what());
    }

    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;

    std::string fileName;

    hFind = FindFirstFile("data\\*", &FindFileData);

    do{
        fileName = FindFileData.cFileName;
        std::string filePath("./data\\" + fileName);
        string extension = filePath.substr(filePath.length()-4,4);
        if (extension == ".ics"){
            if (filePath.substr(7,3) == "ro_"){
                calendars.push_back(Calendar(filePath,false));
            }
            else{
                calendars.push_back(Calendar(filePath,true));
            }
        }
    }while (FindNextFile(hFind, &FindFileData) != 0);
    FindClose(hFind);

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
    wxFont font = time02->GetFont();
    for (unsigned int i = 0 ; i < displayVect.size(); ++i){
        displayVect.at(i)->Clear();
        displayVect.at(i)->SetBackgroundColour(wxColour(255,255,255));
        displayVect.at(i)->SetFont(font);
    }

    wxDateTime selDate = datePicker->GetDate();
    wxDateSpan oneDay(0,0,0,1);
    wxDateTime wkStart(selDate);
    wxDateTime wkEnd;
    while (wkStart.GetWeekDay() != wxDateTime::WeekDay::Mon){
        wkStart.Subtract(oneDay);
    }
    wkEnd = wkStart + 7*oneDay;

    for (unsigned int i = 0 ; i < calendars.size(); ++i)
    {
        if (calendarList->IsSelected(i))
        {
            vector<Event> events = calendars.at(i).getEvents();
            for (unsigned int i = 0; i < events.size(); ++i)
            {
                wxDateTime evStart = events.at(i).getStart();
                wxDateTime evEnd = events.at(i).getEnd();
                FrequencyEnum evFreq = events.at(i).getFrequency();
                int evCount = events.at(i).getRepeatCount();
                if ( evFreq != FrequencyEnum::NONE)
                {
                    if (evFreq == FrequencyEnum::DAILY)
                    {
                        wxDateSpan oneDay(0,0,0,1);
                        do
                        {
                            if ((evStart.IsBetween(wkStart,wkEnd) && evEnd.IsBetween(wkStart,wkEnd)) || evStart.IsLaterThan(wkEnd))
                            {
                                break;
                            }
                            else
                            {
                                evStart += oneDay;
                                evEnd += oneDay;
                                evCount--;
                            }
                        }
                        while(evCount >= 0);
                    }
                    else if (evFreq == FrequencyEnum::WEEKLY)
                    {
                        wxDateSpan oneWeek(0,0,1,0);
                        do
                        {
                            if ((evStart.IsBetween(wkStart,wkEnd) && evEnd.IsBetween(wkStart,wkEnd)) || evStart.IsLaterThan(wkEnd))
                            {
                                break;
                            }
                            else
                            {
                                evStart += oneWeek;
                                evEnd += oneWeek;
                                evCount--;
                            }
                        }
                        while(evCount >= 0);
                        if (evCount == -1){
                            evStart = wxDateTime();
                            evEnd = wxDateTime();
                        }
                    }
                    else if (evFreq == FrequencyEnum::MONTHLY)
                    {
                        wxDateSpan oneMonth(0,1,0,0);
                        do
                        {
                            if ((evStart.IsBetween(wkStart,wkEnd) && evEnd.IsBetween(wkStart,wkEnd)) || evStart.IsLaterThan(wkEnd))
                            {
                                break;
                            }
                            else
                            {
                                evStart += oneMonth;
                                evEnd += oneMonth;
                                evCount--;
                            }
                        }
                        while(evCount >= 0);
                    }
                    else if (evFreq == FrequencyEnum::ANNUALLY)
                    {
                        wxDateSpan oneYear(1,0,0,0);
                        do
                        {
                            if ((evStart.IsBetween(wkStart,wkEnd) && evEnd.IsBetween(wkStart,wkEnd)) || evStart.IsLaterThan(wkEnd))
                            {
                                break;
                            }
                            else
                            {
                                evStart += oneYear;
                                evEnd += oneYear;
                                evCount--;
                            }
                        }
                        while(evCount >= 0);
                    }
                }
                bool done = true;
                do
                {
                    if (evStart.IsBetween(wkStart,wkEnd) && evEnd.IsBetween(wkStart,wkEnd))
                    {
                        done = true;
                        int Sday = (int) events.at(i).getStart().GetWeekDay();
                        int Shour = events.at(i).getStart().GetHour();
                        int Eday = (int) events.at(i).getEnd().GetWeekDay();
                        int Ehour = events.at(i).getEnd().GetHour();
                        int Sindex = Sday*24+Shour;
                        int Eindex = Eday*24+Ehour;
                        for (int j = Sindex ; j <= Eindex ; ++j)
                        {
                            if (j == Eindex && events.at(i).getEnd().GetMinute() == 0)
                            {
                                break;
                            }
                            string info;
                            info.append(events.at(i).getTitle());
                            info.append("\n");
                            info.append(events.at(i).getStart().Format("%H:%M"));
                            info.append(" - ");
                            info.append(events.at(i).getEnd().Format("%H:%M"));
                            displayVect.at(j)->SetValue(info.c_str());
                            displayVect.at(j)->SetBackgroundColour(wxColour(157,249,244));
                        }
                        if (evFreq == FrequencyEnum::DAILY && evCount > 0)
                        {
                            done = false;
                            wxDateSpan oneDay(0,0,0,1);
                            evCount--;
                            evStart += oneDay;
                            evEnd += oneDay;
                        }
                    }

                }while(!done);
            }
        }
    }

}

void MainGUI::clearLocalData()
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;

    std::string fileName;

    hFind = FindFirstFile("data\\*", &FindFileData);

    do{
        fileName = FindFileData.cFileName;
        std::string filePath("data\\" + fileName);
        if (fileName != ".gitignore")
            remove (filePath.c_str());
    }while (FindNextFile(hFind, &FindFileData) != 0);
    FindClose(hFind);

}



// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

#include "ScheduleEventDialog.h"
#include "Event.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

ScheduleEventDialog::ScheduleEventDialog(wxWindow* parent, SSHConnection* sshconn, const std::string& user)
: SEDialog(parent)
{
    connection = sshconn;
    username = user;
}

Event ScheduleEventDialog::getEvent() const
{
    return createdEvent;
}

std::vector<std::string> ScheduleEventDialog::getUsers() const
{
    return userList;
}

void ScheduleEventDialog::OnFindTimes(wxCommandEvent& event)
{
    if (textboxDuration->IsEmpty() || textboxEventName->IsEmpty() || textboxUsers->IsEmpty()){
        wxMessageBox("Please fill in all fields.");
    }
    else if (textboxDuration->GetValue().IsNumber()){
        eventChoiceList->Clear();
        buttonCreate->Enable();
        vector<wxDateTime> timeSlots;
        string line;
        int numberSlots;
        wxString bufferStart, bufferEnd;
        wxDateTime bufferStartDT, bufferEndDT;

        wxString wxUsers = textboxUsers->GetValue();
        wxString durationString = textboxDuration->GetValue();

        int duration = wxAtoi(durationString);

        string usersString = string(wxUsers.mb_str());

        stringstream ss (usersString);
        string token;

        while (getline(ss, token, ',')){
            if (SSHConnection::doesUserExist(token)){
            userList.push_back(token);
            }
            else{
                string error(token);
                error.append(" is not a valid user.");
                wxMessageBox(error.c_str());
                return;
            }
        }

        int result = connection->findTimes(userList,duration);
        connection->getTimes();

        ifstream fileIn("./data\\found_times.txt");

        fileIn >> numberSlots;
        cout << numberSlots << endl;
        getline(fileIn, line);
        if (numberSlots != 0){
            while(getline(fileIn, line)){

                cout << line << endl;

                bufferStart = line.substr(0,8);
                bufferEnd   = line.substr(9,8);

                cout << bufferStart << endl;
                cout << bufferEnd << endl;


                bufferStartDT.ParseTime(bufferStart);
                bufferEndDT.ParseTime(bufferEnd);

                timeSlots.push_back(bufferStartDT);
                timeSlots.push_back(bufferEndDT);
            }

            generateTimeRanges(timeSlots, duration);

        } else {
            wxMessageBox( wxT("No availability to schedule an event."));
        }
    } else {
        wxMessageBox(wxT("Please type a duration in number of minutes."));
    }
}

void ScheduleEventDialog::OnExit( wxCommandEvent& event )
{
    EndModal(wxID_CANCEL);
}

void ScheduleEventDialog::OnFormChange(wxCommandEvent& event)
{
    eventChoiceList->Clear();
    buttonCreate->Disable();
}

void ScheduleEventDialog::OnFormChange(wxCalendarEvent& event){
    eventChoiceList->Clear();
    buttonCreate->Disable();
}

void ScheduleEventDialog::OnCreate( wxCommandEvent& event )
{
wxString startString;
wxString endString;
wxDateTime date = calendarSelect->GetDate();
wxDateTime startDT = date;
wxDateTime endDT = date;
wxString choice = eventChoiceList->GetString(eventChoiceList->GetSelection());
string details = textboxEventName->GetValue().mb_str();

startString = choice.SubString(0,7);
endString   = choice.SubString(9,16);

startDT.ParseTime(startString);
endDT.ParseTime(endString);

createdEvent = Event(details, startDT, endDT);
this->EndModal(wxID_OK);
}

void ScheduleEventDialog::generateTimeRanges(vector<wxDateTime> vt, int duration){
    int i;
    int sMin, eMin; //starting time and ending time in minutes
    int sHour; //current hour
    int cMin; //current time in minutes
    int hourAdjust, minuteAdjust;
    wxDateTime bufferDT(0,0,0);

    wxArrayString listItems;
    wxString buffer;

    for (i = 0; i < vt.size(); i+=2){
        sMin = vt[i].GetMinute() + vt[i].GetHour()*60;
        eMin = vt[i+1].GetMinute() + vt[i+1].GetHour()*60;

        sHour = vt[i].GetHour();

        cMin = sMin;

        hourAdjust = (int)(duration / 60);
        minuteAdjust = duration - (hourAdjust * 60);

        while ((eMin - cMin) >= duration){
            bufferDT.SetHour(vt[i].GetHour());
            bufferDT.SetMinute(vt[i].GetMinute());
            bufferDT.SetSecond(0);

            buffer << bufferDT.FormatISOTime();

            if ((vt[i].GetMinute() + minuteAdjust) >= 60)
                bufferDT.SetHour(vt[i].GetHour() + 1 + hourAdjust);
            else
                bufferDT.SetHour(vt[i].GetHour() + hourAdjust);
            bufferDT.SetMinute((vt[i].GetMinute() + minuteAdjust) % 60);
            bufferDT.SetSecond(0);

            buffer << "-" << bufferDT.FormatISOTime();
            eventChoiceList->Append(buffer);

            buffer.clear();

            vt[i].SetMinute((vt[i].GetMinute() + 15) % 60);
            if (vt[i].GetMinute() == 0)
                vt[i].SetHour(vt[i].GetHour() + 1);
            cMin += 15;
        }
    }
}

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

#include "ScheduleEventDialog.h"

using namespace std;

ScheduleEventDialog::ScheduleEventDialog(wxWindow* parent, SSHConnection* sshconn, const std::string& user)
: SEDialog(parent)
{
    //ctor
}

Event ScheduleEventDialog::getEvent() const
{

}

std::vector<std::string> ScheduleEventDialog::getUsers() const
{

}

void ScheduleEventDialog::onChange(wxCommandEvent& event)
{
	textboxUsers->Clear();
	textboxDuration->Clear();
	textboxEventName->Clear();
	eventChoiceList->Clear();
    buttonCreate->Disable();
}

void ScheduleEventDialog::onFindTimes(wxCommandEvent& event)
{
   //bool validEntries = validateEntries();
    if (true){
        vector<string> users;
        vector<wxDateTime> timeSlots;
        ifstream fileIn;
        string line;
        int numberSlots;
        wxString bufferStart, bufferEnd;
        wxDateTime bufferStartDT, bufferEndDT;

        wxString wxUsers = textboxUsers->GetValue();
        wxString durationString = textboxDuration->GetValue();
        wxDateTime date = calendarSelect->GetDate();

        int duration = wxAtoi(durationString);

        string usersString = string(wxUsers.mb_str());

        stringstream ss (usersString);
        string token;

        while (getline(ss, token, ',')){
            users.push_back(token);
        }

        //send users and duration, day, month, year to server
        //server returns path to file (text file probably) of available time slots
        /*fileIn.open(PATH);

        fileIn >> numberSlots;
        if (numberSlots != 0){
            while(getline(fileIn, line){

                bufferStart = line.SubString(0,7);
                bufferEnd   = line.SubString(9,16);

                bufferStartDT.Parse(bufferStart);
                bufferEndDT.Parse(bufferEnd);

                timeSlots.push_back(bufferStartDT);
                timeSlots.push_back(bufferEndDT);
            }
        } else {
            //wxMessageBox("No time slots")
        }
        generateTimeRanges(timeSlots, duration);
        */
    }
}

void ScheduleEventDialog::onOK(wxCommandEvent& event)
{
	wxString startString;
wxString endString;
wxDateTime date = calendarSelect->GetDate();
wxDateTime startDT = date;
wxDateTime endDT = date;
wxString choice = eventChoiceList->GetString(eventChoiceList->GetSelection());

startString = choice.SubString(0,7);
endString   = choice.SubString(9,16);

startDT.ParseTime(startString);
endDT.ParseTime(endString);

//Event newEvent(textboxEventName.GetLineText(), startDT, endDT);

}

void ScheduleEventDialog::onCancel(wxCommandEvent& event)
{
    Close();
}

wxArrayString ScheduleEventDialog::generateTimeRanges(vector<wxDateTime> vt, int duration){
    int i;
    int sMin, eMin;
    int sHour, eHour;
    int cHour, cMin;
    int hourAdjust, minuteAdjust;
    wxDateTime bufferDT(0,0,0);

    wxArrayString listItems;
    wxString buffer;

    for (i = 0; i < vt.size(); i+=2){
        sMin = vt[i].GetMinute() + vt[i].GetHour()*60;
        eMin = vt[i+1].GetMinute() + vt[i+1].GetHour()*60;

        sHour = vt[i].GetHour();
        eHour = vt[i+1].GetHour();

        cHour = sHour;
        cMin = sMin;

        hourAdjust = (int)(duration / 60);
        minuteAdjust = duration - (hourAdjust * 60);

        while ((eMin - cMin) >= duration){
            bufferDT.SetHour(vt[i].GetHour());
            bufferDT.SetMinute(vt[i].GetMinute());

            buffer << bufferDT.FormatISOTime();

            bufferDT.SetHour(vt[i].GetHour() + hourAdjust);
            bufferDT.SetMinute(vt[i].GetMinute() + minuteAdjust);

            buffer << "-" << bufferDT.FormatISOTime();
            listItems.Add(buffer);

            buffer.clear();

            vt[i].SetMinute((vt[i].GetMinute() + 15) % 60);
            if (vt[i].GetMinute() == 0)
                vt[i].SetHour(vt[i].GetHour() + 1);
            cMin += 15;
        }
    }
    return listItems;
}


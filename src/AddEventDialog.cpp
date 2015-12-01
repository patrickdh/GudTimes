// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

#include "AddEventDialog.h"
#include "Event.h"
using namespace std;

AddEventDialog::AddEventDialog(wxWindow* parent)
: AEDialog(parent)
{
    //ctor
}

Event AddEventDialog::getEvent() const
{
    return createdEvent;
}

void AddEventDialog::onOK(wxCommandEvent& event)
{
    int length = eventTitle->GetLineLength(0);
    string title;
    if(length > 0 )
    {
       title = eventTitle->GetValue();
    }
    else{
        wxMessageBox("Must input valid title");
        return;
    }
    wxDateTime eventSDate = DatePicker->GetValue();
    wxDateTime eventEDate = DatePicker->GetValue();
    int i = eventStart->GetSelection();
    wxString startT = eventStart->GetString(i);
    unsigned short hour = wxAtoi(startT(0,2));
    unsigned short minute = wxAtoi(startT(3,2));
    eventSDate.SetHour(hour);
    eventSDate.SetMinute(minute);

    int j = eventEnd->GetSelection();
    wxString endTime = eventEnd->GetString(j);
    unsigned short ehour = wxAtoi(endTime(0,2));
    unsigned short eminute = wxAtoi(endTime(3,2));
    eventEDate.SetHour(ehour);
    eventEDate.SetMinute(eminute);
    if (eventEDate.IsLaterThan(eventSDate)!= TRUE){
        wxMessageBox("End time must be later than start time");
        return;
    }

    int k = eventFrequency->GetSelection();
    wxString frequency = eventFrequency->GetString(k);
    FrequencyEnum freq = FrequencyEnum::NONE;
    if(frequency == "DAILY")
    {
        freq = FrequencyEnum::DAILY;
    }
    else if (frequency == "WEEKLY")
    {
        freq = FrequencyEnum::WEEKLY;
    }
    else if (frequency == "MONTHLY")
    {
        freq = FrequencyEnum::MONTHLY;
    }
    else if (frequency == "ANNUALLY")
    {
        freq = FrequencyEnum::ANNUALLY;
    }

    int repeat = Repeat->GetValue();

    if (freq == FrequencyEnum::NONE)
        createdEvent = Event(title, eventSDate, eventEDate);
    else
        createdEvent = Event(title, eventSDate, eventEDate, freq, repeat);

    EndModal(wxID_OK);

}
void AddEventDialog::onCancel(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
}

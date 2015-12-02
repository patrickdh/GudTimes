// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

#include "DeleteEventDialog.h"

using namespace std;

DeleteEventDialog::DeleteEventDialog(wxWindow* parent, const Calendar& cal)
: DEDialog(parent)
{
    this->SetIcon(wxICON(aaaaa_logo));
    events = cal.getEvents();
    wxString a;

    for (unsigned int i =0 ; i < events.size() ; ++i){
        if (events[i].isValid()){
        a = " ";
        a.Append(events[i].getTitle());
        a.Append("\, ");
        Event evnt = events[i];
        a.Append(evnt.getStart().FormatISODate());
        a.Append("\, ");
        a.Append(evnt.getStart().FormatISOTime());
        a.Append(" - ");
        a.Append(evnt.getEnd().FormatISOTime());
        }
        else a = "INVALID";
        deleteEventListBox->Append(a);

    }
}

int DeleteEventDialog::getIndex() const
{
    return indexToDelete;
}

void DeleteEventDialog::onOK(wxCommandEvent& event)
{
    indexToDelete = deleteEventListBox->GetSelection();
    EndModal(wxID_OK);
}

void DeleteEventDialog::onCancel(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
}

void DeleteEventDialog::onSelection(wxCommandEvent& event)
{
    if (events.size()>deleteEventListBox->GetSelection()){
        deleteButton->Enable(true);
    }else {
        deleteButton->Enable(false);
    }
}

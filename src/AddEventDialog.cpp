// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // WX_PRECOMP

#include "AddEventDialog.h"

using namespace std;

AddEventDialog::AddEventDialog(wxWindow* parent)
: AEDialog(parent)
{
    //ctor
}

Event AddEventDialog::getEvent()
{

}

void AddEventDialog::onOK(wxCommandEvent& event)
{

}

void AddEventDialog::onCancel(wxCommandEvent& event)
{

}

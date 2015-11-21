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
    //ctor
}

int DeleteEventDialog::getIndex() const
{

}

void DeleteEventDialog::onOK(wxCommandEvent& event)
{

}

void DeleteEventDialog::onCancel(wxCommandEvent& event)
{

}

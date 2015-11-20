#pragma once

#include <wx/event.h>
#include <wx/window.h>

#include "Calendar.h"
#include "DEDialog.h"

class DeleteEventDialog : public DEDialog
{
    public:
        DeleteEventDialog(wxWindow* parent, const Calendar& cal);
        int getIndex();
    protected:
        void onOK(wxCommandEvent& event);
        void onCancel(wxCommandEvent& event);
    private:
        int indexToDelete;
};

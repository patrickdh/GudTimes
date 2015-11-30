#pragma once

#include <wx/event.h>
#include <wx/window.h>

#include "Calendar.h"
#include "DEDialog.h"
#include "Calendar.h"

class DeleteEventDialog : public DEDialog
{
    public:
        DeleteEventDialog(wxWindow* parent, const Calendar& cal);
        int getIndex() const;
    protected:
        void onOK(wxCommandEvent& event);
        void onCancel(wxCommandEvent& event);
        void onSelection(wxCommandEvent& event);
    private:
        int indexToDelete;
        std::vector<Event> events;
};

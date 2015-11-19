#pragma once

#include<wx/event.h>
#include<wx/window.h>

#include "AEDialog.h"
#include "Event.h"

class AddEventDialog : public AEDialog
{
    public:
        AddEventDialog(wxWindow* parent);
        Event getEvent();
    protected:
        void onOK(wxCommandEvent& event);
        void onCancel(wxCommandEvent& event);
    private:
        Event createdEvent;
};

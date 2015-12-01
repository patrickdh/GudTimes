#include "LoginGUI.h"

#include "GudTimesMain.h"

IMPLEMENT_APP(GudTimesMain);

bool GudTimesMain::OnInit()
{
    LoginGUI* frame = new LoginGUI(0L);
    frame->SetIcon(wxICON(aaaaa_logo)); // To Set App Icon
    frame->Show();

    return true;
}

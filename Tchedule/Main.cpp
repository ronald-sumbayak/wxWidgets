#include "wx/wx.h"
#include "Frame.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit ();
};

IMPLEMENT_APP (MyApp)
DECLARE_APP (MyApp)

bool MyApp::OnInit () {
    srand (time (nullptr));
    Frame *frame = new Frame ("Tchedule");
    frame->Show ();
    return true;
}
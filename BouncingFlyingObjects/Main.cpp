#include <cstdlib>
#include "wx/wx.h"
#include "MainFrame.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit ();
};

IMPLEMENT_APP (MyApp)
DECLARE_APP (MyApp)

bool MyApp::OnInit () {
	srand(time(nullptr));
    MainFrame *frame = new MainFrame ("Bouncing Box");
    frame->Show ();
    return true;
}
#include "wx/wx.h"
#include "MainFrame.h"
#include <cstdlib>

class MyApp : public wxApp {
public:
    virtual bool init ();
};

IMPLEMENT_APP (MyApp)
DECLARE_APP (MyApp)

bool MyApp::init () {
    srand (time (nullptr));
    MainFrame* frame = new MainFrame ("AlphaNumeric Printer");
    frame->Show ();
    return true;
}
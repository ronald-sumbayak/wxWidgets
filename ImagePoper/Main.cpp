#include "MainFrame.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit ();
};

IMPLEMENT_APP (MyApp)
DECLARE_APP (MyApp)

bool MyApp::OnInit () {
    srand (time (nullptr));
    MainFrame *frame = new MainFrame ("Image Poper");
    frame->Show (true);
    return true;
}
#include "MainFrame.h"
#include "MainWindow.h"

MainFrame::MainFrame (const wxString &title) : wxFrame (nullptr, wxID_ANY, title) {
    mWindow = new MainWindow (this);
}
#pragma once
#include "wx\wx.h"
class MainWindow;

class MainFrame : public wxFrame {
private:
    MainWindow *mWindow;

public:
    MainFrame (const wxString &title);
};
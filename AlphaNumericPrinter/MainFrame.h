#pragma once
#include "wx\wx.h"
class MainWindow;

class MainFrame : public wxFrame {
private:
    MainWindow *window;

public:
    MainFrame (const wxString &title);
};
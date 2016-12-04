#pragma once
#include "wx\wx.h"
class MainWindow;

class MainFrame : public wxFrame {
    
    MainWindow *window;

public:
    MainFrame (const wxString&);
    ~MainFrame ();
};
#pragma once
#include "wx/wx.h"
#include "ClassWindow.h"
#include "StudentWindow.h"
class Window;

class Frame : public wxFrame {

    ClassWindow *classWindow;
    StudentWindow *studentWindow;

public:
    Frame (const wxString&);
    string replaceFromSpace (string);
    ~Frame ();
};
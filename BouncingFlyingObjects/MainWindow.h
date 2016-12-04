#pragma once
#include <vector>
#include "MainFrame.h"
class FlyingObject;

class MainWindow : public wxWindow {

    std::vector<wxColor> colors;
    std::vector<FlyingObject*> objects;
    wxTimer *timer;
    void setupColor ();
    bool isEmptySpace (wxPoint);
    wxColor randomColor ();
    DECLARE_EVENT_TABLE ()

public:
    MainWindow (MainFrame*);
    void onPaint (wxPaintEvent&);
    void onTimer (wxTimerEvent&);
    void putFlyingObject (wxMouseEvent&);
    void toggleTimer (wxMouseEvent&);
    ~MainWindow();
};
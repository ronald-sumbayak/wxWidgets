#pragma once
#include "wx/wx.h"
#include "Data.h"
#include "wx/grid.h"
#include "StudentWindow.h"

class ClassWindow : public wxWindow {

    int currenttime;
    Data data;
    wxGridCellCoords *coords;
    vector<Kelas> currentClasses;
    wxGrid *list;
    wxTimer *timer;
    StudentWindow *studentWindow;
    DECLARE_EVENT_TABLE ()

public:
    void setData (Data);
    void setupList ();
    void syncWithStudentWindow (StudentWindow*);
    void onGridClick (wxGridEvent&);
    void onTick (wxTimerEvent&);
    void refreshClasses ();
    int tominute (string);
    int toMinute (string);
    int toDay (string);
    int toDayNow (string);
    ClassWindow (wxFrame*);
    ~ClassWindow();
};
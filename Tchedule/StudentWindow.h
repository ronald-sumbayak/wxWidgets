#pragma once
#include "wx/wx.h"
#include "wx/grid.h"
#include "Data.h"

class StudentWindow : public wxWindow {

    Data data;
    wxGrid *studentList, *dosen;

public:
    void setData (Data);
    void onGridClick (int, int);
    StudentWindow (wxFrame*);
    ~StudentWindow ();
};
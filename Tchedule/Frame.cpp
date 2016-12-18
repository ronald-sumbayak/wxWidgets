#include "Frame.h"
#include "Data.h"

Frame::Frame (const wxString &title) : wxFrame (nullptr, wxID_ANY, title, wxDefaultPosition, wxSize (800, 600)) {
    Data data;
    data.loadData ();

    studentWindow = new StudentWindow (this);
    studentWindow->setData (data);
    studentWindow->Show ();

    classWindow = new ClassWindow (this);
    classWindow->setData (data);
    classWindow->Show ();
    classWindow->syncWithStudentWindow (studentWindow);
}

Frame::~Frame() {
    delete classWindow;
    delete studentWindow;
}
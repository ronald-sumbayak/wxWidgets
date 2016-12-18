#include "ClassWindow.h"
#include "Data.h"
#define TIMER_ID 1
#define REFRESH_EVERY 30

BEGIN_EVENT_TABLE (ClassWindow, wxWindow)
EVT_GRID_CELL_LEFT_CLICK (ClassWindow::onGridClick)
EVT_TIMER (TIMER_ID, ClassWindow::onTick)
END_EVENT_TABLE ()

ClassWindow::ClassWindow (wxFrame *frame) : wxWindow (frame, wxID_ANY, wxDefaultPosition, wxSize (400, 600)) {
    SetBackgroundColour (*wxBLUE);
    timer = new wxTimer (this, TIMER_ID);
    currenttime = toMinute (string (wxNow ().mb_str ()));
    timer->Start ((REFRESH_EVERY - ((currenttime % 60) % REFRESH_EVERY)) * 1000);
}

void ClassWindow::setData (Data data) {
    this->data = data;
    refreshClasses ();
    setupList ();
}

void ClassWindow::setupList () {
    int row = (int) ceil (currentClasses.size () / 2.0);
    list = new wxGrid (this, wxID_ANY, wxDefaultPosition, wxSize (380, 570));
    list->CreateGrid (row, 2);
    list->Center ();
    list->EnableEditing (false);
    list->HideColLabels ();
    list->HideRowLabels ();
    for (int i = 0; i < row; i++) list->SetRowSize (i, 75);
    for (int i = 0; i < 2; i++) list->SetColSize (i, 200);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 2; j++) {
            if ((i*2)+j >= currentClasses.size ()) break;
            Kelas kelas = currentClasses[(i*2)+j];
            list->SetCellAlignment (i, j, -1, 10);
            list->SetCellValue (i, j, kelas.nama + "\n" + kelas.ruang + "\n" + kelas.mulai + " - " + kelas.selesai);
            list->SetCellAlignment (i, j, wxALIGN_CENTER, wxALIGN_CENTER);
        }
    }
}

void ClassWindow::syncWithStudentWindow (StudentWindow *studentWindow) {
    this->studentWindow = studentWindow;
}

void ClassWindow::onGridClick (wxGridEvent &event) {
    coords = new wxGridCellCoords (event.GetRow (), event.GetCol ());
    if (list->GetCellValue (*coords).IsEmpty ()) return;
    list->SelectBlock (*coords, *coords);
    list->SetGridCursor (event.GetRow (), event.GetCol ());
    studentWindow->onGridClick (event.GetRow (), event.GetCol ());
}

ClassWindow::~ClassWindow () {

}

void ClassWindow::onTick (wxTimerEvent &event) {
    currenttime = toMinute (string (wxNow ().mb_str ()));
    if (currenttime % REFRESH_EVERY == 0) {
        refreshClasses ();
        setupList ();
        timer->Stop ();
        timer->Start (REFRESH_EVERY * 1000);
    }

    if (list->GetCellValue (*coords).IsEmpty ()) return;
    list->SelectBlock (*coords, *coords);
    list->SetGridCursor (coords->GetRow (), coords->GetCol ());
}

void ClassWindow::refreshClasses () {
    currentClasses.clear ();
    for (int i = 0; i < data.classes.size (); i++) {
        if (toDay (data.classes[i].hari) != toDayNow (string (wxNow ().mb_str ()))) continue;
        if (currenttime < tominute (data.classes[i].mulai)) continue;
        if (currenttime > tominute (data.classes[i].selesai)) continue;
        currentClasses.push_back (data.classes[i]);
    }
}

int ClassWindow::toMinute (string str) {
    char a1, a2, a3, a4;
    a1 = str.c_str ()[11] - '0';
    a2 = str.c_str ()[12] - '0';
    a3 = str.c_str ()[14] - '0';
    a4 = str.c_str ()[15] - '0';
    return (((a1 * 10) + a2) * 60) + (a3 * 10) + a4;
}

int ClassWindow::tominute (string str) {
    char a1, a2, a3, a4;
    a1 = str.c_str ()[0] - '0';
    a2 = str.c_str ()[1] - '0';
    a3 = str.c_str ()[3] - '0';
    a4 = str.c_str ()[4] - '0';
    return (((a1 * 10) + a2) * 60) + (a3 * 10) + a4;
}

int ClassWindow::toDay (string day) {
    if (day == "Senin") return 0;
    if (day == "Selasa") return 1;
    if (day == "Rabu") return 2;
    if (day == "Kamis") return 3;
    if (day == "Jumat") return 4;
    if (day == "Sabtu") return 5;
    if (day == "Minggu") return 6;
    return -1;
}

int ClassWindow::toDayNow (string day) {
    day = day.substr (0, 3);
    if (day == "Mon") return 0;
    if (day == "Tue") return 1;
    if (day == "Wed") return 2;
    if (day == "Thu") return 3;
    if (day == "Fri") return 4;
    if (day == "Sat") return 5;
    if (day == "Sun") return 6;
    return -1;
}
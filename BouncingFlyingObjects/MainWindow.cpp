#include "MainWindow.h"
#include "Box.h"
#include "Circle.h"
#define TIMER_ID 6116
#define TIMER_INTERVAL 10

BEGIN_EVENT_TABLE (MainWindow, wxWindow)
    EVT_PAINT (MainWindow::onPaint)
    EVT_TIMER (TIMER_ID, MainWindow::onTimer)
    EVT_LEFT_DOWN (MainWindow::putFlyingObject)
    EVT_RIGHT_DOWN (MainWindow::toggleTimer)
END_EVENT_TABLE ()

MainWindow::MainWindow (MainFrame *frame) : wxWindow (frame, wxID_ANY) {
    setupColor ();
    timer = new wxTimer (this, TIMER_ID);
    timer->Start (TIMER_INTERVAL);
}

void MainWindow::setupColor () {
    colors.push_back (*wxRED);
    colors.push_back (*wxGREEN);
    colors.push_back (*wxBLACK);
    colors.push_back (*wxWHITE);
    colors.push_back (*wxBLUE);
    colors.push_back (*wxYELLOW);
    colors.push_back (*wxLIGHT_GREY);
}

void MainWindow::onTimer (wxTimerEvent &event) {
    wxPoint window (GetClientSize ().GetWidth (), GetClientSize ().GetHeight ());
    for (unsigned int x = 0; x < objects.size (); x++) {
        objects[x]->move (window);
        for (unsigned int i = 0; i < objects.size (); i++) if (x != i) objects[x]->collide (objects[i]);
    }
    Refresh ();
}

void MainWindow::onPaint (wxPaintEvent &event) {
    wxPaintDC pdc (this);
    for (FlyingObject *object : objects) object->draw (pdc);
}

void MainWindow::putFlyingObject (wxMouseEvent &event) {
    wxPoint mouse (wxGetMousePosition ().x, wxGetMousePosition ().y);

    if (isEmptySpace (mouse)) {
        switch (rand () % 3) {
            case 0: objects.push_back (new Circle (mouse, randomColor (), randomColor ())); break;
            case 1: objects.push_back (new Rect (mouse, randomColor (), randomColor ())); break;
            case 2: objects.push_back (new Box (mouse, randomColor (), randomColor ())); break;
            default: break;
        }
        Refresh ();
    }
}

bool MainWindow::isEmptySpace (wxPoint mouse) {
    for (unsigned int i = 0; i < objects.size (); i++) if (objects[i]->isBelow (mouse)) return false;
    return true;
}

void MainWindow::toggleTimer (wxMouseEvent &event) {
    timer->IsRunning () ? timer->Stop () : timer->Start ();
}

wxColor MainWindow::randomColor () {
    return colors[rand () % colors.size ()];
}

MainWindow::~MainWindow () {
    delete timer;
}
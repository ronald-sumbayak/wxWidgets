#include "MainWindow.h"
#include "Box.h"
#include "Circle.h"
#define TIMER_ID 6116

BEGIN_EVENT_TABLE (MainWindow, wxWindow)
	EVT_LEFT_DOWN (MainWindow::onMouseClick)
	EVT_RIGHT_DOWN (MainWindow::toggleTimer)
	EVT_TIMER (TIMER_ID, MainWindow::onTimer)
    EVT_PAINT (MainWindow::onPaint)
END_EVENT_TABLE ()

MainWindow::MainWindow (MainFrame *parent) : wxWindow (parent, wxID_ANY) {
    SetBackgroundColour (wxColour (*wxWHITE));
	mShapeSize = 10;
	setupColor();
	mTimer = new wxTimer(this, TIMER_ID);
	mTimer->Start (50);
}

void MainWindow::setupColor() {
	mColor.push_back(*wxRED);
	mColor.push_back(*wxGREEN);
	mColor.push_back(*wxBLACK);
	mColor.push_back(*wxWHITE);
	mColor.push_back(*wxBLUE);
	mColor.push_back(*wxYELLOW);
	mColor.push_back(*wxLIGHT_GREY);
}

void MainWindow::onTimer(wxTimerEvent &event) {
	wxMessageOutputDebug().Printf("Timer invoked");
	for (unsigned int x = 0; x < mObject.size(); x++) {
		mObject[x]->move(GetClientSize().GetWidth(), GetClientSize().GetHeight());
		for (unsigned int i = 0; i < mObject.size(); i++) if (x != i) mObject[x]->collide(mObject[i]);
	}
	Refresh();
}

void MainWindow::onPaint (wxPaintEvent &event) {
	wxPaintDC pdc(this);
	for (FlyingObject *object : mObject) object->draw(pdc);
}

void MainWindow::onMouseClick(wxMouseEvent &event) {
	int xx, yy;
	xx = wxGetMousePosition().x;
	yy = wxGetMousePosition().y;

	if (isEmptySpace(xx, yy)) {
		int type = (rand() % 3);
		if (type == 0) mObject.push_back(new Circle(xx, yy, mColor[rand() % 7], mColor[rand() % 7]));
		else if (type == 1) mObject.push_back(new Rect(xx, yy, mColor[rand() % 7], mColor[rand() % 7]));
		else mObject.push_back(new Box(xx, yy, mColor[rand() % 7], mColor[rand() % 7]));
		Refresh();
	}
}

bool MainWindow::isEmptySpace(int xx, int yy) {
	for (unsigned int i = 0; i < mObject.size(); i++) if (mObject[i]->isBelow(xx, yy)) return false;
	return true;
}

void MainWindow::toggleTimer(wxMouseEvent &event) {
	if (mTimer->IsRunning()) mTimer->Stop();
	else mTimer->Start ();
}

MainWindow::~MainWindow() {
	mTimer->Stop();
	delete mTimer;
	mObject.clear();
}
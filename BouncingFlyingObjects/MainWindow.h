#pragma once
#include <vector>
#include "wx\wx.h"
#include "MainFrame.h"
#include "FlyingObject.h"
class Box;

class MainWindow : public wxWindow {

	int mShapeSize;
	std::vector<wxColor> mColor;
	std::vector<FlyingObject*> mObject;
	wxTimer *mTimer;
    DECLARE_EVENT_TABLE ()

public:
    MainWindow (MainFrame *parent);
	void setupColor();
    void onPaint (wxPaintEvent &event);
	void onTimer(wxTimerEvent &event);
	void onMouseClick(wxMouseEvent &event);
	void toggleTimer(wxMouseEvent &event);
	bool isEmptySpace(int xx, int yy);
	~MainWindow();
};
#pragma once
#include "wx\wx.h"
#include "MainFrame.h"

class MainWindow : public wxWindow {
private:
	wxBitmap *bitmap;
	int imageSize;
	bool isAlphaNumeric (int numb);
	DECLARE_EVENT_TABLE ()

public:
	MainWindow (MainFrame *parent);
	void onKeyDown (wxKeyEvent &event);
	void onKeyUp (wxKeyEvent &event);
	void onChar (wxKeyEvent &event);
	void loadImage (wxString keyCode);
	void onPaint (wxPaintEvent& event);
};
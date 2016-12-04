#pragma once
#include "MainFrame.h"

class MainWindow : public wxWindow {

    wxBitmap *bitmap;
    int imageSize;
    bool isAlphaNumeric (int);
    DECLARE_EVENT_TABLE ()

public:
    MainWindow (MainFrame*);
    void loadImage (wxKeyEvent&);
    void onPaint (wxPaintEvent&);
	~MainWindow ();
};
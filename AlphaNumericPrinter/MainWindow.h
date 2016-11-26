#pragma once
#include "wx\wx.h"
#include "MainFrame.h"

class MainWindow : public wxWindow {
private:
    wxBitmap *mBitmap;
    int mImageSize;
    bool isAlphaNumeric (int numb);
    DECLARE_EVENT_TABLE ()

public:
    MainWindow (MainFrame *parent);
    void loadImage (wxKeyEvent &event);
    void onPaint (wxPaintEvent &event);
};
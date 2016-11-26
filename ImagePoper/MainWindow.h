#pragma once
#include "wx\wx.h"

class MainWindow : public wxWindow {
    
    int mImageSize, mImageCount;
    wxBitmap *mBitmap;
    DECLARE_EVENT_TABLE ()
    
public:
    MainWindow (wxFrame *parent);
    void loadImage (wxMouseEvent &event);
    void onPaint (wxPaintEvent &event);
};
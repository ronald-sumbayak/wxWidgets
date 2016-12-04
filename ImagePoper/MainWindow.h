#pragma once
#include "MainFrame.h"

class MainWindow : public wxWindow {
    
    int imageSize, imageCount;
    wxBitmap *bitmap;
    DECLARE_EVENT_TABLE ()
    
public:
    MainWindow (wxFrame*);
    void loadImage (wxMouseEvent&);
    void onPaint (wxPaintEvent&);
};
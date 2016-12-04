#pragma once
#include "FlyingObject.h"

class Rect : public FlyingObject {

public:
    Rect (wxPoint, wxColor, wxColor);
    void draw (wxPaintDC&);
    virtual int top ();
    virtual int left ();
    virtual int right ();
    virtual int bottom ();
};


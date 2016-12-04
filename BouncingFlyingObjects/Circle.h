#pragma once
#include "FlyingObject.h"

class Circle : public FlyingObject {

    int radius;

public:
    Circle (wxPoint, wxColor, wxColor);
    void draw (wxPaintDC&);
    virtual int top ();
    virtual int left ();
    virtual int right ();
    virtual int bottom ();
};
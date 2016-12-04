#pragma once
#include "wx/dcclient.h"

class FlyingObject {

protected:
    int x, y, width, height, xDir, yDir, xSpeed, ySpeed;
    wxColor fillColor, outlineColor;

public:
    FlyingObject (wxPoint, wxColor, wxColor);
    virtual void draw (wxPaintDC&) = 0;
    virtual void collide (FlyingObject*);
    void move (wxPoint);
    bool isBelow (wxPoint);
    virtual int top () = 0;
    virtual int left () = 0;
    virtual int right () = 0;
    virtual int bottom () = 0;
};


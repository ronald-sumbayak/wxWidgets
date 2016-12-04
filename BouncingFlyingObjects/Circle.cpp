#include "Circle.h"

Circle::Circle (wxPoint mouse, wxColor fillColor, wxColor outlineColor) : FlyingObject (mouse, fillColor, outlineColor) {
    radius = height = width = width / 2;
}

void Circle::draw (wxPaintDC &pdc) {
    pdc.SetBrush (wxBrush(wxColor(fillColor)));
    pdc.SetPen (wxPen (wxColor (outlineColor), 2, wxPENSTYLE_SOLID));
    pdc.DrawCircle (x, y, radius);
}

int Circle::top () { return y + radius; }
int Circle::left () { return x - radius; }
int Circle::right () { return x + radius; }
int Circle::bottom () { return y - radius; }

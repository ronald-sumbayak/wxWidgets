#include "Rect.h"

Rect::Rect (wxPoint mouse, wxColor fillColor, wxColor outlineColor) : FlyingObject (mouse, fillColor, outlineColor) {

}

void Rect::draw (wxPaintDC &pdc) {
    pdc.SetBrush (wxBrush (wxColor (fillColor)));
    pdc.SetPen (wxPen (wxColor (outlineColor), 2, wxPENSTYLE_SOLID));
    pdc.DrawRectangle (wxPoint (x, y), wxSize (width, height));
}

int Rect::top () { return y + height; }
int Rect::left () { return x; }
int Rect::right () { return x + width; }
int Rect::bottom () { return y; }
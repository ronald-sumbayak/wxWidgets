#include "Box.h"
#include "FlyingObject.h"

Box::Box(int xx, int yy, wxColor fillColor, wxColor outlineColor) : FlyingObject (fillColor, outlineColor) {
	width = height = (rand() % 140) + 10;
	x = xx - (width / 2);
	y = yy - (height / 2);
}

void Box::draw(wxPaintDC &pdc) {
	pdc.SetBrush(wxBrush(wxColor(mFillColor)));
	pdc.SetPen(wxPen(wxColor(mOutlineColor), 2, wxPENSTYLE_SOLID));
	pdc.DrawRectangle(wxPoint(x, y), wxSize(width, height));
}

int Box::left() {
	return x;
}

int Box::right() {
	return x + width;
}

int Box::bottom() {
	return y;
}

int Box::top() {
	return y + height;
}

int Box::type() {
	return TYPE_RECT;
}
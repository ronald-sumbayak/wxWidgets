#include "Circle.h"
#include "FlyingObject.h"
#include "Box.h"
#include <cmath>

Circle::Circle(int xx, int yy, wxColor fillColor, wxColor outlineColor) : FlyingObject(fillColor, outlineColor) {
	width = height = (rand() % 140) + 10;
	x = xx;
	y = yy;
}

void Circle::draw(wxPaintDC &pdc) {
	pdc.SetBrush(wxBrush(wxColor(mFillColor)));
	pdc.SetPen(wxPen(wxColor(mOutlineColor), 2, wxPENSTYLE_SOLID));
	pdc.DrawCircle(x, y, width/2);
}

int Circle::left() {
	return x - (width / 2);
}

int Circle::right() {
	return x + (width / 2);
}

int Circle::bottom() {
	return y - (height / 2);
}

int Circle::top() {
	return y + (height / 2);
}

int Circle::type() {
	return TYPE_CIRCLE;
}
#include "Rect.h"
#include "FlyingObject.h"

Rect::Rect(int xx, int yy, wxColor fillColor, wxColor outlineColor) : FlyingObject(fillColor, outlineColor) {
	width = (rand() % 140) + 10;
	height = (rand() % 140) + 10;
	x = xx - (width / 2);
	y = yy - (height / 2);
}

Rect::Rect(wxColor fillColor, wxColor outlineColor) : FlyingObject(fillColor, outlineColor) {

}

void Rect::draw(wxPaintDC &pdc) {
	pdc.SetBrush(wxBrush(wxColor(mFillColor)));
	pdc.SetPen(wxPen(wxColor(mOutlineColor), 2, wxPENSTYLE_SOLID));
	pdc.DrawRectangle(wxPoint(x, y), wxSize(width, height));
}

int Rect::left() {
	return x;
}

int Rect::right() {
	return x + width;
}

int Rect::bottom() {
	return y;
}

int Rect::top() {
	return y + height;
}

int Rect::type() {
	return TYPE_RECT;
}
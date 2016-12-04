#pragma once
#include "FlyingObject.h"
class Rect : public FlyingObject {
public:
	Rect(int xx, int yy, wxColor fillColor, wxColor outlineColor);
	Rect(wxColor fillColor, wxColor outlineColor);
	void draw(wxPaintDC &pdc);
	int left();
	int right();
	int bottom();
	int top();
	int type();
};


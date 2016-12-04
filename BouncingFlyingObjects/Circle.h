#pragma once
#include "FlyingObject.h"
#include "Box.h"
class Circle : public FlyingObject {

public:
	Circle(int xx, int yy, wxColor fillColor, wxColor outlineColor);
	void draw(wxPaintDC &pdc);
	int left();
	int right();
	int bottom();
	int top();
	int type();
};


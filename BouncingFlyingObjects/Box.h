#pragma once
#include "wx\dcclient.h"
#include "FlyingObject.h"
class FlyingObject;

class Box : public FlyingObject {

public:
	Box(int xx, int yy, wxColor fillColor, wxColor outlineColor);
	void draw(wxPaintDC &pdc);
	int left();
	int right();
	int bottom();
	int top();
	int type();
};


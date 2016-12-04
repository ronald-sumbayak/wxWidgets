#pragma once
#include "wx/dcclient.h"

class FlyingObject {

protected:
	int const TYPE_CIRCLE = 1, TYPE_RECT = 0;
	int x, y, width, height, xDir, yDir, xSpeed, ySpeed;
	wxColor mFillColor, mOutlineColor;

public:
	FlyingObject(wxColor fillColor, wxColor outlineColor);
	virtual void draw(wxPaintDC &dc) = 0;
	void move(int xMax, int yMax);
	virtual void collide(FlyingObject *fo);
	bool isBelow(int xx, int yy);
	virtual int left() = 0;
	virtual int right() = 0;
	virtual int bottom() = 0;
	virtual int top() = 0;
	virtual int type() = 0;
};


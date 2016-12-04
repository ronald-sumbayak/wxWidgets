#pragma once
#include "wx\dcclient.h"
#include "FlyingObject.h"
#include "Rect.h"

class Box : public Rect {

public:
	Box(int xx, int yy, wxColor fillColor, wxColor outlineColor);
};


#include "Box.h"
#include "Rect.h"

Box::Box(int xx, int yy, wxColor fillColor, wxColor outlineColor) : Rect (xx, yy, fillColor, outlineColor) {
	width = height = (rand() % 140) + 10;
	x = xx - (width / 2);
	y = yy - (height / 2);
}
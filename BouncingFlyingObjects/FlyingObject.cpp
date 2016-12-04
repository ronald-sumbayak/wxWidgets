#include "FlyingObject.h"

FlyingObject::FlyingObject(wxColor fillColor, wxColor outlineColor) {
	mFillColor = fillColor;
	mOutlineColor = outlineColor;
	xDir = (rand() % 3) - 1;
	yDir = (rand() % 3) - 1;
	xSpeed = 1;
	ySpeed = 1;
}

void FlyingObject::move(int xMax, int yMax) {
	if (left() <= 0) xDir = -xDir;
	else if (right() >= xMax) xDir = -xDir;
	x += (xDir * xSpeed);

	if (bottom() <= 0) yDir = -yDir;
	else if (top() >= yMax) yDir = -yDir;
	y += (yDir * ySpeed);
}

void FlyingObject::collide(FlyingObject *fo) {
	if ((fo->bottom() <= bottom() && bottom() <= fo->top()) || (fo->bottom() <= top() && top() <= fo->top()) ||
		(bottom() <= fo->bottom() && fo->bottom() <= top()) || (bottom() <= fo->top() && fo->top() <= top())) {

		if (xDir <= 0 && (left() <= fo->right() && left() + xSpeed > fo->right())) {
			xDir = 1;
			fo->xDir = -1;
		}
		else if (xDir >= 0 && (right() >= fo->left() && right() - xSpeed < fo->left())) {
			xDir = -1;
			fo->xDir = 1;
		}
	}
	if ((fo->left() <= left() && left() <= fo->right()) || (fo->left() <= right() && right() <= fo->right()) ||
		(fo->left() >= left() && fo->left() <= right()) || (fo->right() >= left() && fo->right() <= right())) {

		if (yDir <= 0 && (bottom() <= fo->top() && bottom() + ySpeed > fo->top())) {
			yDir = 1;
			fo->yDir = -1;
		}
		else if (yDir >= 0 && (top() >= fo->bottom() && top() - ySpeed < fo->bottom())) {
			yDir = -1;
			fo->yDir = 1;
		}
	}


}

bool FlyingObject::isBelow(int xx, int yy) {
	if (xx >= x && xx <= x + width && yy >= y && yy <= y + height) return true;
	else return false;
}
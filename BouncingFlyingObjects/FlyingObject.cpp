#include "FlyingObject.h"
#define MIN_SIZE 10
#define MAX_SIZE 150
#define MIN_SPEED 1
#define MAX_SPEED 5
#define random(min, max) (rand () % (max - min)) + min

FlyingObject::FlyingObject (wxPoint mouse, wxColor fillColor, wxColor outlineColor) {
    x = mouse.x;
    y = mouse.y;
    width = random (MIN_SIZE, MAX_SIZE);
    height = random (MIN_SIZE, MAX_SIZE);
    xDir = random (-1, 2);
    yDir = random (-1, 2);
    xSpeed = random (MIN_SPEED, MAX_SPEED);
    ySpeed = random (MIN_SPEED, MAX_SPEED);
    this->fillColor = fillColor;
    this->outlineColor = outlineColor;
}

void FlyingObject::move (wxPoint max) {
    if (left () <= 0 || right () >= max.x) xDir = -xDir;
    x += (xDir * xSpeed);
    if (bottom () <= 0 || top () >= max.y) yDir = -yDir;
    y += (yDir * ySpeed);
}

void FlyingObject::collide (FlyingObject *fo) {
    if ((fo->bottom () <= bottom () && bottom () <= fo->top ()) || (fo->bottom () <= top () && top () <= fo->top ()) ||
        (bottom () <= fo->bottom () && fo->bottom () <= top ()) || (bottom () <= fo->top () && fo->top () <= top ())) {

        if (xDir <= 0 && (left () <= fo->right () && left () + xSpeed > fo->right ())) {
            xDir = 1;
            fo->xDir = -1;
        }
        else if (xDir >= 0 && (right () >= fo->left () && right () - xSpeed < fo->left ())) {
            xDir = -1;
            fo->xDir = 1;
        }
    }
    
    if ((fo->left () <= left () && left () <= fo->right ()) || (fo->left () <= right () && right () <= fo->right ()) ||
        (fo->left () >= left () && fo->left () <= right ()) || (fo->right () >= left () && fo->right () <= right ())) {

        if (yDir <= 0 && (bottom () <= fo->top () && bottom () + ySpeed > fo->top ())) {
            yDir = 1;
            fo->yDir = -1;
        }
        else if (yDir >= 0 && (top () >= fo->bottom () && top () - ySpeed < fo->bottom ())) {
            yDir = -1;
            fo->yDir = 1;
        }
    }


}

bool FlyingObject::isBelow (wxPoint coord) {
    return x <= coord.x && coord.x <= x + width && y <= coord.y && coord.y <= y + height;
}
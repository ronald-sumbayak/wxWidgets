#include "Box.h"

Box::Box (wxPoint mouse, wxColor fillColor, wxColor outlineColor) : Rect (mouse, fillColor, outlineColor) {
    height = width;
}
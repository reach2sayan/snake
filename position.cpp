#include "position.hpp"

Position::Position(int newx, int newy, int h, int w){

	height = h;
	width = w;

	if (newx > height)
			x = 1;
	else if (newx < 1)
			x = height;
	else
			x = newx;

	if (newy > width-1)
		y = 1;
	else if (newy < 1)
		y = width;
	else
		y = newy;
}

void Position::setX(const int newx){

	if (newx > height)
		x = 0;
	else if (newx < 0)
		x = height;
	else
		x = newx;
}

void Position::setY(const int newy){

	if (newy > width)
		y = 0;
	else if (y < 0)
		y = width;
	else
		y = newy;
}

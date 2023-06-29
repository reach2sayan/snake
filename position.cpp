#include "position.hpp"

Position::Position(int newx, int newy, int h, int w){

	height = h;
	width = w;

	if (newx > width)
			x = 1;
	else if (newx < 1)
			x = width;
	else
			x = newx;

	if (newy > height)
		y = 1;
	else if (newy < 1)
		y = height;
	else
		y = newy;
}

void Position::setX(const int newx){

	if (newx > width)
		x = 0;
	else if (newx < 0)
		x = width;
	else
		x = newx;
}

void Position::setY(const int newy){

	if (newy > height)
		y = 0;
	else if (y < 0)
		y = height;
	else
		y = newy;
}

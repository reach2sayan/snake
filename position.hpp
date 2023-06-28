#ifndef __POSITION_H
#define __POSITION_H

class Position {

	private:
		int x;
		int y;
		int height;
		int width;

	public:

		Position() : x{0}, y{0}, height{0}, width{0} {}
		Position(int newx, int newy,int h, int w);
		void setX(const int newx);
		void setY(const int newy);
		int getX() const { return x; }
		int getY() const { return y; } 
		int get_height() const { return height; }
		int get_width() const { return width; }
};
#endif

#ifndef __SNAKE_H
#define __SNAKE_H

#include <vector>
#include "position.hpp"

class Food;
class ScreenObject;
enum Direction {LEFT, RIGHT, TOP, BOTTOM};
class Snake{

	private:
		std::vector<Position> snake;
		bool bEatsFruit = false;
		Direction direction;

	public:
		Snake(int height, int width);
		std::vector<Position>& getSnake() { return snake;}
		Direction getDirection() const { return direction; }
		void setDirection(const Direction d) { direction = d; }
		bool FatalCollision() const;
		void setEatingSuccess(const bool yes) { bEatsFruit = yes; }
		bool getEatingSuccess() const { return bEatsFruit; }
		void checkEatingSuccess(Food& foodObj, const ScreenObject& screenObj);

};
#endif

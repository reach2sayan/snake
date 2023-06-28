#ifndef __FOOD_H
#define __FOOD_H

#include "position.hpp"
#include "snake.hpp"

class Food{
	private:
		Position food;	
	
	public:
		Food(int width, int height, Snake& snakeObj);
		Position GetFood() const {return food; }
		void UpdateFood(int height, int width, Snake& snakeObj);
};
#endif

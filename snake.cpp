#include "snake.hpp"
#include "food.hpp"
#include "screenobject.hpp"

Snake::Snake(int height, int width){

	for (int i = 0; i < 5; i++) {
		snake.push_back(Position(30+i, 10, height, width));
	}

}

bool Snake::FatalCollision() const {

	for (int i = 2; i < snake.size(); i++)
		if (snake[0].getX() == snake[i].getX() && snake[0].getY() == snake[i].getY())
			return true;

	return false;
}

void Snake::checkEatingSuccess(Food& foodObj, const ScreenObject& screenObj){

	int height = screenObj.get_height();
	int width = screenObj.get_width();
	Position foodPos = foodObj.GetFood();
	if (snake[0].getX() == foodPos.getX() && 
			snake[0].getY() == foodPos.getY()){

		foodObj.UpdateFood(height, width, *this);
		bEatsFruit = true;
	}
	else
		bEatsFruit = false;
}



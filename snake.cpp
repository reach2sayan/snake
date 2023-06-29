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
	//auto message = std::to_string(snake.front().getX()) + " " + std::to_string(foodPos.getX());
	//screenObj.PrintMessage(message);
	if (snake.front().getX() == foodPos.getX() && 
			snake.front().getY() == foodPos.getY())
		bEatsFruit = true;
	else
		bEatsFruit = false;
}



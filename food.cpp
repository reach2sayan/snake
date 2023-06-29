#include "food.hpp"
#include <cstdlib>
#include <ctime>

Food::Food(int width, int height, Snake& snakeObj){

	srand(time(NULL));

	while(true){

		int x = rand()%width + 1;
		int y = rand()%height + 1;

		const std::vector<Position>& snake = snakeObj.getSnake();
		for (int i = 0; i < snake.size(); i++)
			if (snake[i].getX() == x && snake[i].getY() == y)
				continue; // if true, ignore the following and go back to the beginning of function

		if (x >= width-2 || y >= height-3)
			continue; // if true, ignore the following and go back to the beginning of function

		// if the coordinates are valid, add fruit in the window
		food = Position(y,x,height,width);
		break;
	};
}

void Food::UpdateFood(int height, int width, Snake& snakeObj){

	Food tmpFood = Food(width, height, snakeObj);
	food.setX(tmpFood.GetFood().getX());
	food.setY(tmpFood.GetFood().getY());
}



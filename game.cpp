#include "screenobject.hpp"
#include "food.hpp"
#include "snake.hpp"
#include <unistd.h>


char isUserReady() {return 'y'; }
char AskUserToPlayAgain() {return 'n'; }

int main(){

	if (isUserReady() == 'y'){

		ScreenObject screenObj = ScreenObject();
		int height = screenObj.get_height();
		int width = screenObj.get_width();

		Snake snakeObj = Snake(height,width);
		Food foodObj = Food(width, height, snakeObj);
		screenObj.DrawWindow();

		while(!screenObj.Quit()){

			if (snakeObj.FatalCollision()){
				move((height-2)/2, (width-2/2));
				printw("GAME OVER...");
			}
			else{

				snakeObj.checkEatingSuccess(foodObj, screenObj);
				screenObj.PositionFood(foodObj);
				screenObj.MoveAndDrawSnake(snakeObj);


				usleep(1000000);

			}
		}while(AskUserToPlayAgain() == 'y');
	}
	return 0;
}

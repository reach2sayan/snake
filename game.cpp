#include "screenobject.hpp"
#include "food.hpp"
#include "snake.hpp"
#include <unistd.h>
#include <string>


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

		int score = 0;
		while(!screenObj.Quit()){

			screenObj.PrintScore(score);
			if (snakeObj.FatalCollision()){
				move((height-2)/2, (width-2/2));
				printw("GAME OVER...");
			}
			else{

				snakeObj.checkEatingSuccess(foodObj, screenObj);
				if (snakeObj.getEatingSuccess())
					score++;
				screenObj.PrintScore(score);
				screenObj.PositionFood(foodObj);
				screenObj.MoveAndDrawSnake(snakeObj);
				if(snakeObj.getEatingSuccess()){
					foodObj.UpdateFood(height, width, snakeObj);
					snakeObj.setEatingSuccess(false);
				}

				usleep(500000);

			}
		}while(AskUserToPlayAgain() == 'y');
	}
	return 0;
}

#ifndef __SCREEN_H
#define __SCREEN_H

#include <ncurses.h>
#include <string>

class Snake;
class Food;
class ScreenObject{

	private:
		int height;
		int width;
	
		const char edgechar = (char)219;
		const char foodchar = '*';
		const char snakechar = 'x';
		bool quitGame = false;
	
	public:
		ScreenObject();
		~ScreenObject();
		int get_height() const { return height; }
		int get_width() const { return width; }
		void DrawWindow() const;
		void PositionFood(Food& Food) const;
		void InitDrawSnake(Snake& snakeObj) const;
		void MoveAndDrawSnake(Snake& snakeObj);
		bool EatingSuccess(Food& food, Snake& snakeObj) const;
		void PrintScore(const int score) const;
		void PrintMessage(const std::string& score) const;
		bool Quit() const {return quitGame;}
};
#endif

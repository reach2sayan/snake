#include "snake.hpp"
#include "food.hpp"
#include "screenobject.hpp"

ScreenObject::ScreenObject(){
	initscr();
	nodelay(stdscr, true);
	keypad(stdscr,true);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, this->height, this->width);
}

ScreenObject::~ScreenObject(){
	nodelay(stdscr,false);
	getch();
	endwin();
}

void ScreenObject::DrawWindow() const{

	int i = 0;
	for (i = 0; i < width; i++) // draws top
	{
		move(0, i);
		addch(edgechar);
	}

	for (i = 0; i < width; i++) // draws bottom
	{
		move(height-2, i);
		addch(edgechar);
	}

	for (i = 0; i < height-1; i++) // draws left side
	{
		move(i, 0);
		addch(edgechar);
	}

	for (i = 0; i < height-1; i++) // draws right side
	{
		move(i, width-1);
		addch(edgechar);
	}
	return;
}

void ScreenObject::InitDrawSnake(Snake& snakeObj) const{
	
	std::vector<Position>& snake = snakeObj.getSnake();
	for (int i = 0; i < snake.size(); i++){
		move(snake[i].getY(), snake[i].getX());
		addch(snakechar);
	}
	return;
}

void ScreenObject::MoveAndDrawSnake(Snake& snakeObj) {

	int KeyPressed = getch();
	std::vector<Position>& snake = snakeObj.getSnake();

	switch(KeyPressed)
	{
		case KEY_LEFT:
			if (snakeObj.getDirection() != RIGHT)
				snakeObj.setDirection(LEFT);
			break;
		case KEY_RIGHT:
			if (snakeObj.getDirection() != LEFT)
				snakeObj.setDirection(RIGHT);
			break;
		case KEY_UP:
			if (snakeObj.getDirection() != BOTTOM)
				snakeObj.setDirection(TOP);
			break;
		case KEY_DOWN:
			if (snakeObj.getDirection() != TOP)
				snakeObj.setDirection(BOTTOM);
		case KEY_BACKSPACE:
			quitGame = true;
			break;
	}

	if (!snakeObj.getEatingSuccess())
	{
		move(snake[snake.size()-1].getY(), snake[snake.size()-1].getX()); // moves at the end of the tail
		printw(" ");
		refresh();
		snake.pop_back();
	}

	// the snake moves and we add an extra character at the beginning of the vector
	// add a head and initialise new coordinates for CharPosition according to the direction input
	if (snakeObj.getDirection() == LEFT)
		snake.insert(snake.begin(), Position(snake[0].getX()-1, snake[0].getY(), height, width));

	else if (snakeObj.getDirection() == RIGHT)
		snake.insert(snake.begin(), Position(snake[0].getX()+1, snake[0].getY(), height, width));

	else if (snakeObj.getDirection() == TOP)
		snake.insert(snake.begin(), Position(snake[0].getX(), snake[0].getY()-1, height, width)); 

	else if (snakeObj.getDirection() == BOTTOM)
		snake.insert(snake.begin(), Position(snake[0].getX(), snake[0].getY()+1, height, width));

	// move to the new CharPosition coordinates
	move(snake[0].getY(), snake[0].getX());
	addch(snakechar); // add a new head
	refresh();
	return;
}

void ScreenObject::PositionFood(Food& foodObj) const {
	Position food = foodObj.GetFood();
	move(food.getY(), food.getY());
	addch(foodchar);
	refresh();
}


void ScreenObject::PrintScore(const int score) const {
	move(height-1, 0);
	printw("Score: %d", score);
	return;
}

/*
bool ScreenObject::EatingSuccess(Food& foodObj, Snake& snakeObj) const {

	Position snakehead = snakeObj.getSnake()[0];
	Position foodpos = foodObj.GetFood();
	if (snakehead.getX() == foodpos.getX() && snakehead.getY() == foodpos.getY()){
		snakeObj.setEatingSuccess(true);
		foodObj.UpdateFood(foodpos.get_height(),foodpos.get_width(), snakeObj);
	}
	else
		snakeObj.setEatingSuccess(false);
	return snakeObj.getEatingSuccess();
}*/



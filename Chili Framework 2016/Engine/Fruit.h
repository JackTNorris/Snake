#pragma once
#include "Snake.h"
#include "Board.h"
#include "Location.h"
#include <time.h>
#include <cstdlib>
class Fruit {
public:
	Fruit(const Location& startSpot);
	void Spawn(Board& brd);
	bool CheckIfEaten(const Location& snekLocation);
	void CheckPosition(const Location& segment);	//making sure fruit doesn't spawn in the snake;
private:
	void randomizeLocation(Location& spot, const Board& brd);
	bool inSegment = false;
	Location loc;
	Color c = Colors::Red;
	bool isEaten = false;
};
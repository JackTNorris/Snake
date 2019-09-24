#include "Fruit.h"

#include <iostream>
#include <cstdlib>
using namespace std;
Fruit::Fruit(const Location & in_loc)
{
	loc = in_loc;
}

void Fruit::Spawn(Board & brd)
{
	if (isEaten == true) {
		randomizeLocation(loc, brd);
		while (inSegment == true) {
			randomizeLocation(loc, brd);
		}
		isEaten = false;
	}

	brd.DrawCell(loc, c);
}

bool Fruit::CheckIfEaten(const Location & snekLocation)
{
	if (snekLocation.x == loc.x && snekLocation.y == loc.y) {
		isEaten = true;
		return true;
	}
	else {
		return false;
	}
	
}

void Fruit::CheckPosition(const Location & segment)
{
	if (segment.x == loc.x && segment.y == loc.y) {
		inSegment = true;
	}
	else {
		inSegment = false;
	}
}





void Fruit::randomizeLocation(Location & spot, const Board & brd)
{
	srand(time(NULL));
	randomizer:
	int x = 1 + rand() % brd.GetGridWidth() - 1;
	int y = 1 + rand() % brd.GetGridHeight() - 1;
	if (x == 0 || x == brd.GetGridWidth() - 1 || y == 0 || y == brd.GetGridHeight() - 1) {
		goto randomizer;
	}
	spot = { x, y };

}

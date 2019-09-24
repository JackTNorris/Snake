#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location & loc)
{
	segments[0].InitHead(loc);
}



void Snake::MoveBy(const Location& delta_loc) {

	for (int i = nSegments - 1; i > 0; --i) {
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}



void Snake::Grow() {
	if (nSegments < nSegmentsMax) {
		
		
		segments[nSegments].InitBody();
		++nSegments;
	}
}




void Snake::Draw(Board & brd) const{
	for (int i = 0; i < nSegments; ++i) {
		segments[i].Draw(brd);
	}
}

Location Snake::GetHeadLocation()
{
	return segments[0].GetLocation();
}

void Snake::Reset(const Location& startLocation)
{
	segments[0].setLocation(startLocation);
	alive = true;
	hitWall = false;
	hitSelf = false;
	nSegments = 1;
}

void Snake::Update(const Board & brd)
{
	if (segments[0].GetLocation().x > brd.GetGridWidth() - 1 || segments[0].GetLocation().x < 1 || segments[0].GetLocation().y > brd.GetGridHeight() - 1 || segments[0].GetLocation().y < 1) {
		hitWall = true;
	}
	for (int i = 1; i <= nSegments; i++) {
		if (segments[0].GetLocation().x == segments[i].GetLocation().x && segments[0].GetLocation().y == segments[i].GetLocation().y) {
			hitSelf = true;
		}
	}

	if (hitSelf || hitWall) {
		alive = false;
	}
}






void Snake::Segment::InitHead(const Location & in_loc)	//init means initialize
{
	loc = in_loc;			//the x and the y's are both assigned
	c = Snake::headColor;	//segment is inside snake class, so I can do this
}





void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}




void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}




void Snake::Segment::MoveBy(const Location & delta_loc)	//delta location refers to the change in the x and the change in the y, that's why I can use the struct location
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake :: Segment::Draw(Board & brd) const {
	brd.DrawCell(loc, c);
}

Location Snake::Segment::GetLocation()
{
	return loc;
}

void Snake::Segment::setLocation(const Location & newLocation)
{
	loc = newLocation;
}

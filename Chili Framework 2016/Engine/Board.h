#pragma once
#include "Graphics.h"
#include "Location.h"
#include "Colors.h"
#include <cstdlib>
class Board {
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetGridWidth() const;
	int GetGridHeight() const;
	int GetDimension() const;
private:
	static constexpr int dimension = 20;
		
	static constexpr int width = Graphics::ScreenWidth/dimension;
	static constexpr int height = Graphics::ScreenHeight/dimension;
	Graphics& gfx;
};
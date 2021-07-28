#pragma once
#include "Pixel.h"

struct Grid;

class Cell
{
	Pixel* pixel;
	ivec2 position;
	Grid* grid;



public:
	Cell(Grid* grid, ivec2 position);

	Type type();

	Pixel* pixelAt(ivec2 newPos);

	Cell& cellAt(ivec2 newPos);

	bool moveTo(ivec2 newPos);

	vec2 normalAt(vec2 direction, const vec2& pixelPos);

	ivec2 getPosition();

	void setGrid(Grid* grid);

	void setPixel(Pixel* pixel);

	Pixel* getPixel();

	vec2 getPixelPosition();

private:
	Cell& getDirectionVertical(int x, int y, int dy);
};


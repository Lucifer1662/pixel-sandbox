#include "Grid.h"
#include "Cell.h"

Grid::Grid(size_t size) : size(size) {
	this->reserve(size * size);
	for (size_t x = 0; x < size; x++)
		for (size_t y = 0; y < size; y++) {
			{
				this->push_back(Cell(this, ivec2(x, y)));
			}
		}
}

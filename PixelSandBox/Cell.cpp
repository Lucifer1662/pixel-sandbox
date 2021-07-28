#include "Cell.h"
#include "Grid.h"


Cell::Cell(Grid* grid, ivec2 position) : grid(grid), position(position), pixel(nullptr) {}

Type Cell::type() {
	if (pixel == nullptr)
		return Empty;
	else
		return pixel->getType();
}

Pixel* Cell::pixelAt(ivec2 newPos) {
	return grid->at(newPos).pixel;
}

Cell& Cell::cellAt(ivec2 newPos) {
	return grid->at(newPos);
}

bool Cell::moveTo(ivec2 newPos) {
	Cell& cell = cellAt(newPos);
	if (cell.pixel == nullptr) {
		pixel->setCell(&cell);
		cell.setPixel(this->pixel);
		this->setPixel(nullptr);
		return true;
	}
	else {
		return false;
	}
}


Cell& Cell::getDirectionVertical(int x, int y, int dy) {
	if (dy == 0) {
		auto above = grid->at(x, y + 1);
		if (above.type() != Empty) {
			return above;
		}

	}
	else {
		return grid->at(x, y + dy);
	}
}


vec2 Cell::normalAt(vec2 direction, const vec2& pixelPos) {
	int x = position.x;
	int y = position.y;




	/*if (x == 0 && direction.x <= 0) {
		if (y == 0 && direction.y <= 0) {
			return glm::normalize(vec2(1, 1));
		}
		else if (y == size - 1 && direction.y >= 0) {
			return glm::normalize(vec2(1, -1));
		}
		else {
			return vec2(-1, 0);
		}
	}
	else if (x == size - 1 && direction.x >= 0) {
		if (y == 0 && direction.y <= 0) {
			return glm::normalize(vec2(-1, 1));
		}
		else if (y == size - 1 && direction.y >= 0) {
			return glm::normalize(vec2(-1, -1));
		}
		else {
			return vec2(1, 0);
		}
	}
	else {
		if (y == 0 && direction.y <= 0) {
			return glm::normalize(vec2(0, 1));
		}
		else if (y == size - 1 && direction.y >= 0) {
			return glm::normalize(vec2(0, -1));
		}
	}*/

	int dx = 0;
	if (direction.x < 0) {
		dx = -1;
	}
	else if (direction.x > 0) {
		dx = 1;
	}

	int dy = 0;
	if (direction.y < 0) {
		dy = -1;
	}
	else if (direction.y > 0) {
		dy = 1;
	}





	int nx = x + dx;
	int ny = y + dy;

	auto pos = (nx < 0 || nx >= size || ny < 0 || ny >= size) ? vec2(nx+0.5f,ny+0.5f) : grid->at(nx, ny).getPixelPosition();
	return glm::normalize(pixelPos - pos);



	bool horizontal_empty = (nx < 0 || nx >= size) ? false : grid->at(nx, y).type() == Empty;
	bool vertical_empty = (ny < 0 || ny >= size) ? false : grid->at(x, ny).type() == Empty;

	//auto horizontal = (nx < 0 || nx >= size) ? Cell(nullptr, { nx,y }) : grid->at(nx, y);
	//auto vertical = (ny < 0 || ny >= size) ? Cell(nullptr, { y,ny }) : grid->at(x, ny);

	if (dx == 0) {
		int lx = x - 1;
		int rx = x + 1;

		bool left_empty = (lx < 0 || lx >= size) ? false : grid->at(lx, y).type() == Empty;
		bool right_empty = (rx < 0 || rx >= size) ? false : grid->at(rx, y).type() == Empty;

		if (left_empty == right_empty) {
			if (left_empty) {
				return glm::normalize(vec2(pixelPos.x, -dy));
			}
			else {
				return glm::normalize(vec2(0, -dy));
			}
		}
		else {
			auto horizontal = left_empty == false ? grid->at(lx,y) : grid->at(rx, y);
			auto normal = vec2(grid->at(nx, y).getPixelPosition()) + vec2(scale, scale) - vec2(grid->at(x, ny).getPixelPosition());
			normal.x = -normal.x;
			return glm::normalize(normal);
		}
	}

	if (dy == 0) {
		int dy = y - 1;
		int uy = y + 1;

		bool down_empty = (dy < 0 || dy >= size) ? false : grid->at(x, dy).type() == Empty;
		bool up_empty = (uy < 0 || uy >= size) ? false : grid->at(x, uy).type() == Empty;

		if (up_empty == down_empty) {
			return glm::normalize(vec2(-dx, pixelPos.y));
		}
		else {
			auto vertical = up_empty == false ? grid->at(x,uy) : grid->at(x, dy);
			auto normal = vec2(vertical.getPixelPosition()) + vec2(scale, scale) - vec2(grid->at(nx, y).getPixelPosition());
			normal.x = -normal.x;
			return glm::normalize(normal);
		}
	}




	if (vertical_empty) {
		if (horizontal_empty) {
			return direction;
		}
		else {
			return vec2(-dx, 0);
		}
	}
	else {
		if (horizontal_empty) {
			return vec2(0, -dy);
		}
		else {
			auto normal = vec2(grid->at(nx, y).getPixelPosition()) + vec2(scale, scale) - vec2(grid->at(x, ny).getPixelPosition());
			normal.x = -normal.x;
			return glm::normalize(normal);
		}
	}




}

ivec2 Cell::getPosition() { return position; }

void Cell::setGrid(Grid* grid) {
	this->grid = grid;
}

void Cell::setPixel(Pixel* pixel)
{
	this->pixel = pixel;
}

Pixel* Cell::getPixel() { return pixel; }

vec2 Cell::getPixelPosition()
{
	if (pixel == nullptr) {
		return vec2(getPosition()) + half_size_vec;
	}
	else {
		return  vec2(position) + pixel->getPosition() + half_size_vec;
	}
}

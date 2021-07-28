#pragma once
#include <vector>
#include "Cell.h"
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include "glm/glm.hpp"
#include "Constants.h"
using vec2 = glm::vec2;
using vec3 = glm::vec3;
using ivec2 = glm::ivec2;

class Grid : public std::vector<Cell>
{
	size_t size;
public:
	Grid(size_t size);

	Cell& at(ivec2 pos) {
		return at(pos.x, pos.y);
	}

	Cell& at(int x, int y) {
		return this->operator[](y + size * x);
	}	
};


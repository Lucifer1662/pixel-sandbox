#pragma once
#include "glm/vec3.hpp"
#include "glm/vec2.hpp"
#include "glm/glm.hpp"
#include "Constants.h"
using vec2 = glm::vec2;
using vec3 = glm::vec3;
using ivec2 = glm::ivec2;

struct Cell;

enum Type {
	Dirt,
	Fire,
	Rock,
	Water,
	Empty
};

class Pixel
{
	Type type;
	vec3 colour;
	vec2 position;
	vec2 velocity;
	vec2 acceleration;
	float restitution;
	float mass; 
	Cell* cell;
	Cell* prevCell = nullptr;

public:

	Pixel(Cell* cell, Type type, vec2 position = vec2(), vec2 velocity = vec2(), 
		vec2 acceleration = vec2(), float restitution = 0.3, float mass = 1, vec3 colour = vec3());

	virtual void update();

	Type getType() { return type; }
	void setCell(Cell* cell) { prevCell = this->cell; this->cell = cell; }
	vec2 getPosition() { return position; }
	Cell* getCell() { return cell; }
	Cell* getPrevCell() { return prevCell; }
};


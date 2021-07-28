#include "Pixel.h"
#include "Cell.h"
#include <algorithm>

Pixel::Pixel(Cell* cell, Type type, vec2 position, vec2 velocity, vec2 acceleration, float restitution, float mass, vec3 colour)
	: type(type), colour(colour), position(position), velocity(velocity),
	acceleration(acceleration), restitution(restitution), mass(mass), cell(cell)
{

	cell->setPixel(this);
}

void Pixel::update() {
	vec2 global_position = cell->getPosition();
	acceleration = vec2(0, -0.098f);

	velocity += acceleration * dt;
	position += velocity * dt;

	//f = ma
	if (position.x > half_scale || position.y > half_scale || position.x < -half_scale || position.y < -half_scale) {
		position = glm::clamp(position, vec2(-0.9, -0.9), vec2(0.9, 0.9));
		vec2 newPos = global_position + position + half_size_vec;



		if (newPos.x >= 0 && newPos.y >= 0 && newPos.y < size && newPos.x < size) {

			auto newPixel = cell->pixelAt(newPos);
			if (newPixel == nullptr) {
				cell->moveTo(newPos);
			}
			else {
				//apply a force back
				vec2 rv = velocity - newPixel->velocity;

				if (type == Water) {
					int  w = 0;
				}

				if (cell->getPosition().y == 0) {
					int w = 0;
				}

				vec2 normal = cell->normalAt(glm::normalize(velocity), newPos);
				// Calculate relative velocity in terms of the normal direction
				float velAlongNormal = glm::dot(rv, normal);

				// Do not resolve if velocities are separating
				if (velAlongNormal > 0)
					return;

				// Calculate restitution
				float e = std::min(restitution, newPixel->restitution);

				// Calculate impulse scalar
				float j = -(1 + e) * velAlongNormal;
				//j /= 1 / mass + 1 / mass;

				// Apply impulse
				vec2 impulse = j * normal;
				velocity += impulse;
				newPixel->velocity -= impulse;
				if (impulse.y > 10) {
					int wwww = 0;
				}

				if (position.x < -half_scale) position.x = -half_scale;
				if (position.x > half_scale) position.x = half_scale;
				if (position.y < -half_scale) position.y = -half_scale;
				if (position.y > half_scale) position.y = half_scale;

			}
		}
		else {
			//apply a force back
			vec2 rv = velocity;

			//vec2 newPosss = global_position + glm::clamp(position, vec2(-0.5, -0.5), vec2(0.5, 0.5)) + half_size_vec;
			//vec2 normal = cell->normalAt(glm::normalize(velocity), newPosss);
			vec2 normal = vec2(0,-1);
			if (newPos.x < 0) {
				normal = vec2(1, 0);
			}
			else if (newPos.x >= size) {
				normal = vec2(-1, 0);
			}
			else if (newPos.y < 0) {
				normal = vec2(0, 1);
			}
		

			// Calculate relative velocity in terms of the normal direction
			float velAlongNormal = glm::dot(rv, normal);

			if (velAlongNormal > 0)
				return;


			// Calculate restitution
			float e = restitution;

			// Calculate impulse scalar
			float j = -(1 + e) * velAlongNormal;

			// Apply impulse
			vec2 impulse = j * normal;
			velocity += impulse;

			if (position.x < -half_scale) position.x = -half_scale;
			if (position.x > half_scale) position.x = half_scale;
			if (position.y < -half_scale) position.y = -half_scale;
			if (position.y > half_scale) position.y = half_scale;
		}
	}
}

#pragma once


#include "glm/vec3.hpp"
#include "glm/vec2.hpp"


using vec2 = glm::vec2;
using vec3 = glm::vec3;
using ivec2 = glm::ivec2;

const float dt = 0.01f;
const float scale = 1.0f;
const float half_scale = scale / 2;
constexpr const size_t size = 900/5;
const vec2 half_size_vec = vec2(scale / 2, scale / 2);


#pragma once
#include "vector2.h"

class AABB;

struct Hit
{
	tove::Vector2 normal;
	tove::Vector2 pos;

	Hit (float n_x, float n_y, float x, float y) : normal{ n_x, n_y }, pos{ x, y }
	{
	}
};

Hit intersect_pos (const AABB& a, const AABB& ball);
bool aabb_intersect (const AABB& a, const AABB& b);
bool intersect_x (const AABB& a, const AABB& ball);
bool intersect_y (const AABB& a, const AABB& ball);
tove::Vector2 get_closest_point (const  AABB AABB, const tove::Vector2 POINT);

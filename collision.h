#pragma once
#include "entity.h"


class Collision
{
public:
	void CheckCollision(Entity* rel, Entity* thing);
	bool IsOverlap(Entity* rel, Entity* thing);
	void CheckEdge(Entity* rel, Entity* thing);
};


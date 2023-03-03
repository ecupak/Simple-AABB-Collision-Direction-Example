#include "collision.h"
#include <iostream>


// rel = relative. everything will be in relation to that entity's position.
// thing is the other object we are checking collision against.
void Collision::CheckCollision(Entity* rel, Entity* thing)
{	
	if (IsOverlap(rel, thing))
	{
		rel->color = 0xff0000;
		CheckEdge(rel, thing);
	}
	else
	{
		rel->color = 0x00ff00;
	}
}


// Determine if they are overlapping at all.
bool Collision::IsOverlap(Entity* rel, Entity* thing)
{
	return (rel->m_current_location.bottom >= thing->m_current_location.top
		&& rel->m_current_location.top <= thing->m_current_location.bottom
		&& rel->m_current_location.left <= thing->m_current_location.right
		&& rel->m_current_location.right >= thing->m_current_location.left);
}


// For each edge, check if there was no overlap previous frame but if there is overlap now.
// That is the edge of relative-entity that has just crossed into thing-entity.
void Collision::CheckEdge(Entity* rel, Entity* thing)
{
	// thing (enemy) does not move in this example. but should also use previous position for the first check.
	if (rel->m_previous_location.bottom < thing->m_current_location.top // Reverse check of IsOverlap (no overlap) using previous position.
		&& rel->m_current_location.bottom >= thing->m_current_location.top) // Same check as in IsOverlap
	{
		std::cout << "Hit the top.\n\n";
	}

	if (rel->m_previous_location.top > thing->m_current_location.bottom
		&& rel->m_current_location.top <= thing->m_current_location.bottom)
	{
		std::cout << "Hit the bottom.\n\n";
	}

	if (rel->m_previous_location.left > thing->m_current_location.right
		&& rel->m_current_location.left <= thing->m_current_location.right)
	{
		std::cout << "Hit the right.\n\n";
	}

	if (rel->m_previous_location.right < thing->m_current_location.left
		&& rel->m_current_location.right >= thing->m_current_location.left)
	{
		std::cout << "Hit the left.\n\n";
	}
}
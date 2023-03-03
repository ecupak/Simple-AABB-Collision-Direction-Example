#include "collision.h"
#include <iostream>


// First see if there is a collision, then see which edge caused it.
void Collision::CheckCollision(Entity* player, Entity* enemy)
{	
	if (IsOverlap(player, enemy))
	{
		player->color = 0xff0000;
		CheckEdge(player, enemy);
	}
	else
	{
		player->color = 0x00ff00;
	}
}


// Determine if they are overlapping at all.
bool Collision::IsOverlap(Entity* player, Entity* enemy)
{
	return (player->m_current_location.bottom >= enemy->m_current_location.top
		&& player->m_current_location.top <= enemy->m_current_location.bottom
		&& player->m_current_location.left <= enemy->m_current_location.right
		&& player->m_current_location.right >= enemy->m_current_location.left);
}


// For each edge, check if there was no overlap previous frame but if there is overlap now.
// That is the edge of player that has just crossed into enemy.
void Collision::CheckEdge(Entity* player, Entity* enemy)
{
	// thing (enemy) does not move in this example. but should also use previous position for the first check.
	if (player->m_previous_location.bottom < enemy->m_current_location.top // Reverse check of IsOverlap (no overlap) using previous position.
		&& player->m_current_location.bottom >= enemy->m_current_location.top) // Same check as in IsOverlap
	{
		std::cout << "Player bottom made contact.\n\n";
		return;
	}

	if (player->m_previous_location.top > enemy->m_current_location.bottom
		&& player->m_current_location.top <= enemy->m_current_location.bottom)
	{
		std::cout << "Player top made contact.\n\n";
		return;
	}

	if (player->m_previous_location.left > enemy->m_current_location.right
		&& player->m_current_location.left <= enemy->m_current_location.right)
	{
		std::cout << "Player left made contact.\n\n";
		return;
	}

	if (player->m_previous_location.right < enemy->m_current_location.left
		&& player->m_current_location.right >= enemy->m_current_location.left)
	{
		std::cout << "Player right made contact.\n\n";
		return;
	}
}
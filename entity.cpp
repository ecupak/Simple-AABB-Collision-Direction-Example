#include "entity.h"

Entity::Entity() {}


// Store current position as previous position before making any changes.
void Entity::Update(int new_x, int new_y)
{
	m_previous_location = m_current_location;

	UpdateBox(new_x, new_y);
}


void Entity::UpdateBox(int x, int y)
{
	m_current_location.top = y;
	m_current_location.left = x;
	m_current_location.right = x + m_size.width;
	m_current_location.bottom = y + m_size.height;
}


void Entity::Draw(Tmpl8::Surface* screen)
{
	CollisionBox draw_box{ GetDrawBox() };

	screen->Box(
		draw_box.left, draw_box.top,
		draw_box.right, draw_box.bottom, 
		color
	);
}


// Puts box in center of mouse.
CollisionBox Entity::GetDrawBox()
{
	return CollisionBox
	{
		m_current_location.top - m_offset.height,
		m_current_location.bottom - m_offset.height,
		m_current_location.left - m_offset.width,
		m_current_location.right - m_offset.width
	};
}
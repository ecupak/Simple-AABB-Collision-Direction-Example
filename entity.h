#pragma once
#include "template.h"
#include "surface.h"


struct CollisionBox
{
	CollisionBox(int t = 0, int b = 0, int l = 0, int r = 0)
		: top{ t }
		, bottom{ b }
		, left{ l }
		, right{ r }
	{	}

	int top;
	int bottom;
	int left;
	int right;
};


struct Size
{
	int height;
	int width;
};


class Entity
{
public:
	Entity();	
	void Update(int new_x, int new_y);
	void Draw(Tmpl8::Surface* screen);

	void UpdateBox(int x, int y);

	CollisionBox m_previous_location;
	CollisionBox m_current_location;

	int color{ 0x00ff00 };

private:	
	CollisionBox GetDrawBox();

	Size m_size{ 50, 50 };
	Size m_offset{ m_size.height / 2, m_size.width/ 2 };
};


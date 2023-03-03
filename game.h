#pragma once

#include "template.h"
#include "surface.h"
#include "entity.h"
#include "collision.h"


namespace Tmpl8 {

class Game
{
public:
	Game(Surface* screen);
	void Init();
	void Shutdown();	
	void Tick( float deltaTime );
	void MouseUp(int button) {};
	void MouseDown(int button);
	void MouseMove(int x, int y);
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }

private:
	// ATTRIBUTES
	Surface* m_screen{ nullptr };
	Entity player;
	Entity enemy;
	Collision collision;
	
	int mouse_x{ 0 };
	int mouse_y{ 0 };
};

};
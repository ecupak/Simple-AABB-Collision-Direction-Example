#include "game.h"


namespace Tmpl8
{
	// -----------------------------------------------------------
	// Constructor
	// -----------------------------------------------------------
	Game::Game(Surface* screen)
		: m_screen{ screen }
	{	}

	// -----------------------------------------------------------
	// Mouse events
	// -----------------------------------------------------------
	void Game::MouseDown(int button){}


	void Game::MouseMove(int x, int y) 
	{ 
		mouse_x = x; 
		mouse_y = y; 
	}

	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	void Game::Init()	
	{
		// Place enemy and set color once. It doesn't move.
		enemy.UpdateBox(300, 200);
		enemy.color = 0x00ffff;
	}

	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		deltaTime *= 0.001; // unused in this example.
		m_screen->Clear(0);

		player.Update(mouse_x, mouse_y);

		collision.CheckCollision(&player, &enemy);

		enemy.Draw(m_screen);
		player.Draw(m_screen);		
	}
};
#pragma once

#include "Player.h"
#include "Alien.h"

class Game
{
public: 
	Game();
	~Game();

	void run();
	void processEvents();
	void update();
	void render();

private:

	Player m_player;
	Alien m_alien;
	sf::RenderWindow m_window;
};


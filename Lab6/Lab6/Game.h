#pragma once
#include <SFML/Graphics.hpp>
#include "tileMap.h"
class Game
{
public:

	Game();
	void run();
	void render();
	void update();
private:
	sf::RenderWindow m_window; 
	TileMap m_tileMap;
};
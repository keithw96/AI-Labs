#pragma once
#include <vector>
#include <list>
#include <iostream>
#include "Tile.h"
class TileMap
{
public:
	void initialise();
	void update(sf::RenderWindow &window);
	void render(sf::RenderWindow &window);
	void processEvents(sf::RenderWindow &window);
	void setCosts(int posX, int posY);
	void createPath(Tile m_startTile);
protected:
	static const int m_gridSize = 50;

	Tile* m_tileArray[m_gridSize][m_gridSize];
	sf::Vector2i m_mousePos;

	int m_tilePosX;
	int m_tilePosY;

	bool m_goalSet;
	bool m_startSet;
	int m_tileSize;

	Tile* m_start;
	Tile* m_goal;

private:

};
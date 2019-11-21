#pragma once
#include <SFML/Graphics.hpp>

enum State
{
	NONE,
	START,
	GOAL,
	OBSTACLE,
	PATH
};

class Tile
{
public:
	Tile(int x, int y, int tileSize);

	void render(sf::RenderWindow & window);
	void setState(State state);

	void setRotation(float rot);
	void setCost(int cost);
	void setPrevious(int x, int y);
	int getX();
	int getY();
	int getCost();

	State getState();
	sf::Vector2f m_position;
	int m_cost;
	float m_rotation;
	std::pair<int, int> m_previous;

	sf::RectangleShape m_tile;
	sf::RectangleShape vector;
	int m_tileSize;
	
	State m_currentState;
	
	
private:

};
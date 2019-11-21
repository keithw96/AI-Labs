#include "Tile.h"

Tile::Tile(int x, int y, int tileSize)
{
	m_position.x = x;
	m_position.y = y;

	m_tileSize = tileSize;

	m_currentState = NONE;
	m_cost = 0;
	m_rotation = 0;
	vector.setSize(sf::Vector2f(25, 1));
	vector.setFillColor(sf::Color::Red);
	vector.setOutlineColor(sf::Color::Red);
	vector.setOutlineThickness(1);
	vector.setPosition(m_position.x + (m_tileSize / 2), m_position.y + (m_tileSize / 2));
	vector.setRotation(m_rotation);
}

void Tile::render(sf::RenderWindow & window)
{
	m_tile.setSize(sf::Vector2f(m_tileSize, m_tileSize));
	m_tile.setOutlineColor(sf::Color::Black);

	switch (m_currentState)
	{
	case START:
		m_tile.setFillColor(sf::Color::Green);
		break;
	case GOAL:
		m_tile.setFillColor(sf::Color::Red);
		break;
	case OBSTACLE:
		m_tile.setFillColor(sf::Color::Black);
		break;
	case PATH:
		m_tile.setFillColor(sf::Color::White);
		break;
	case NONE:
		m_tile.setFillColor(sf::Color::Blue);
		break;
	default:
		break;
	}
	m_tile.setOutlineThickness(5);
	m_tile.setPosition(m_position);

	window.draw(m_tile);
	if (m_currentState == NONE)
	{
		window.draw(vector);
	}
}

void Tile::setState(State state)
{
	m_currentState = state;
}

State Tile::getState()
{
	return m_currentState;
}

void Tile::setRotation(float rot)
{
	m_rotation = rot;
	vector.setRotation(m_rotation);
}

void Tile::setCost(int cost)
{
	m_cost = cost;
}
int Tile::getCost()
{
	return m_cost;
}

void Tile::setPrevious(int x, int y) {

	m_previous = std::make_pair(x, y);
}

int Tile::getX()
{
	return m_position.x;
}

int Tile::getY()
{
	return m_position.y;
}
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */

class SeekAlien
{
public:
	void initialise();
	void movement(sf::Vector2f targetPosition);
	void update(sf::Vector2f targetPosition);
	void render(sf::RenderWindow& window);
	int getNewOrientation(int rotation, sf::Vector2f velocity);

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Text m_text;
	sf::Font m_font;
	int m_rotation;

	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

	const float m_maxSpeed = 10.0f;
};


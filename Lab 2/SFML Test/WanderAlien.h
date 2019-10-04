#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */

class WanderAlien
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
	sf::Font m_font;
	sf::Text m_text;

	int m_rotation;

	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

	const float m_maxSpeed = 5.0f;
	const float m_maxRotation = 0.5f;
};


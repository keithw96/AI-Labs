#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#define M_PI           3.14159265358979323846  /* pi */

class ArriveAlien
{
public:
	void initialise(float maxSpeed, sf::Vector2f position);
	void movement(sf::Vector2f targetPosition);
	void playerConeIntersect(sf::Vector2f playerPosition, sf::FloatRect playerRect);
	void update(sf::Vector2f targetPosition, sf::FloatRect playerRect);
	void render(sf::RenderWindow& window);
	int getNewOrientation(int rotation, sf::Vector2f velocity);

private:
	sf::Sprite m_sprite;
	sf::Sprite m_coneSprite;
	sf::Texture m_redCone;
	sf::Texture m_greenCone;
	sf::Texture m_texture;
	sf::Font m_font;
	sf::Text m_text;

	int m_rotation;

	sf::Vector2f m_position;
	sf::Vector2f m_velocity;

	float m_timeToTarget = 0.25f;
	float m_maxSpeed;
	float m_radius = 125.0f;
};


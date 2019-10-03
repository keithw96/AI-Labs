#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */

class PursueAlien
{
public:
	void initialise();
	void movement(sf::Vector2f targetPosition, sf::Vector2f targetVelocity);
	void seekTarget(sf::Vector2f targetPosition);
	void persue(sf::Vector2f targetPosition, sf::Vector2f targetVelocity);
	void update(sf::Vector2f targetPosition, sf::Vector2f targetVelocity);
	void render(sf::RenderWindow& window);
	int getNewOrientation(int rotation, sf::Vector2f velocity);

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	int m_rotation;

	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_newTarget;

	const float m_maxSpeed = 10.0f;
	const float m_maxTimePrediction = 1.1f;
	float timePrediction;
};

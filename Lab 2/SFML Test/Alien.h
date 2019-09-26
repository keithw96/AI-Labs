#pragma once

#include <SFML/Graphics.hpp>

struct Kinematic
{
	sf::Vector2f position;
	sf::Vector2f velocity;
	float orientation; 
	float rotation;
};

class Alien
{
public:
	void initialise();
	void movement();
	void update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
	void getNewOrientation(int rotation, sf::Vector2f velocity);

private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	int m_rotation;

	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;

	
	int m_speed = 1;
};


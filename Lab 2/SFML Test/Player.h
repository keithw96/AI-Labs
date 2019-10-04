#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
class Player
{
public:
	void initialise();
	void boundaryFlip(sf::RenderWindow & window);
	void movement();
	void update(sf::RenderWindow & window);
	void render(sf::RenderWindow & window);
	sf::Vector2f getPosition();
	sf::Vector2f getVelocity();
	sf::FloatRect getTextureRect();
private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;

	int m_rotation;

	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
};				
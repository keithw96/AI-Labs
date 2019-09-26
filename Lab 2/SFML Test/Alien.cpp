#include "Alien.h"

void Alien::initialise()
{
	m_pos = sf::Vector2f(200, 200);
	m_velocity = sf::Vector2f(10.0f, 10.0f);
	m_rotation = 0;

	m_texture.loadFromFile("Resources/Alien1.png");
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_pos.x, m_pos.y);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
}

void Alien::update(sf::RenderWindow & window)
{

}

void Alien::movement()
{

}

void Alien::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

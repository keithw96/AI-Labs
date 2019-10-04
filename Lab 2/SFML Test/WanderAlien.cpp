#include "WanderAlien.h"

void WanderAlien::initialise()
{
	m_position = sf::Vector2f(200, 1000);
	m_velocity = sf::Vector2f(10.0f, 0.0f);
	m_rotation = 0;

	m_texture.loadFromFile("Resources/Alien1.png");
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position.x, m_position.y);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);

	m_font.loadFromFile("arial.ttf");
	m_text = sf::Text("Wanderer", m_font);
	m_text.setCharacterSize(40);
	m_text.setStyle(sf::Text::Bold);
	m_text.setFillColor(sf::Color::Yellow);
	m_text.setOrigin(m_sprite.getOrigin());

}

void WanderAlien::update(sf::Vector2f targetPosition)
{
	movement(targetPosition);
}

void WanderAlien::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(m_text);
}

int WanderAlien::getNewOrientation(int rotation, sf::Vector2f velocity)
{
	if (std::sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y)) > 0)
	{
		int newRotation = (atan2(-velocity.x, velocity.y)) * (180 / M_PI);

		return newRotation;
	}
	else
	{
		return m_rotation;
	}
}

void WanderAlien::movement(sf::Vector2f targetPosition)
{
	float magnitutde = std::sqrt((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y));
	m_velocity = sf::Vector2f(m_velocity.x / magnitutde, m_velocity.y / magnitutde);
	
	//m_rotation = getNewOrientation(m_rotation, m_velocity);

	int random = (rand() % 3) -1;

	m_rotation = m_rotation * (180 / M_PI);

	m_rotation = m_rotation + m_maxRotation * random;

	m_velocity = sf::Vector2f(sin(m_rotation), -cos(m_rotation) * m_maxSpeed);

	m_position += m_velocity;

	m_sprite.setPosition(m_position);

	m_rotation = m_rotation / (180 / M_PI);

	m_sprite.setRotation(m_rotation);
	m_text.setPosition(m_position);
}
#include "SeekAlien.h"

void SeekAlien::initialise()
{
	m_position = sf::Vector2f(200, 200);
	m_velocity = sf::Vector2f(10.0f, 10.0f);
	m_rotation = 0;

	m_texture.loadFromFile("Resources/Alien1.png");
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position.x, m_position.y);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);

	m_font.loadFromFile("arial.ttf");
	m_text = sf::Text("Seek", m_font);
	m_text.setCharacterSize(40);
	m_text.setStyle(sf::Text::Bold);
	m_text.setFillColor(sf::Color::Yellow);
	m_text.setOrigin(m_sprite.getOrigin());
}

void SeekAlien::update(sf::Vector2f targetPosition)
{
	movement(targetPosition);
}

void SeekAlien::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	window.draw(m_text);
}

int SeekAlien::getNewOrientation(int rotation, sf::Vector2f velocity)
{
	if (std::sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y)) > 0)
	{
		int newRotation = (atan2(velocity.x, -velocity.y)) * (180 / M_PI);

		return newRotation;
	}
	else
	{
		return m_rotation;
	}
}

void SeekAlien::movement(sf::Vector2f targetPosition)
{
	m_velocity = targetPosition - m_position;
	
	m_velocity = sf::Vector2f(m_velocity.x * m_maxSpeed, m_velocity.y * m_maxSpeed);

	float magnitude = std::sqrt((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y));
	m_velocity = sf::Vector2f(m_velocity.x / magnitude, m_velocity.y / magnitude);
	m_velocity = sf::Vector2f(m_velocity.x * m_maxSpeed, m_velocity.y * m_maxSpeed);

	m_rotation = getNewOrientation(m_rotation, m_velocity);

	m_position = m_position + m_velocity;

	m_sprite.setPosition(m_position);
	m_sprite.setRotation(m_rotation);
	m_text.setPosition(m_position);
}
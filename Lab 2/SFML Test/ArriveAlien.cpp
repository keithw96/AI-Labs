#include "ArriveAlien.h"

void ArriveAlien::initialise(float maxSpeed, sf::Vector2f position)
{
	m_position = position;
	m_velocity = sf::Vector2f(10.0f, 10.0f);
	m_rotation = 0;
	m_maxSpeed = maxSpeed;

	m_texture.loadFromFile("Resources/Alien1.png");
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position.x, m_position.y);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
}

void ArriveAlien::update(sf::Vector2f targetPosition)
{
	movement(targetPosition);
}

void ArriveAlien::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

int ArriveAlien::getNewOrientation(int rotation, sf::Vector2f velocity)
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

void ArriveAlien::movement(sf::Vector2f targetPosition)
{
	m_velocity = targetPosition - m_position;

	if (std::sqrt((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y)) < m_radius)
	{
	
	}
	else
	{
		m_velocity = sf::Vector2f(m_velocity.x * m_timeToTarget, m_velocity.y * m_timeToTarget);
		if (std::sqrt((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y)) > m_maxSpeed)
		{
			float mag = std::sqrt((m_velocity.x * m_velocity.x) + (m_velocity.y * m_velocity.y));
			m_velocity = sf::Vector2f(m_velocity.x / mag, m_velocity.y / mag);						
			m_velocity = sf::Vector2f(m_velocity.x * m_maxSpeed, m_velocity.y * m_maxSpeed);


			m_rotation = getNewOrientation(m_rotation, m_velocity);																						
		}

		m_position += m_velocity;
	}

	m_sprite.setPosition(m_position);
	m_sprite.setRotation(m_rotation);
}
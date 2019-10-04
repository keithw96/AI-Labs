#include "Player.h"

/// <summary>
/// Loads the players texture and initialises the player's member variables
/// </summary>
void Player::initialise()
{
	m_pos = sf::Vector2f(1500, 1500);
	m_velocity = sf::Vector2f(0, 0);
	m_rotation = 0;

	m_texture.loadFromFile("Resources/Ship.png");
	m_texture.setSmooth(true);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_pos.x, m_pos.y);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);
}

/// <summary>
/// Updates the players movement and boundary collision
/// </summary>
/// <param name="window"></param>
void Player::update(sf::RenderWindow & window)
{
	movement();
	boundaryFlip(window);
}

/// <summary>
/// Renders the players sprite
/// </summary>
/// <param name="window"></param>
void Player::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

/// <summary>
/// Updates the players position, rotation and velocity
/// </summary>
void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if(m_velocity.x < 20.0f)
		{ 
			m_velocity.x += 1.0f;
			m_velocity.y += 1.0f;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (m_velocity.x > 0.0f)
		{
			m_velocity.x -= 1.0f;
			m_velocity.y -= 1.0f;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (m_rotation < 0)
		{
			m_rotation = 360;
		}

		m_rotation -= 2;
		m_sprite.setRotation(m_rotation);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (m_rotation > 360)
		{
			m_rotation = 0;
		}

		m_rotation += 2;
		m_sprite.setRotation(m_rotation);
	}

	m_pos.x += sin((3.14159265 / 180) * m_rotation) * m_velocity.x;
	m_pos.y -= cos((3.14159265 / 180) * m_rotation) * m_velocity.y;

	m_sprite.setPosition(m_pos);

}

/// <summary>
/// Checks if the player has gone past the boundary of the screen
/// Flips them to the opposite boundary
/// </summary>
/// <param name="window"></param>
void Player::boundaryFlip(sf::RenderWindow & window)
{

	if (m_pos.x - m_sprite.getTextureRect().width < 0)
	{
		m_pos.x += window.getSize().x;
	}

	if (m_pos.x > window.getSize().x)
	{
		m_pos.x -= window.getSize().x;
	}

	if (m_pos.y - m_sprite.getTextureRect().height < 0)
	{
		
		m_pos.y += window.getSize().y;
	}

	if (m_pos.y > window.getSize().y)
	{
		m_pos.y -= window.getSize().y;
	}
}

sf::Vector2f Player::getPosition()
{
	return m_pos;
}

sf::Vector2f Player::getVelocity()
{
	return m_velocity;
}

sf::FloatRect Player::getTextureRect()
{
	return m_sprite.getGlobalBounds();
}
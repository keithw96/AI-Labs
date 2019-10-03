#include "Game.h"

/// <summary>
/// Game constructor
/// Caps window frame rate and calls object constructors
/// </summary>
Game::Game()
	: m_window(sf::VideoMode(3840, 2000), "SFML Test")
{
	m_window.setFramerateLimit(60);

	m_player.initialise();
	m_seekAlien.initialise();
	m_arriveAlien.initialise(10.0f, sf::Vector2f(600,200));
	m_arriveAlienMrk2.initialise(5.0f, sf::Vector2f(1500, 300));
	m_wanderAlien.initialise();
	m_pursueAlien.initialise();
}

/// <summary>
/// Game deconstructor
/// </summary>
Game::~Game()
{

}

/// <summary>
/// Game Update Loop
/// </summary>
void Game::run()
{
	while (m_window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

/// <summary>
/// Check for Window events
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}

/// <summary>
/// Update game objects
/// </summary>
void Game::update()
{
	m_player.update(m_window);
	m_seekAlien.update(m_player.getPosition());
	m_arriveAlien.update(m_player.getPosition());
	m_arriveAlienMrk2.update(m_player.getPosition());
	m_wanderAlien.update(m_player.getPosition());
	m_pursueAlien.update(m_player.getPosition(), m_player.getVelocity());
}

/// <summary>
/// Render Game Elements
/// </summary>
void Game::render()
{
	m_window.clear();

	m_player.render(m_window);
	m_seekAlien.render(m_window);
	m_arriveAlien.render(m_window);
	m_arriveAlienMrk2.render(m_window);
	m_wanderAlien.render(m_window);
	m_pursueAlien.render(m_window);

	m_window.display();
}

#include "Game.h"

/// <summary>
/// Game constructor
/// Caps window frame rate and calls object constructors
/// </summary>
Game::Game()
	: m_window(sf::VideoMode(2000, 2000), "SFML Test")
{
	m_window.setFramerateLimit(60);

	m_player.initialise();
	m_alien.initialise();
	
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
}

/// <summary>
/// Render Game Elements
/// </summary>
void Game::render()
{
	m_window.clear();

	m_player.render(m_window);
	m_alien.render(m_window);

	m_window.display();
}

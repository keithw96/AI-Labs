#include "Game.h"

Game::Game(): 
	m_window(sf::VideoMode(900,900), "Lab 6", sf::Style::Default)
{
	m_tileMap.initialise();
	m_window.setFramerateLimit(60);

	std::cout << "Left Click to set start point" << std::endl;
	std::cout << "Right Click to set goal point" << std::endl;
	std::cout << "Middle Click to set obstacles" << std::endl;
}


void Game::run()
{
	while (m_window.isOpen())
	{
		update();
		render();
	}
}

void Game::render()
{
	m_tileMap.render(m_window);

	m_window.display();
}

void Game::update()
{
	m_tileMap.update(m_window);
}
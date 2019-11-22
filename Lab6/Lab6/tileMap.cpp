#include "tileMap.h"

void TileMap::initialise()
{
	m_tileSize = 20;
	m_goalSet = false;
	m_startSet = false;
	m_tilePosX = 0;
	m_tilePosY = 0;

	for (int i = 0; i < m_gridSize; i++)
	{
		for (int j = 0; j < m_gridSize; j++)
		{
			m_tileArray[j][i] = new Tile(j * m_tileSize, i * m_tileSize, m_tileSize);
		}
	}
}

void TileMap::update(sf::RenderWindow &window)
{
	processEvents(window);
}

void TileMap::render(sf::RenderWindow & window)
{
	for (int i = 0; i < m_gridSize; i++)
	{
		for (int j = 0; j < m_gridSize; j++)
		{
			m_tileArray[i][j]->render(window);
		}
	}
}

void TileMap::processEvents(sf::RenderWindow& window)
{
	m_mousePos = sf::Mouse::getPosition(window);
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			std::cout << "Close" << std::endl;
			window.close();
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_startSet == false)
	{
		m_tilePosX = static_cast<int>(m_mousePos.x / (m_tileSize));
		m_tilePosY = static_cast<int>(m_mousePos.y / (m_tileSize));

		if (m_start != NULL)
		{
			m_start->setState(NONE);
		}

		if (m_tileArray[m_tilePosX][m_tilePosY]->getState() != OBSTACLE)
		{
			m_start = m_tileArray[m_tilePosX][m_tilePosY];

			m_tileArray[m_tilePosX][m_tilePosY]->setState(START);

			
			m_startSet = true;
		}
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_startSet = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && m_goalSet == false && m_start != NULL)
	{
		m_tilePosX = static_cast<int>(m_mousePos.x / (m_tileSize));
		m_tilePosY = static_cast<int>(m_mousePos.y / (m_tileSize));


		if (m_goal != NULL)
		{
			m_goal->setState(NONE);
		}

		if (m_tileArray[m_tilePosX][m_tilePosY]->getState() != OBSTACLE)
		{
			m_goal = m_tileArray[m_tilePosX][m_tilePosY];

			m_tileArray[m_tilePosX][m_tilePosY]->setState(GOAL);

			m_goalSet = true;

		//	setCosts(m_tilePosX, m_tilePosY);
		}

	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		m_goalSet = false;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
	{
		m_tilePosX = static_cast<int>(m_mousePos.x / m_tileSize);
		m_tilePosY = static_cast<int>(m_mousePos.y / m_tileSize);

		if (m_tileArray[m_tilePosX][m_tilePosY]->getState() != OBSTACLE)
		{
			m_tileArray[m_tilePosX][m_tilePosY]->setState(OBSTACLE);
		}
	}
}

void TileMap::setCosts(int posX, int posY)
{
	for (int i = 0; i < m_gridSize; i++)
	{
		for (int j = 0; j < m_gridSize; j++)
		{
			if (m_tileArray[i][j]->getState() == OBSTACLE)
			{
				m_tileArray[i][j]->setCost(std::numeric_limits<int>::max());
			}
		}
	}

	for (int i = 0; i < m_gridSize; i++)
	{
		for (int j = 0; j < m_gridSize; j++)
		{
			if (m_tileArray[i][j]->getState() == NONE)
			{
				m_tileArray[i][j]->setCost(0);
			}
		}
	}

	std::list<Tile> tileQueue;

	tileQueue.push_back(*m_tileArray[posX][posY]);

	m_tileArray[posX][posY]->setCost(0);
	int i = 0;

	auto iter = tileQueue.begin();

	while (tileQueue.size() != 0)
	{
		i++;

		if (iter->getX() != m_gridSize - 1 && m_tileArray[iter->getX() + 1][iter->getY()]->getCost() == 0 && m_tileArray[iter->getX() + 1][iter->getY()]->getState() != GOAL)
		{
			m_tileArray[iter->getX() + 1][iter->getY()]->setCost(m_tileArray[iter->getX()][iter->getY()]->getCost() + 1);
			m_tileArray[iter->getX() + 1][iter->getY()]->setRotation(180);
			m_tileArray[iter->getX() + 1][iter->getY()]->setPrevious(m_tileArray[iter->getX()][iter->getY()]->getX(), m_tileArray[iter->getX()][iter->getY()]->getY());
			tileQueue.push_back(*m_tileArray[iter->getX() + 1][iter->getY()]);
		}

		if (iter->getX() != m_gridSize - 1 && m_tileArray[iter->getX()][iter->getY() + 1]->getCost() == 0 && m_tileArray[iter->getX()][iter->getY() + 1]->getState() != GOAL)
		{
			m_tileArray[iter->getX()][iter->getY() + 1]->setCost(m_tileArray[iter->getX()][iter->getY()]->getCost() + 1);
			m_tileArray[iter->getX()][iter->getY() + 1]->setRotation(270);
			m_tileArray[iter->getX()][iter->getY() + 1]->setPrevious(m_tileArray[iter->getX()][iter->getY()]->getX(), m_tileArray[iter->getX()][iter->getY()]->getY());
			tileQueue.push_back(*m_tileArray[iter->getX()][iter->getY() + 1]);
		}

		if (iter->getX() != 0 && m_tileArray[iter->getX() - 1][iter->getY()]->getCost() == 0 && m_tileArray[iter->getX() - 1][iter->getY()]->getState() != GOAL)
		{
			m_tileArray[iter->getX() - 1][iter->getY()]->setCost(m_tileArray[iter->getX()][iter->getY()]->getCost() + 1);
			m_tileArray[iter->getX() - 1][iter->getY()]->setRotation(0);
			m_tileArray[iter->getX() - 1][iter->getY()]->setPrevious(m_tileArray[iter->getX()][iter->getY()]->getX(), m_tileArray[iter->getX()][iter->getY()]->getY());
			tileQueue.push_back(*m_tileArray[iter->getX() - 1][iter->getY()]);
		}

		if (iter->getY() != 0 && m_tileArray[iter->getX()][iter->getY() - 1]->getCost() == 0 && m_tileArray[iter->getX()][iter->getY() - 1]->getState() != GOAL)
		{
			m_tileArray[iter->getX()][iter->getY() - 1]->setCost(m_tileArray[iter->getX()][iter->getY()]->getCost() + 1);
			m_tileArray[iter->getX()][iter->getY() - 1]->setRotation(90);
			m_tileArray[iter->getX()][iter->getY() - 1]->setPrevious(m_tileArray[iter->getX()][iter->getY()]->getX(), m_tileArray[iter->getX()][iter->getY()]->getY());
			tileQueue.push_back(*m_tileArray[iter->getX()][iter->getY() - 1]);
		}
		if (iter->getX() != m_gridSize - 1 && iter->getY() != m_gridSize - 1 && m_tileArray[iter->getX() + 1][iter->getY() + 1]->getCost() == 0 && m_tileArray[iter->getX() + 1][iter->getY() + 1]->getState() != GOAL)
		{
			m_tileArray[iter->getX() + 1][iter->getY() + 1]->setCost(m_tileArray[iter->getX()][iter->getY()]->getCost() + 1);
			m_tileArray[iter->getX() + 1][iter->getY() + 1]->setRotation(202.5);
			m_tileArray[iter->getX() + 1][iter->getY() + 1]->setPrevious(m_tileArray[iter->getX()][iter->getY()]->getX(), m_tileArray[iter->getX()][iter->getY()]->getY());
			tileQueue.push_back(*m_tileArray[iter->getX() + 1][iter->getY() + 1]);
		}
		if (iter->getY() != m_gridSize - 1 && iter->getX() != 0 && m_tileArray[iter->getX() - 1][iter->getY() + 1]->getCost() == 0 && m_tileArray[iter->getX() - 1][iter->getY() + 1]->getState() != GOAL)
		{
			m_tileArray[iter->getX() - 1][iter->getY() + 1]->setCost(m_tileArray[iter->getX()][iter->getY()]->getCost() + 1);
			m_tileArray[iter->getX() - 1][iter->getY() + 1]->setRotation(292.5);
			m_tileArray[iter->getX() - 1][iter->getY() + 1]->setPrevious(m_tileArray[iter->getX()][iter->getY()]->getX(), m_tileArray[iter->getX()][iter->getY()]->getY());
			tileQueue.push_back(*m_tileArray[iter->getX() - 1][iter->getY() + 1]);
		}
		if (iter->getY() != 0 && iter->getX() != 0 && m_tileArray[iter->getX() - 1][iter->getY() - 1]->getCost() == 0 && m_tileArray[iter->getX() - 1][iter->getY() - 1]->getState() != GOAL)
		{
			m_tileArray[iter->getX() - 1][iter->getY() - 1]->setCost(m_tileArray[iter->getX()][iter->getY()]->getCost() + 1);
			m_tileArray[iter->getX() - 1][iter->getY() - 1]->setRotation(45);
			m_tileArray[iter->getX() - 1][iter->getY() - 1]->setPrevious(m_tileArray[iter->getX()][iter->getY()]->getX(), m_tileArray[iter->getX()][iter->getY()]->getY());
			tileQueue.push_back(*m_tileArray[iter->getX() - 1][iter->getY() - 1]);
		}
		if (iter->getX() != m_gridSize - 1 && iter->getY() != 0 && m_tileArray[iter->getX() + 1][iter->getY() - 1]->getCost() == 0 && m_tileArray[iter->getX() + 1][iter->getY() - 1]->getState() != GOAL)
		{
			m_tileArray[iter->getX() + 1][iter->getY() - 1]->setCost(m_tileArray[iter->getX()][iter->getY()]->getCost() + 1);
			m_tileArray[iter->getX() + 1][iter->getY() - 1]->setRotation(112.5);
			m_tileArray[iter->getX() + 1][iter->getY() - 1]->setPrevious(m_tileArray[iter->getX()][iter->getY()]->getX(), m_tileArray[iter->getX()][iter->getY()]->getY());
			tileQueue.push_back(*m_tileArray[iter->getX() + 1][iter->getY() - 1]);
		}
		iter++;
		tileQueue.pop_front();
	}
	createPath(*m_start);
}

void TileMap::createPath(Tile m_startTile)
{
	std::list<Tile> tileQueue;

	tileQueue.push_back(m_startTile);

	auto iter = tileQueue.begin();

	while (iter->m_cost != 0 && m_tileArray[iter->m_previous.first][iter->m_previous.second]->getState() != GOAL)
	{
		m_tileArray[iter->m_previous.first][iter->m_previous.second]->setState(PATH);
		tileQueue.push_back(*m_tileArray[iter->m_previous.first][iter->m_previous.second]);

		iter++;
	}
}
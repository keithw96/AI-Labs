#pragma once

#include "Player.h"
#include "SeekAlien.h"
#include "ArriveAlien.h"
#include "WanderAlien.h"
#include "PursueAlien.h"

class Game
{
public: 
	Game();
	~Game();

	void run();
	void processEvents();
	void update();
	void render();

private:

	Player m_player;
	SeekAlien m_seekAlien;
	ArriveAlien m_arriveAlien;
	ArriveAlien m_arriveAlienMrk2;
	WanderAlien m_wanderAlien;
	PursueAlien m_pursueAlien;

	sf::RenderWindow m_window;
};


#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/View.hpp>
#include <SFML/System/Clock.hpp>

#include "SharedObject.h"

class Game
{
public:
	Game(SharedObject& obj);
	~Game() = default;

	void Run(); //Run Game loop
	void RestartClock(); //Reset Clock

private:
	SharedObject& mObj;
	sf::View mCamera;
	sf::Clock mClock;
	float mDeltaTime = 0;

	void InitSFX();
	void InitMusic();
};

#endif
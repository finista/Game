#pragma once

#include "Player.h"

#include <SFML/Graphics.hpp>
using namespace sf;

class Engine
{
private:
	Event event;
	RenderWindow window;
	Player player;
public:
	Engine();

	void loop();
};


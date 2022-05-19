#include "Engine.h"

Engine::Engine() {
	window.create(VideoMode(1280, 720), "Platformer");
}

// Create jump, run, etc Create player status changing

void Engine::loop() {
	Clock clock;

	while (window.isOpen()) {
		float deltaTime = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		player.update(deltaTime);

		window.clear();

		window.draw(player.getSprite());

		window.display();
	}
}
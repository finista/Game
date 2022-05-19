#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	Vector2f position;
	float speed, maxSpeed;
	float jumpVelocity;

	float deltaTime;

	int moveDirection;

	int width, height;
	float frame;

	int health;

	Texture idleTexture;
	Texture runTexture;
	Texture jumpTexture;

	Sprite sprite;

	enum PlayerState {
		Idle, 
		Running,
		Jumping, Falling
	};
	PlayerState currentState;

	void action();
public:
	Player();

	Sprite getSprite();

	void update(float);
	void fixedUpdate();

	void animation();
};

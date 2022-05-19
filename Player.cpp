#include "Player.h"

Player::Player() :
	position(0, 0),
	speed(0),
	maxSpeed(40),
	jumpVelocity(0),
	health(100),
	width(65),
	height(70),
	frame(0)
{
	idleTexture.loadFromFile("Assets/Player/Idle/1x.png");
	runTexture.loadFromFile("Assets/Player/Run/1x.png");
	jumpTexture.loadFromFile("Assets/Player/Jump/1x.png");

	sprite.setTexture(idleTexture);
	sprite.setTextureRect(IntRect(16, 0, width, height));
}

Sprite Player::getSprite() {
	return sprite;
}

void Player::action() {
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		currentState = PlayerState::Running;
		moveDirection = 1;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		currentState = PlayerState::Running;
		moveDirection = -1;
	}
}

void Player::update(float deltaTime) {
	this->deltaTime = deltaTime;

	currentState = PlayerState::Idle;

	action();
	fixedUpdate();

	animation();
}

void Player::fixedUpdate() {
	position += Vector2f(moveDirection * speed * deltaTime * .00001, 0);

	if (speed < maxSpeed && currentState == PlayerState::Running) {
		speed += deltaTime * .0001;
	}
	else if (currentState == PlayerState::Idle) {
		speed = 0;
	}

	sprite.setPosition(position);
}

void Player::animation() {
	if (currentState == PlayerState::Running) {
		sprite.setTexture(runTexture);
		sprite.setTextureRect(IntRect(20 + (int)frame * width, 5, width, height));

		frame += 0.0009;
		if (frame >= 18) {
			frame = 0;
		}
	}
}
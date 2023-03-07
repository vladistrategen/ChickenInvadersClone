#include "Player.h"

Player::Player()
{
	this->health = 100;
	this->damage = 10;
	this->position = sf::Vector2f(1, 300);
	this->velocity_modifier = 1;
	this->acceleration = 1;
	this->size = sf::Vector2f(0.07, 0.07);
	this->pathToTexture = "Assets/player.png";
}

void Player::triggerCooldown()
{
	this->isOnShootCooldown = true;
	std::thread cooldownThread(&Player::resetCooldown, this);
	cooldownThread.detach();
	
}



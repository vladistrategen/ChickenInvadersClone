#include "Bullet.h"

Bullet::Bullet()
{
	this->health = 1;
	this->damage = 10;
	this->position = sf::Vector2f(1, 1);
	this->velocity_modifier = 1.2;
	this->acceleration = 1;
	this->size = sf::Vector2f(0.07, 0.07);
	this->pathToTexture = "Assets/bullet.png";
}

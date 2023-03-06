#include "GameObject.h"

GameObject::GameObject()
{
	this->health = 50;
	this->damage = 10;
	this->position = sf::Vector2f(0, 0);
	this->velocity = sf::Vector2f(0, 0);
	this->acceleration = sf::Vector2f(0, 0);
	this->size = sf::Vector2f(0, 0);

	
}

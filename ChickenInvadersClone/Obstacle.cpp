#include "Obstacle.h"
#include <time.h>
Obstacle::Obstacle()
{
	this->health = 10;
	this->damage = 10;
	this->position = sf::Vector2f(0, 0);
	this->velocity_modifier = 0.85;
	this->acceleration = 1;
	this->size = sf::Vector2f(0.1,0.1);
}

void Obstacle::randomizeTexture()
{
	int random = rand() % 3;
	this->pathToTexture = this->obstacleTextures[random];
}

void Obstacle::randomizePosition()
{
	int random = rand() % 800;
	this->position = sf::Vector2f(1280,random );
}

void Obstacle::loadTexture()
{
	this->randomizeTexture();
	GameObject::loadTexture(); //  calls the loadTexture() method from the base class
}

void Obstacle::loadSprite()
{
	this->randomizePosition();
	GameObject::loadSprite(); //  calls the loadSprite() method from the base class
	/*if (this->sprite.getLocalBounds().height < 600 && this->sprite.getLocalBounds().width < 600)
	{
		int currentScale = this->sprite.getScale().x;
		this->sprite.setScale(currentScale*2,currentScale*2);

	}*/
}

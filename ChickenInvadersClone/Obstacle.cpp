#include "Obstacle.h"
#include <time.h>
Obstacle::Obstacle()
{
	this->health = 10;
	this->damage = 10;
	this->position = sf::Vector2f(0, 0);
	this->velocity_modifier = 5;
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

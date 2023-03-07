#include "GameObjectFactory.h"

GameObject* GameObjectFactory::createGameObject(string objectType)
{
	if (objectType == "Bullet")
	{
		return new Bullet();
	}
	else if (objectType == "Player")
	{
		return new Player();
	}
	else if (objectType == "Obstacle")
	{
		return new Obstacle();
	}
	else
	{
		return nullptr;
	}
	
}

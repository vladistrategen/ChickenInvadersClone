#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "Bullet.h"
#include "Player.h"
#include "Obstacle.h"


using std::string;
class GameObjectFactory
{
public:
	GameObjectFactory() {}
	~GameObjectFactory() {}
	GameObject* createGameObject(string objectType);
};


#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "GameObject.h"
#include "Bullet.h"
#include "GameObjectFactory.h"
using std::vector;
class GameObjectManager
{
public:
	GameObjectManager();
	
	~GameObjectManager();
	
	void addObstacle(GameObject* obs) {
		this->obstacles.push_back(obs);
	}

	void addFriendlyProjectile(GameObject* proj) {
		this->friendlyProjectiles.push_back(proj);
	}

	void removeObstacle(GameObject* obs);

	void removeFriendlyProjectile(GameObject* proj);

	void drawAll(sf::RenderWindow* window);

	bool handlePlayerCollisions();

	void handleFriendlyProjectileCollisions();

	void handleCollisions() {
		this->handlePlayerCollisions();
		this->handleFriendlyProjectileCollisions();
	}

	void createFriendlyProjectile(float x, float y);

	void createObstacle();

	void update();

	void moveInanimateObjects();

	void setPlayer(Player* player) {
		this->player = player;
	}

private:
	std::vector<GameObject*> obstacles;
	std::vector<GameObject*> friendlyProjectiles;
	Player* player;
	GameObjectFactory* factory;
};


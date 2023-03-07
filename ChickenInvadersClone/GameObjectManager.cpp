#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
	player = new Player();
	obstacles = vector<GameObject*>();
	friendlyProjectiles = vector<GameObject*>();
	factory = new GameObjectFactory();
}

GameObjectManager::~GameObjectManager()
{
	delete player;
	for (auto obstacle : obstacles) {
		delete obstacle;
	}
	for (auto projectile : friendlyProjectiles) {
		delete projectile;
	}
}

void GameObjectManager::removeObstacle(GameObject* obs)
{
	for (int i = 0; i < obstacles.size(); i++) {
		if (obstacles[i] == obs) {
			obstacles.erase(obstacles.begin() + i);
			break;
		}
	}
	delete obs;
}

void GameObjectManager::removeFriendlyProjectile(GameObject* proj)
{

	for (int i = 0; i < friendlyProjectiles.size(); i++) {
		if (friendlyProjectiles[i] == proj) {
			friendlyProjectiles.erase(friendlyProjectiles.begin() + i);
			break;
		}
	}
	delete proj;
}

void GameObjectManager::drawAll(sf::RenderWindow* window)
{
	for (auto gameObject : obstacles)
	{
		window->draw(*gameObject);
	}
	for (auto gameObject : friendlyProjectiles)
	{
		window->draw(*gameObject);
	}
	window->draw(*player);
}

void GameObjectManager::handlePlayerCollisions()
{
	for (auto obstacle : obstacles) {
		if (player->getSpritePointer()->getGlobalBounds().intersects(obstacle->getSpritePointer()->getGlobalBounds())) {
			player->setHealth(player->getHealth() - obstacle->getDamage());
			removeObstacle(obstacle);
		}
	}
}

void GameObjectManager::handleFriendlyProjectileCollisions()
{
	for (auto bullet : friendlyProjectiles) {
		for (auto obstacle : obstacles) {
			if (bullet->getSpritePointer()->getGlobalBounds().intersects(obstacle->getSpritePointer()->getGlobalBounds()))
			{
				obstacle->setHealth(obstacle->getHealth() - bullet->getDamage());
				removeFriendlyProjectile(bullet);
				if (obstacle->getHealth() <= 0) {
					removeObstacle(obstacle);
				}
			}
		}
	}
}

void GameObjectManager::createFriendlyProjectile(float x, float y)
{
	GameObject* newobj = factory->createGameObject("Bullet");
	newobj->loadTexture();
	newobj->loadSprite();
	newobj->getSpritePointer()->setPosition(x, y);
	addFriendlyProjectile(newobj);
}

void GameObjectManager::createObstacle(float x, float y)
{
}

void GameObjectManager::update()
{
}

void GameObjectManager::moveInanimateObjects()
{
	for (auto obstacle : obstacles) {
		obstacle->UpdatePosition(-5, 0);
		if(obstacle->getSpritePointer()->getPosition().x<0)
			removeObstacle(obstacle);
	}
	for (auto projectile : friendlyProjectiles) {
		projectile->UpdatePosition(5,0);
		if(projectile->getSpritePointer()->getPosition().x>1280)
			removeFriendlyProjectile(projectile);
	}
}



#include "AssetLoader.h"

AssetLoader::AssetLoader()
{
	this->gameObjects = vector<GameObject*>();
}

AssetLoader::~AssetLoader()
{
	while (!gameObjects.empty()) {
		delete gameObjects.back();
		gameObjects.pop_back();
	}
}

void AssetLoader::loadSprites()
{
	for (auto gameObject : this->gameObjects)
	{
		gameObject->loadSprite();
	}
}

void AssetLoader::loadTextures()
{
	for (auto gameObject : this->gameObjects)
	{
		gameObject->loadTexture();
	}
}

void AssetLoader::addGameObject(GameObject* gameObject)
{
	this->gameObjects.push_back(gameObject);
}

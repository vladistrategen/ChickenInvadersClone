#include "AssetLoader.h"

AssetLoader::AssetLoader()
{
	this->gameObjects = vector<GameObject*>();
}

AssetLoader::~AssetLoader()
{

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

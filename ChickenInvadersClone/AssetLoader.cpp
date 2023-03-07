#include "AssetLoader.h"

AssetLoader::AssetLoader()
{
	this->gameObjects = vector<GameObject>();
}

AssetLoader::~AssetLoader()
{

}

void AssetLoader::loadSprites()
{
	sf::Texture texture;
	texture.loadFromFile("Assets/Chicken.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	GameObject gameObject;
	gameObject.setSprite(sprite);
	gameObject.setTexture(texture);
	this->gameObjects.push_back(gameObject);
}

void AssetLoader::loadTextures()
{
	for (auto gameObject : this->gameObjects)
	{
		gameObject.loadTexture();
	}
}
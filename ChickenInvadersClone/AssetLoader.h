#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
using std::vector;
class AssetLoader
{
public:
	AssetLoader();
	~AssetLoader();
	void loadSprites();
	void loadTextures();
	void addGameObject(GameObject* gameObject);
private:
	vector<GameObject*> gameObjects;
};


#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "AssetLoader.h"
#include "Player.h"
#include "CollisionHandler.h"
#include "GameObjectManager.h"
using std::string;

class Game
{
public:
	Game();
	~Game();
	void run();
	void initialize();
private:
	AssetLoader* assetLoader;
	GameObjectManager* gameObjectManager;
	Player* player;
	sf::Texture backgroundTexture;
	sf::Sprite background;
};


#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "AssetLoader.h"
#include "Player.h"
#include "CollisionHandler.h"
#include "GameObjectManager.h"
#include "UiObjectManager.h"
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
	UiObjectManager* uiObjectManager;

	Player* player;

	sf::Texture backgroundTexture;
	sf::Sprite background;

	sf::Texture gameOverTexture;
	sf::Sprite gameOverSprite;

	bool isGameOver = false;

};


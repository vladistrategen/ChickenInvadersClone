#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "AssetLoader.h"
#include "Player.h"
#include "CollisionHandler.h"
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
	CollisionHandler collisionHandler;
	Player* player;
};


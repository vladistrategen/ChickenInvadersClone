#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <string>
using std::string;
class Obstacle
	: public  GameObject
{
	public:
	Obstacle();
	~Obstacle() {}
	void randomizeTexture();
	void randomizePosition();
	void loadTexture() override;
	void loadSprite() override;
private:
	string obstacleTextures[3] = { "Assets/obstacle1.png", "Assets/obstacle2.png", "Assets/obstacle3.png" };
};


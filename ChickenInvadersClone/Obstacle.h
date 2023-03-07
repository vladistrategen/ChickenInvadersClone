#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <string>
using std::string;
class Obstacle
	: public sf::Drawable, public sf::Transformable, public GameObject
{
	public:
	Obstacle();
	~Obstacle() {}
	void randomizeTexture();
	void randomizePosition();
private:
	string obstacleTextures[3] = { "Assets/Obstacle1.png", "Assets/Obstacle2.png", "Assets/Obstacle3.png" };
};


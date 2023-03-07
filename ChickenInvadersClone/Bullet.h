#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
class Bullet : public GameObject
{
	public:
	Bullet();
	~Bullet() {}
	void update();
	void draw(sf::RenderWindow& window);
	void setDirection(int direction);
};


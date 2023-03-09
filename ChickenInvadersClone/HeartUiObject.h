#pragma once
#include "UiObject.h"
#include <SFML/Graphics.hpp>
#include <string>
using std::string;
class HeartUiObject
	: public UiObject
{
public:

	HeartUiObject();

	~HeartUiObject() {}

	void setPosition(float x, float y) { this->sprite.setPosition(x, y); }

	void setPosition(sf::Vector2f pos) { this->sprite.setPosition(pos); }

	void setIsEmpty() { this->empty_texture = true; }

	void damage() {
		if (damageState > 0) {
			this->pathToTexture = this->Textures[--this->damageState];
			if (!damageState)
				setIsEmpty();
			this->loadTexture();
			this->loadSprite();
		}
		
	}
	
	bool isEmpty() { return empty_texture; }
private:
	int damageState = 2;
	string Textures[3] = {  "Assets/emptyHeart.png", "Assets/halfHeart.png", "Assets/fullHeart.png" };
	bool empty_texture = false;

};


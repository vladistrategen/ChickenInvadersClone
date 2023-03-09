#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
using std::string;
using std::vector;
class UiObject
	: public sf::Drawable
{
public:
	UiObject();
	~UiObject() {}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void setTexture(sf::Texture& texture);

	virtual void loadTexture();

	void setSprite(sf::Sprite& sprite);

	virtual void loadSprite();

	sf::Sprite* getSpritePointer() { return &this->sprite; }
	
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	string pathToTexture;
};


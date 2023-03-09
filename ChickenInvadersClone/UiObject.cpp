#include "UiObject.h"

UiObject::UiObject()
{

}

void UiObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite);
}

void UiObject::setTexture(sf::Texture& texture)
{
	this->texture = texture;
}

void UiObject::loadTexture()
{
	if (!this->texture.loadFromFile(this->pathToTexture))
	{
		// Handle error
		std::cerr << "[!] Cannot load file: \"" << this->pathToTexture << "\". Exiting...\n";
		std::cin.get();
		exit(1);
	}
	this->texture.setSmooth(true);
}

void UiObject::setSprite(sf::Sprite& sprite)
{
	this->sprite = sprite;
}

void UiObject::loadSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.2, 0.2);
}

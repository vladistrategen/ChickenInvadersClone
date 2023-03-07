#include "GameObject.h"
#include <iostream>


GameObject::GameObject()
{
	this->health = 50;
	this->damage = 10;
	this->position = sf::Vector2f(0, 0);
	this->velocity_modifier = 1;
	this->acceleration = 1;
	this->size = sf::Vector2f(0.1, 0.1);

}


void GameObject::UpdatePosition(float x_offset, float y_offset)
{
	this->sprite.move(x_offset*velocity_modifier, y_offset*velocity_modifier);
}

sf::Vector2f GameObject::getPosition()
{
	return this->sprite.getPosition();
}

void GameObject::setPosition(sf::Vector2f position)
{
	this->position = position;
}

void GameObject::setTexture(sf::Texture& texture)
{
	this->texture = texture;
}

void GameObject::loadTexture()
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

void GameObject::setSprite(sf::Sprite& sprite)
{
	this->sprite = sprite;
}

void GameObject::loadSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->position);
	this->sprite.setScale(0.1, 0.1);
}

sf::Sprite* GameObject::getSpritePointer()
{
	return &this->sprite;
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite);
}

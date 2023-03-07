#include "GameObject.h"
#include <iostream>


GameObject::GameObject()
{
	this->health = 50;
	this->damage = 10;
	this->position = sf::Vector2f(0, 0);
	this->velocity = 5;
	this->acceleration = 1;
	this->size = 1;

}


void GameObject::UpdatePosition(float x_offset, float y_offset)
{
	this->position.x += x_offset;
	this->position.y += y_offset;
}

sf::Vector2f GameObject::getPosition()
{
	return this->position;
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
}

void GameObject::setSprite(sf::Sprite& sprite)
{
	this->sprite = sprite;
}

void GameObject::loadSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->position);
}

sf::Sprite* GameObject::getSpritePointer()
{
	return &this->sprite;
}



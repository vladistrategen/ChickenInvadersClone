#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using std::string;
class GameObject: public sf::Drawable
{
public:
	GameObject();
	~GameObject() {}
	void UpdatePosition(float x_offset, float y_offset);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);
	void setTexture(sf::Texture& texture);
	void loadTexture();
	void setSprite(sf::Sprite& sprite);
	void loadSprite();
	sf::Sprite* getSpritePointer();

	int getHealth(){ return this->health; }
	void setHealth(int health) { this->health = health; }

	int getDamage() { return this->damage; }
	void setDamage(int damage) { this->damage = damage; }
	
	float getVelocity() { return this->velocity; }
	void setVelocity(float velocity) { this->velocity = velocity; }
	
	float getAcceleration() { return this->acceleration; }
	void setAcceleration(float acceleration) { this->acceleration = acceleration; }

	int getSize() { return this->size; }
	void setSize(int size) { this->size = size; }
	
	string getPathToTexture() { return this->pathToTexture; }
	void setPathToTexture(string pathToTexture) { this->pathToTexture= pathToTexture; }



private:
	int health;
	int damage;
	sf::Vector2f position;
	float velocity;
	float acceleration;
	int size;
	sf::Texture texture;
	sf::Sprite sprite;

	string pathToTexture;



};


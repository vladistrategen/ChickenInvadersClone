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
	virtual void setPosition(sf::Vector2f position);
	void setTexture(sf::Texture& texture);
	virtual void loadTexture();
	void setSprite(sf::Sprite& sprite);
	virtual void loadSprite();
	sf::Sprite* getSpritePointer();

	int getHealth(){ return this->health; }
	void setHealth(int health) { this->health = health; }

	int getDamage() { return this->damage; }
	void setDamage(int damage) { this->damage = damage; }
	
	float getVelocity() { return this->velocity; }
	void setVelocity(float velocity) { this->velocity = velocity; }
	
	float getAcceleration() { return this->acceleration; }
	void setAcceleration(float acceleration) { this->acceleration = acceleration; }

	sf::Vector2f getSize() { return this->size; }
	void setSize(sf::Vector2f size) { this->size = size; }
	
	string getPathToTexture() { return this->pathToTexture; }
	void setPathToTexture(string pathToTexture) { this->pathToTexture= pathToTexture; }

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


protected:
	int health;
	int damage;
	sf::Vector2f position;
	float velocity;
	float acceleration;
	sf::Vector2f size;
	sf::Texture texture;
	sf::Sprite sprite;

	string pathToTexture;



};


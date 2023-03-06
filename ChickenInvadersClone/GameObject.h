#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{
public:
	GameObject();
	~GameObject();
	void Draw();
	void UpdatePosition(float x_offset, float y_offset);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);
	void setTexture(sf::Texture texture);
	void setSprite(sf::Sprite sprite);
	sf::Sprite* getSpritePointer();
	int getHealth();
	void setHealth(int health);
	int getDamage();
	void setDamage(int damage);
	float getVelocity();
	void setVelocity(float velocity);
	float getAcceleration();
	void setAcceleration(float acceleration);
	int getSize();
	void setSize(int size);
	


private:
	int health;
	int damage;
	sf::Vector2f position;
	float velocity;
	float acceleration;
	int size;
	sf::Texture texture;
	sf::Sprite sprite;

};


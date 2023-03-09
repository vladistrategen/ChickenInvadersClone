#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "UiObject.h"
#include "HeartUiObject.h"
using std::vector;
class UiObjectManager
{
	public:
	UiObjectManager();
	~UiObjectManager();
	void drawAllHearts(sf::RenderWindow* window);
	void handleHeartChanges();
	void initialize();
	void setPlyaer(Player* player) { this->player = player; }

	void addHeart(HeartUiObject* heart) { this->hearts.push_back(heart); }
	void removeHeart(HeartUiObject* heart);
private:
	Player* player;
	vector<HeartUiObject*> hearts;
};


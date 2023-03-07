#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <chrono>
#include <thread>
class Player: public GameObject
{
public:
	Player();
	~Player() {}
	void triggerCooldown();
	
	
	
	bool canShoot() { return !this->isOnShootCooldown; }
	
	void resetCooldown() {
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		isOnShootCooldown = false;
	}
private:
	bool isOnShootCooldown = false;
};



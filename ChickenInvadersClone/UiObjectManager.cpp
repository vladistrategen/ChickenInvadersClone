#include "UiObjectManager.h"

UiObjectManager::UiObjectManager()
{
	
	this->hearts = vector<HeartUiObject*>();
}

UiObjectManager::~UiObjectManager()
{
	for (auto heart : hearts) {
		delete heart;
	}
}


void UiObjectManager::drawAllHearts(sf::RenderWindow* window)
{
	for (auto heart : hearts)
	{
		window->draw(*heart);
	}
}

void UiObjectManager::handleHeartChanges()
{
	for (auto heart : hearts) {
		if (!heart->isEmpty()) {
			heart->damage();
			break;
		}
	}
}

void UiObjectManager::initialize()
{
	for (int i = 0; i < player->getHealth() / 20; i++) {
		HeartUiObject* heart = new HeartUiObject();
		heart->loadTexture();
		heart->loadSprite();

		heart->setPosition(1200 - i * 50, 20);
		this->addHeart(heart);
	}
}

void UiObjectManager::removeHeart(HeartUiObject* heart)
{
	for (int i = 0; i < hearts.size(); i++) {
		if (hearts[i] == heart) {
			hearts.erase(hearts.begin() + i);
			break;
		}
	}
	delete heart;
}

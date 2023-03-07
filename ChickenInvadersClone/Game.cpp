#include "Game.h"
#include <time.h>


Game::Game()
{
	this->assetLoader = new AssetLoader();
	this->player = new Player();
	this->assetLoader->addGameObject(this->player);
    this->gameObjectManager = new GameObjectManager();
    this->gameObjectManager->setPlayer(player);
	
}
Game::~Game()
{
    delete this->assetLoader;
	delete this->gameObjectManager;
}
void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Chicken Invaders Clone");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (player->getPosition().x > 1)
                player->UpdatePosition(-5, 0);

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (player->getPosition().x < 1160)
                player->UpdatePosition(5, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (player->getPosition().y > 1)
                player->UpdatePosition(0, -5);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (player->getPosition().y < 620)
                player->UpdatePosition(0, 5);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (player->canShoot()) {
                gameObjectManager->createFriendlyProjectile(player->getPosition().x + 40, player->getPosition().y + 35);
                player->triggerCooldown();
            }
        }


        window.clear();
        window.draw(background);
        gameObjectManager->moveInanimateObjects();
        gameObjectManager->drawAll(&window);
        
        window.display();
    }
}
void Game::initialize()
{
    this->assetLoader->loadTextures();
    this->assetLoader->loadSprites();
    this->backgroundTexture.loadFromFile("Assets/background.png");
    this->background.setTexture(backgroundTexture);
    this->background.setPosition(0, 0);
    this->background.setScale(0.7, 0.7);
    
	srand(time(NULL));
	
    
}

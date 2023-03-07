#include "Game.h"
#include <time.h>
Game::Game()
{
	this->assetLoader = new AssetLoader();
	this->player = new Player();
	this->assetLoader->addGameObject(this->player);
	
}
Game::~Game()
{
}
void Game::run()
{
}
void Game::initialize()
{
    this->assetLoader->loadTextures();
    this->assetLoader->loadSprites();
    
	srand(time(NULL));
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
            if (player->getPosition().x>1)
                player->UpdatePosition(-10, 0);

        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (player->getPosition().x<1160)
                player->UpdatePosition(10, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (player->getPosition().y>1)
                player->UpdatePosition(0, -10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (player->getPosition().y<620)
                player->UpdatePosition(0, 10);
        }



        window.clear();
        window.draw(*player);
        window.display();
    }
}

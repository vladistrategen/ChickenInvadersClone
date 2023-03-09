#include "Game.h"
#include <time.h>


Game::Game()
{
	this->assetLoader = new AssetLoader();
	this->player = new Player();
	this->assetLoader->addGameObject(this->player);
    this->gameObjectManager = new GameObjectManager();
    this->gameObjectManager->setPlayer(player);
    this->uiObjectManager = new UiObjectManager();
    this->uiObjectManager->setPlyaer(player);
	
}
Game::~Game()
{
    delete this->assetLoader;
	delete this->gameObjectManager;
    
    delete this->uiObjectManager;
    
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
        int random_number = rand();
        if (random_number % 67 == 0 ) { // arbitrary number to create obstacles
			gameObjectManager->createObstacle();
		}

        if (isGameOver) {
			window.clear();
			window.draw(gameOverSprite);
			window.display();
			continue;
		}

        window.clear();
        window.draw(background);
        gameObjectManager->moveInanimateObjects();
        if (this->gameObjectManager->handlePlayerCollisions()){
			this->uiObjectManager->handleHeartChanges();
		}
        this->gameObjectManager->handleFriendlyProjectileCollisions();
        gameObjectManager->drawAll(&window);
        this->uiObjectManager->drawAllHearts(&window);

        if (player->getHealth() <= 0)
            this->isGameOver = true;

        
        
        window.display();
    }
}
void Game::initialize()
{
    this->assetLoader->loadTextures();
    this->assetLoader->loadSprites();
    if (!this->backgroundTexture.loadFromFile("Assets/background.png"))
    {
        // Handle error
        std::cerr << "[!] Cannot load file: \"" << "Assets/background.png" << "\". Exiting...\n";
        std::cin.get();
        exit(1);
    }
    this->background.setTexture(backgroundTexture);
    this->background.setPosition(0, 0);
    this->background.setScale(0.7, 0.7);
    this->uiObjectManager->initialize();
    if (!this->gameOverTexture.loadFromFile("Assets/gameOver.png")) {
        // Handle error
        std::cerr << "[!] Cannot load file: \"" << "Assets/gameOver.png" << "\". Exiting...\n";
        std::cin.get();
        exit(1);
    }
    this->gameOverSprite.setTexture(gameOverTexture);
    
	srand(time(NULL));
	
    
}

#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;

	//game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	this->points = 0;
	this->enemySpawnTimerMax = this->enemySpawnTimer;
	this->enemySpawnTimer = 10.f;
	
	this->maxEnemies = 10;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(videoMode, "sfml projet", sf::Style::Titlebar | sf::Style::Close);
	
	this->window->setFramerateLimit(60);
}
void Game::initEnemies()
{
	this->enemy.setPosition(10.f, 10.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(sf::Color::Red);/*
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f)*/;
		
	
	
}
//public functions
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::spawnEnemy()
{
	this->enemy.setPosition(
		static_cast<float>(rand()% static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f
	);

	this->enemy.setFillColor(sf::Color::Green);
	this->enemies.push_back(this->enemy);
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
	
}

void Game::updateMousePosition()
{
	//update the mouse position
	//mouse pos relative to window
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
{


	//update the timer/spawn enemy and reset the timer
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;

		}
		else
		{
			this->enemySpawnTimer += 0.f;
		}
	}
	//move the enemy
	for (int i=0; i < this->enemies.size(); i++)
	{
		bool deleted = false;
		this->enemies[i].move(0.f, 5.f);

		//check if clicked opun
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
			{
				deleted = true;
				this->points += 10.f;
			}
		}
		//is the enemie is at the botom of the screen
		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			deleted = true;
		}

		if (deleted)
			this->enemies.erase(this->enemies.begin() + i);
	}

}

void Game::update()
{
	this->pollEvents();
	this->updateMousePosition();
	
	this->updateEnemies();
	//mouse pos
	
	
}

void Game::RenderEnemies()
{
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}

void Game::render()
{
	/*render gameobjects*/


	this->window->clear();
	this->RenderEnemies();

	
	this->window->display();
}

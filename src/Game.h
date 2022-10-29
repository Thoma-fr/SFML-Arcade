#pragma once
#include <iostream>
#include <vector>
#include<ctime>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
//game engine
class Game
{
private:
    sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	
	//mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	//Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;


	//private functions
	void initVariables();
	void initWindow();
	void initEnemies();
	
	//GameObject
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	
public:
	Game();
	virtual ~Game();
	//accessors
	const bool running() const;
	
	void spawnEnemy();

	void pollEvents();
	void updateMousePosition();

	void updateEnemies();
	void update();
	void RenderEnemies();
	void render();
};


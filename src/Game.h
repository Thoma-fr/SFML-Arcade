#pragma once

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
	//private functions
	void initVariables();
	void initWindow();
public:
	Game();
	virtual ~Game();
	//accessors
	const bool running() const;

	void pollEvents();
	void update();
	void render();
};


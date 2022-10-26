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
    sf::RenderWindow window;

	void initVariables();
	void initWindow();
public:
	Game();
	virtual ~Game();

	void update();
	void render();
};


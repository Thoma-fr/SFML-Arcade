#include <iostream>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "sfml projet",sf::Style::Titlebar| sf::Style::Close);
	sf::Event ev;

	while (window.isOpen())
	{
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}

		window.clear(sf::Color::Blue);
		window.display();



		
	}
	
    return 0;
}

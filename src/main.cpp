#include <iostream>
#include "Game.h"

int main()
{
	//Init GameEngine
	Game game;

	while (game.running())
	{
		game.update();
		game.render();
	}
    return 0;
}

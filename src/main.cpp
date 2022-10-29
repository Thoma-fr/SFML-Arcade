
#include "Game.h"

int main()
{
	//Init GameEngine
	std::srand(static_cast<unsigned>(time(NULL)));

	Game game;

	while (game.running())
	{
		game.update();
		game.render();
	}
    return 0;
}

#include <iostream>
#include "BaseGame/BaseGame.h"

class Game : public BaseGame
{
	void Start() override
	{

	}

	void Update() override
	{

	}

	void End() override
	{

	}
};

int main()
{
	Game* game = new Game();

	game->Run();

	delete game;

	system("pause");
	return 0;
}
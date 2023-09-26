#include <iostream>
#include "BaseGame/BaseGame.h"

class Game : public BaseGame
{
	Shape* shape = nullptr;

	void Start()
	{
		shape = new Shape(renderer);
		shape->CreateSquare();

		renderer->ClearScreenWithColor(1, 0, 0, 1);
	}

	void Update()
	{
		shape->Draw();
	}

	void End()
	{
		delete shape;
	}
};

int main()
{
	Game* game = new Game();

	game->Run();

	delete game;
	return 0;
}
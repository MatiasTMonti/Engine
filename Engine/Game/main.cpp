#include <iostream>
#include "BaseGame/BaseGame.h"

class Game : public BaseGame
{
	Shape* shape = nullptr;

	void Start()
	{
		shape = new Shape(renderer);
		shape->CreateTriangle();
		shape->SetScale(50, 50, 50);
		shape->SetPosition(400.0f, 500.0f, 1.0f);
		shape->SetColor(glm::vec3(-1.0f, 0.5f, 0.0f));
	}

	void Update()
	{

		shape->SetPosition(0.0, -0.1, 0.0);
		//shape->SetScale(0.1f, 0.1f, 0.1f);
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
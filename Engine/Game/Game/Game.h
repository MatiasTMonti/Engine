#pragma once

#include "BaseGame/BaseGame.h"

class Game : public BaseGame
{
private:
	Sprite* player;
	Sprite* city;
	Sprite* sign;
	Animation* idle;
	Animation* up;
	Animation* down;
	Animation* left;
	Animation* right;
	Animation* signIdle;

	float time;

public:
	Game();
	~Game();

	void Start()override;
	void Update()override;
	void End()override;
};
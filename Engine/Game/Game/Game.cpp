#include "Game.h"
#include "Timer/Timer.h"

Game::Game()
{
	player = nullptr;
	city = nullptr;
	sign = nullptr;
	idle = nullptr;
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;
	signIdle = nullptr;
	time = 0;
}

Game::~Game()
{
	if (player != nullptr) {
		player = nullptr;
		delete player;
	}

	if (city != nullptr) {
		city = nullptr;
		delete city;
	}

	if (sign != nullptr) {
		sign = nullptr;
		delete sign;
	}

	if (idle != nullptr) {
		idle = nullptr;
		delete idle;
	}

	if (up != nullptr) {
		up = nullptr;
		delete up;
	}

	if (down != nullptr) {
		down = nullptr;
		delete down;
	}

	if (left != nullptr) {
		left = nullptr;
		delete left;
	}

	if (right != nullptr) {
		right = nullptr;
		delete right;
	}

	if (signIdle != nullptr) {
		signIdle = nullptr;
		delete signIdle;
	}
}

void Game::Start()
{
	city = new Sprite(renderer, "res/city.png");
	city->SetColor(glm::vec3(1, 1, 1));
	city->SetPosition(400, 400, 0);
	city->SetScale(800, 800, 100);

	sign = new Sprite(renderer, "res/Sonic_Mania_Sprite_Sheet.png");
	sign->SetColor(glm::vec3(1, 1, 1));
	sign->SetPosition(400, 400, 0);
	sign->SetScale(100, 100, 100);

	player = new Sprite(renderer, "res/Sonic_Mania_Sprite_Sheet.png");
	player->SetColor(glm::vec3(1, 1, 1));
	player->SetPosition(400, 200, 0);
	player->SetScale(100, 100, 100);

	idle = new Animation();
	up = new Animation();
	down = new Animation();
	right = new Animation();
	left = new Animation();
	signIdle = new Animation();

	idle->AddFrame(3.2, 7.6, 10, 23.5, 830, 465);

	up->AddFrame(8.55, 14.49, 10, 23.5, 830, 465);
	up->AddFrame(9.75, 14.49, 10, 23.5, 830, 465);
	up->AddFrame(10.95, 14.49, 10, 23.5, 830, 465);
	down->AddFrame(8.55, 14.49, 10, 23.5, 830, 465);
	down->AddFrame(9.75, 14.49, 10, 23.5, 830, 465);
	down->AddFrame(10.95, 14.49, 10, 23.5, 830, 465);
	left->AddFrame(8.55, 14.49, 10, 23.5, 830, 465);
	left->AddFrame(9.75, 14.49, 10, 23.5, 830, 465);
	left->AddFrame(10.95, 14.49, 10, 23.5, 830, 465);
	right->AddFrame(8.55, 14.49, 10, 23.5, 830, 465);
	right->AddFrame(9.75, 14.49, 10, 23.5, 830, 465);
	right->AddFrame(10.95, 14.49, 10, 23.5, 830, 465);

	signIdle->AddFrame(2.54, 1.2, 7.42, 16.6, 830, 465);
	signIdle->AddFrame(3.53, 1.2, 7.42, 16.6, 830, 465);
	signIdle->AddFrame(4.51, 1.2, 7.42, 16.6, 830, 465);
	signIdle->AddFrame(5.48, 1.2, 7.42, 16.6, 830, 465);
	signIdle->AddFrame(6.48, 1.2, 7.42, 16.6, 830, 465);

	player->SetCollider(true);
	sign->SetCollider(true);
}

void Game::Update()
{
	glm::vec3 lastPosition = player->GetPosition();

	if (IsKeyPressed(KEY_W))
	{
		player->Translate(0, 5, 0);
		player->UpdateAnimation(up);
	}
	else if (IsKeyPressed(KEY_S))
	{
		player->Translate(0, -5, 0);
		player->UpdateAnimation(down);
	}
	else if (IsKeyPressed(KEY_A))
	{
		player->Translate(-5, 0, 0);
		player->UpdateAnimation(left);
	}
	else if (IsKeyPressed(KEY_D))
	{
		player->Translate(5, 0, 0);
		player->UpdateAnimation(right);
	}
	else
	{
		player->UpdateAnimation(idle);
	}

	sign->UpdateAnimation(signIdle);

	if (CollisionManager::CheckCollision(player, sign))
	{
		player->SetPosition(lastPosition.x, lastPosition.y, lastPosition.z);
	}

	city->Draw();
	sign->Draw();
	player->Draw();
}

void Game::End()
{
	delete player;
	delete city;
}
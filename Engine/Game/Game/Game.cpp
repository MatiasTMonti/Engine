#include "Game.h"
#include "Timer/Timer.h"

Game::Game()
{
	player = nullptr;
	sign = nullptr;
	grass = nullptr;
	pikachu = nullptr;
	pikachuMove = nullptr;
	pikachuIdle = nullptr;
	pikachuImage = nullptr;
	pikachuImageIdle = nullptr;
	pikachuText = nullptr;
	PikachuTextIdle = nullptr;
	signIdle = nullptr;
	idle = nullptr;
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;
	time = 0;
}

Game::~Game()
{
	if (player != nullptr) {
		player = nullptr;
		delete player;
	}

	if (sign != nullptr) {
		sign = nullptr;
		delete sign;
	}

	if (grass != nullptr) {
		grass = nullptr;
		delete grass;
	}

	if (pikachu != nullptr) {
		pikachu = nullptr;
		delete pikachu;
	}

	if (pikachuImage != nullptr) {
		pikachuImage = nullptr;
		delete pikachuImage;
	}

	if (pikachuImageIdle != nullptr) {
		pikachuImageIdle = nullptr;
		delete pikachuImageIdle;
	}

	if (pikachuText != nullptr) {
		pikachuText = nullptr;
		delete pikachuText;
	}

	if (PikachuTextIdle != nullptr) {
		PikachuTextIdle = nullptr;
		delete PikachuTextIdle;
	}

	if (pikachuIdle != nullptr) {
		pikachuIdle = nullptr;
		delete pikachuIdle;
	}

	if (pikachuMove != nullptr) {
		pikachuMove = nullptr;
		delete pikachuMove;
	}

	if (signIdle != nullptr) {
		signIdle = nullptr;
		delete signIdle;
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
}

void Game::Start()
{
	grass = new Sprite(renderer, "res/bg.png");
	grass->SetColor(glm::vec3(1, 1, 1));
	grass->SetPosition(400, 400, 0);
	grass->SetScale(800, 800, 100);

	sign = new Sprite(renderer, "res/Sonic_Mania_Sprite_Sheet.png");
	sign->SetColor(glm::vec3(1, 1, 1));
	sign->SetPosition(550, 550, 0);
	sign->SetScale(100, 100, 100);

	player = new Sprite(renderer, "res/Sonic_Mania_Sprite_Sheet.png");
	player->SetColor(glm::vec3(1, 1, 1));
	player->SetPosition(400, 200, 0);
	player->SetScale(100, 100, 100);

	pikachu = new Sprite(renderer, "res/pikachu.png");
	pikachu->SetColor(glm::vec3(1, 1, 1));
	pikachu->SetPosition(400, 200, 0);
	pikachu->SetScale(100, 100, 100);

	pikachuImage = new Sprite(renderer, "res/pikachu.png");
	pikachuImage->SetColor(glm::vec3(1, 1, 1));
	pikachuImage->SetPosition(100, 700, 0);
	pikachuImage->SetScale(200, 200, 100);

	pikachuText = new Sprite(renderer, "res/pikachu.png");
	pikachuText->SetColor(glm::vec3(1, 1, 1));
	pikachuText->SetPosition(650, 100, 0);
	pikachuText->SetScale(300, 100, 100);

	signIdle = new Animation();
	idle = new Animation();
	up = new Animation();
	down = new Animation();
	right = new Animation();
	left = new Animation();

	pikachuIdle = new Animation();
	pikachuMove = new Animation();
	pikachuImageIdle = new Animation();
	PikachuTextIdle = new Animation();

	pikachuIdle->AddFrame(136, 346, 40, 48, 847, 396, 500, 3);
	pikachuMove->AddFrame(536, 300, 46, 37, 847, 396, 500, 4);

	pikachuImageIdle->AddFrame(365, 0, 181, 148, 847, 396, 500, 1);
	PikachuTextIdle->AddFrame(597, 100, 244, 32, 847, 396, 500, 1);

	signIdle->AddFrame(133, 150, 49.5, 100, 832, 830, 1000, 4);

	idle->AddFrame(390, 98, 98 / 3, 43, 830, 465, 500, 3);
	up->AddFrame(282, 401, 181 / 6, 29, 830, 465, 500, 6);
	down->AddFrame(22, 354, 126 / 4, 40, 830, 465, 500, 4);
	right->AddFrame(155, 199, 124 / 3, 43, 830, 465, 500, 3);
	left->AddFrame(379, 152, 159 / 4, 43, 830, 465, 500, 4);

	pikachu->SetAnimation(pikachuIdle);
	pikachu->SetAnimation(pikachuMove);
	pikachuImage->SetAnimation(pikachuImageIdle);
	pikachuText->SetAnimation(PikachuTextIdle);

	player->SetAnimation(up);
	sign->SetAnimation(signIdle);

	player->SetCollider(true);
	sign->SetCollider(true);
	pikachu->SetCollider(true);
}

void Game::Update()
{
	glm::vec3 lastPosition = pikachu->GetPosition();
	glm::vec3 lastPositionP2 = player->GetPosition();

	if (IsKeyPressed(KEY_W))
	{
		pikachu->Translate(0, 5, 0);
		pikachu->SetAnimation(pikachuMove);
	}
	else if (IsKeyPressed(KEY_S))
	{
		pikachu->Translate(0, -5, 0);
		pikachu->SetAnimation(pikachuMove);
	}
	else if (IsKeyPressed(KEY_A))
	{
		pikachu->Translate(-5, 0, 0);
		pikachu->SetAnimation(pikachuMove);
	}
	else if (IsKeyPressed(KEY_D))
	{
		pikachu->Translate(5, 0, 0);
		pikachu->SetAnimation(pikachuMove);
	}
	else
	{
		pikachu->SetAnimation(pikachuIdle);
	}

	if (IsKeyPressed(KEY_UP))
	{
		player->Translate(0, 5, 0);
		player->SetAnimation(up);
	}
	else if (IsKeyPressed(KEY_DOWN))
	{
		player->Translate(0, -5, 0);
		player->SetAnimation(down);
	}
	else if (IsKeyPressed(KEY_LEFT))
	{
		player->Translate(-5, 0, 0);
		player->SetAnimation(left);
	}
	else if (IsKeyPressed(KEY_RIGHT))
	{
		player->Translate(5, 0, 0);
		player->SetAnimation(right);
	}
	else
	{
		player->SetAnimation(idle);
	}

	if (CollisionManager::CheckCollision(player, sign))
	{
		player->SetPosition(lastPositionP2.x, lastPositionP2.y, lastPositionP2.z);
	}

	if (CollisionManager::CheckCollision(pikachu, sign))
	{
		pikachu->SetPosition(lastPosition.x, lastPosition.y, lastPosition.z);
	}

	player->UpdateAnimation();
	sign->UpdateAnimation();

	pikachuImage->UpdateAnimation(pikachuImageIdle);
	pikachuText->UpdateAnimation(PikachuTextIdle);

	grass->Draw();
	pikachu->UpdateAnimation();
	pikachu->Draw();
	pikachuImage->UpdateAnimation();
	pikachuImage->Draw();
	pikachuText->UpdateAnimation();
	pikachuText->Draw();
	sign->Draw();
	player->Draw();
}

void Game::End()
{
	delete signIdle;
	delete idle;
	delete up;
	delete down;
	delete right;
	delete left;
	delete player;
	delete sign;
	delete grass;
	delete pikachu;
	delete pikachuIdle;
	delete pikachuMove;
	delete pikachuImage;
	delete pikachuImageIdle;
	delete pikachuText;
	delete PikachuTextIdle;
}
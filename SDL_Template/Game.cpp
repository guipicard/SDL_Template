#include "Game.h"

Game::~Game()
{
	//if (sprite != nullptr)
	//{
	//	delete sprite;
	//	sprite = nullptr;
	//}

	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}
}

void Game::Init(SDL_Renderer* graphics)
{
	//sprite = new Sprite(100, 10, 250, 250);
	player = new Player();
	player->LoadTexture(graphics, "assets/bomberman.png");


	//sprite->LoadTexture(graphics, "assets/smiley.png");
}

void Game::Update()
{
	
}

void Game::Draw(SDL_Renderer* graphics)
{
	if (player != nullptr)
	{
		player->Draw(graphics);
	}
}
#pragma once
#include "SDL.h"
#include "Sprite.h"
#include "Player.h"
class Game
{

public:
	~Game();

	void Init(SDL_Renderer* graphics);

	void Update();
	void Draw(SDL_Renderer* graphics);

private:
	//Sprite* sprite;
	Player* player;
};


#include <Windows.h>
#include <SDL.h>

#include "Game.h"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		SDL_Log("Error : %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window* win = SDL_CreateWindow(
		"Game App",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_UTILITY
	);

	SDL_Renderer* graphics = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);

	if (graphics == nullptr)
	{
		SDL_Log("Error : %s\n", SDL_GetError());
		return 1;
	}

	// Init Game
	Game* game = new Game();
	game->Init(graphics);

	bool running = true;
	SDL_Event events;

	while (running)
	{
		while (SDL_PollEvent(&events))
		{
			switch (events.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}

		SDL_SetRenderDrawColor(graphics, 0, 0, 0, 255);
		SDL_RenderClear(graphics);

		game->Update();
		game->Draw(graphics);

		// Push back buffer to the front buffer
		SDL_RenderPresent(graphics);
	}

	delete game;
	game = nullptr;

	SDL_DestroyRenderer(graphics);
	SDL_DestroyWindow(win);
	SDL_Quit();

	SDL_Log("PROGRAM END\n");
	return 0;
}

//// yellow
//SDL_SetRenderDrawColor(graphics, 0, 0, 255, SDL_ALPHA_OPAQUE);

//// send 3 lines (triangle) to back buffer
//SDL_RenderDrawLine(graphics, 0, 0, 0, 240);
//SDL_RenderDrawLine(graphics, 0, 240, 240, 240);
//SDL_RenderDrawLine(graphics, 240, 240, 240, 0);
//SDL_RenderDrawLine(graphics, 240, 0, 0, 0);

//// red
//SDL_SetRenderDrawColor(graphics, 255, 255, 0, 255);

//// send rectangle to back buffer
//rectangle.x += 1 * deltaTime;
//if (rectangle.x > 800) 
//{
//	rectangle.x = 0;
//	rectangle.y += rectangle.h;
//}

//if (rectangle.y > 600)
//{
//	rectangle.y = 0;
//}
//
//SDL_RenderFillRect(graphics, &rectangle);
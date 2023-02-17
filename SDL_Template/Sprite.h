#pragma once
#include "SDL_image.h"
#include <string>

class Sprite
{
public:
	Sprite();
	Sprite(float x, float y, float w, float h);
	~Sprite();

	bool LoadTexture(SDL_Renderer* graphics, const std::string& filename);

	void Draw(SDL_Renderer* graphics);

	SDL_Texture* m_Texture;
	float m_X;
	float m_Y;
	float m_W;
	float m_H;

private:
	void Draw(SDL_Renderer* graphics, float x, float y, float w, float h);

};


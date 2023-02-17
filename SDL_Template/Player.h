#pragma once
#include "Sprite.h"
class Player
{
public:
	Player();
	Player(float x, float y, float w, float h);
	~Player();

	bool LoadTexture(SDL_Renderer* graphics, const std::string& filename);

	void Draw(SDL_Renderer* graphics);

	SDL_Texture* m_Texture;
	float m_x;
	float m_y;
	float m_h;
	float m_w;


private:
	Sprite* sprite = new Sprite(m_x, m_y, m_h, m_w);
	void Draw(SDL_Renderer* graphics, float m_x, float m_y, float m_h, float m_w);
};


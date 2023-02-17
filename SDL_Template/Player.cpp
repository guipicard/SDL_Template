#include "Player.h"


Player::Player()
	:Player(50.0f, 50.0f, 50.0f, 50.0f)
{
	

}

Player::Player(float x, float y, float w, float h)
	:m_Texture(nullptr),
	m_x(x),
	m_y(y),
	m_h(h),
	m_w(w)
{
	
}

Player::~Player()
{
	if (m_Texture != nullptr)
	{
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	}
}

bool Player::LoadTexture(SDL_Renderer* graphics, const std::string& filename)
{
	m_Texture = IMG_LoadTexture(graphics, filename.c_str());
	if (m_Texture == nullptr)
	{
		SDL_Log("Error loading texture %s", filename.c_str());
		return false;
	}

	return true;
}

void Player::Draw(SDL_Renderer* graphics)
{
	Draw(graphics, m_x, m_y, m_w, m_h);
}

void Player::Draw(SDL_Renderer* graphics, float x, float y, float w, float h)
{
	SDL_Rect dest = SDL_Rect();
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;

	SDL_RenderCopyEx(graphics, m_Texture, nullptr, &dest, 0.0, nullptr, SDL_FLIP_NONE);
}

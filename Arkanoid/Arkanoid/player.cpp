#include "engine.h"
#include "player.h"

void Player::update()
{
	if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_A])
	{
		pos.x -= 200 * delta_time;
	}

	if (keys[SDL_SCANCODE_RIGHT] || keys[SDL_SCANCODE_D])
	{
		pos.x += 200 * delta_time;
	}
}

void Player::draw()
{
	SDL_SetRenderDrawColor (render, 255, 255, 255, 255);
	SDL_Rect rect = { (int)pos.x, (int)pos.y, 32, 8 };
	SDL_RenderFillRect (render, &rect);
}
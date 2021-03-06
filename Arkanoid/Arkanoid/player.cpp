#include "engine.h"
#include "player.h"

#include "game.h"

void Player::update()
{
	if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_A])
	{
		pos.x -= speed * delta_time;
	}

	if (keys[SDL_SCANCODE_RIGHT] || keys[SDL_SCANCODE_D])
	{
		pos.x += speed * delta_time;
	}

	draw ();
}

void Player::draw ()
{
	SDL_SetRenderDrawColor (render, 255, 255, 255, 255);
	SDL_FRect rect = { pos.x, pos.y, WIDTH, HEIGHT };
	SDL_RenderFillRectF (render, &rect);
}

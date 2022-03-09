#include "game.h"

bool keys[SDL_SCANCODE_LEFT + SDL_SCANCODE_A + SDL_SCANCODE_RIGHT + SDL_SCANCODE_D] = { false };
std::vector<colliding_component*> colliding_components = {};

void Game::add_collidable (colliding_component* add)
{
	colliding_components.push_back (add);
}

void Game::set_up ()
{
	wall* a_wall = new wall (0, 0, 1, 600);
	add_collidable (a_wall);
	a_wall = new wall (0, 0, 1, 400);
	add_collidable (a_wall);
	a_wall = new wall (600, 0, 1, 600);
	add_collidable (a_wall);
	bottom* a_bottom = new bottom (0, 400, 600, 1);
	add_collidable (a_bottom);

	int x{ 2 }, y{ 2 };
	int add_x{ 32 }, add_y{ 19 };
	for (int i = 1; i < 8; ++i)
	{
		for (int k = 1; k < 20; ++k)
		{
			//this is heap allocation, i don't want to delete it though. is this legal?
			brick* a_brick = new brick (x, y, 30, 15);
			add_collidable (a_brick);
			x += add_x;
		}
		y += add_y;
		x = 2;
	}
}

void Game::update ()
{
	for (int i = 0; i < colliding_components.size (); ++i)
	{
		colliding_components[i]->update ();
	}
}
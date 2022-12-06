#include "raylib.h"
#include "Classes.h"

int asteroid_count;

void Level::update()
{
	time_from_start += 1 / 60.f;

	player.update();
}

void Level::render()
{
	player.render();
}

void Level::reset()
{
	player = {};

	
}



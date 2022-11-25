#pragma once
#include "Player.h"

class Level
{
	public:
		Camera camera = {};

		Player player = {};
		Vector2 size;
		float time_from_start = 0;

		void reset();
		void update();
		void render();
};

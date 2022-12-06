#pragma once
#include <math.h>
#include "raylib.h"

struct Bullet
{
	public:
		Vector2 position;
		Vector2 speed;
		float radius;
		float player_rotation_when_shot;
		int lifeSpawn;
		bool active;
		Color color;
};

class Player
{
	public:
		int rotation = 0;
		int score = 0;

		Color color = RAYWHITE;

		virtual ~Player() = default;

		virtual void initialize();
		virtual void update();
		virtual void render();
};

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


class Asteroid
{
	public:
		Vector2 position;
		Vector2 speed;
		float radius;
		Color color = PURPLE;
		bool active;

		virtual void initialize(Vector2 new_position, Vector2 new_speed, Vector2 new_radius, bool active_state);
		virtual void update();
		virtual void render();
};







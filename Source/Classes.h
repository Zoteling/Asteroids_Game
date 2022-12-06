#pragma once
#include <math.h>
#include <raylib.h>

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

		Color color = GREEN;

		virtual ~Player() = default;

		virtual void initialize();
		virtual void update();
		virtual void render();
};

enum Size { big, medium, small };

class Asteroid
{
public:
	Vector2 position;
	Vector2 speed;
	float radius;
	Color color;
	bool active;

	Size size;

	virtual void initialize();
	virtual void update(Asteroid* specific_asteroid);
	virtual void render(Asteroid* specific_asteroid);

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







#pragma once
#include <math.h>
#include <raylib.h>
#include <vector>

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

		int max_bullets = 20;
		Bullet bullets[20] = { };
};

enum Size { big, medium, small };

class Asteroid
{
	public:
		Asteroid(Vector2 _position, Vector2 _speed, float _radius, Size _size);
		virtual ~Asteroid() = default;

		Vector2 position = {};
		Vector2 speed = {};
		float radius = {};
		Size size = Size::big;

		//void initialize(Vector2 new_position, Vector2 new_speed, int new_radius, bool active_state, Size new_size);
		void update();
		void render();
		void respawn();
};

//const int max_big_asteroid_count = 4;
//const int max_medium_asteroid_count = 8;
//const int max_small_asteroid_count = 16;

class Level
{
public:
	//Camera camera = {};

	Player player = {};
	Vector2 size;
	float time_from_start = 0;

	int score = 0;

	virtual ~Level() = default;

	void reset();
	void update();
	void render();

	//Asteroids
	std::vector<Asteroid> big_asteroids;
	std::vector<Asteroid> medium_asteroids;
	std::vector<Asteroid> small_asteroids;

	const int asteroid_speed = 2;
};






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
		int player_base_height = 40;
		int rotation = 0;
		int score = 0;
		int max_bullets = 20;
		Bullet bullets[20] = { };
		Color color = RAYWHITE;
		Texture2D texture;
		Texture2D texture_bullets;

		virtual ~Player() = default;

		virtual void initialize();
		virtual void update();
		virtual void render();
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
		Texture2D texture;
		float rotation;

		void update();
		void render();
};

enum class State
{
	main_menu,
	game,
	end_game
};

class GameState
{
	public:
		State current_state;
};

class Level
{
	public:
		Player player = {};
		Vector2 size;
		float time_from_start = 0;
		const int asteroid_speed = 2;
		int score = 0;

		virtual ~Level() = default;

		void reset();
		void update(GameState* state);
		void render();

		//Asteroids
		std::vector<Asteroid> big_asteroids;
		std::vector<Asteroid> medium_asteroids;
		std::vector<Asteroid> small_asteroids;
};






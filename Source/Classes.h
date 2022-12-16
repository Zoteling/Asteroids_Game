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

		virtual ~Player() = default;

		virtual void initialize();
		virtual void update(Sound shooting_sound);
		virtual void render(Texture2D player_texture, Texture2D bullet_texture);
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
		float rotation;

		void update();
		void render(Texture2D asteroid_texture);
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
		float time_from_start = 0;
		const int asteroid_speed = 2;
		int score = 0;

		virtual ~Level() = default;

		void reset();
		void update(GameState* state, Sound sounds[1]);
		void render(Texture2D textures[3]);

		//Asteroids
		std::vector<Asteroid> big_asteroids;
		std::vector<Asteroid> medium_asteroids;
		std::vector<Asteroid> small_asteroids;
};






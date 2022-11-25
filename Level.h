#pragma once

class Player
{
public:
	int rotation = 0;
	int score = 0;

	virtual ~Player() = default;

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

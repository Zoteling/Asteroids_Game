#include "Classes.h"

void Asteroid::update()
{
	position.x += speed.x;
	position.y += speed.y;

	if (position.x > GetScreenWidth() + radius) position.x = -(radius);
	else if (position.x < 0 - radius) position.x = GetScreenWidth() + radius;
	if (position.y > GetScreenHeight() + radius) position.y = -(radius);
	else if (position.y < 0 - radius) position.y = GetScreenHeight() + radius;

	rotation += 1;
}

Asteroid::Asteroid(Vector2 _position, Vector2 _speed, float _radius, Size _size)
{
	this->position = _position;
	this->speed = _speed;
	this->radius = _radius;
	this->size = _size;
	this->rotation = GetRandomValue(0, 360);
}

void Asteroid::render(Texture2D asteroid_texture)
{
	switch (size)
	{
	
		case big:
		{
			int size = 160;
			int half_size = 80;

			Rectangle source = Rectangle(0, 0, 101, 84);
			Rectangle dest = Rectangle(position.x, position.y, size, size);

			DrawTexturePro(asteroid_texture, source, dest, Vector2(half_size, half_size), rotation, WHITE);

			break;
		}
		case medium:
		{
			int size = 80;
			int half_size = 40;

			Rectangle source = Rectangle(0, 0, 101, 84);
			Rectangle dest = Rectangle(position.x, position.y, size, size);

			DrawTexturePro(asteroid_texture, source, dest, Vector2(half_size, half_size), rotation, WHITE);
			break;
		}
		case small:
		{
			int size = 40;
			int half_size = 20;

			Rectangle source = Rectangle(0, 0, 101, 84);
			Rectangle dest = Rectangle(position.x, position.y, size, size);

			//DrawCircleV(position, radius, RED);
			DrawTexturePro(asteroid_texture, source, dest, Vector2(half_size, half_size), rotation, WHITE);
			break;
		}
	}

}


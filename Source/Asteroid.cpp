#include "Classes.h"

void Asteroid::update()
{
	position.x += speed.x;
	position.y += speed.y;

	if (position.x > GetScreenWidth() + radius) position.x = -(radius);
	else if (position.x < 0 - radius) position.x = GetScreenWidth() + radius;
	if (position.y > GetScreenHeight() + radius) position.y = -(radius);
	else if (position.y < 0 - radius) position.y = GetScreenHeight() + radius;
}

Asteroid::Asteroid(Vector2 _position, Vector2 _speed, float _radius, Size _size)
{
	this->position = _position;
	this->speed = _speed;
	this->radius = _radius;
	this->size = _size;
}

//void Asteroid::respawn()
//{
//	int random = GetRandomValue(0, 3);
//
//	if(random == 0) position.x = -radius;
//	if(random == 1) position.x = position.x = GetScreenWidth() + radius;
//	if(random == 2) position.y = -radius;
//	if(random == 3) position.y = GetScreenHeight() + radius;
//
//	//active = true;
//}

void Asteroid::render()
{
	switch (size)
	{
		case big:
		{
			DrawCircleV(position, radius, RED);
			break;
		}
		case medium:
		{
			DrawCircleV(position, radius, RED);
			break;
		}
		case small:
		{
			DrawCircleV(position, radius, RED);
			break;
		}
	}

}


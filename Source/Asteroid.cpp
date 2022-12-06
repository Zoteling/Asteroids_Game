#include "Classes.h"

void Asteroid::update()
{

	if (active) 
	{
		position.x += speed.x; 
		position.y += speed.y; 

		if (position.x > GetScreenWidth() + radius) position.x = -(radius);
		else if (position.x < 0 - radius) position.x = GetScreenWidth() + radius; 
		if (position.y > GetScreenHeight() + radius) position.y = -(radius);
		else if (position.y < 0 - radius) position.y = GetScreenHeight() + radius; 
	}

}

void Asteroid::render()
{
	switch (size)
	{
		case big:
		{
			if (active)  
			{
				DrawCircleV(position, radius, RED); 
			}

			break;
		}
		case medium:
		{
			if (active) 
			{
				DrawCircleV(position, radius, RED); 
			}
			break;
		}
		case small:
		{
			if (active) 
			{
				DrawCircleV(position, radius, RED); 
			}

			break;
		}
	}

}


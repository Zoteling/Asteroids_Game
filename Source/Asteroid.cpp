#include "Classes.h"

void Asteroid::update()
{

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


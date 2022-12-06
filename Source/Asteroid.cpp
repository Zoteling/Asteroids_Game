#include "Classes.h"

void Asteroid::initialize()
{


}

void Asteroid::update(Asteroid* specific_asteroid)
{
	if (specific_asteroid->active) 
	{
		specific_asteroid->position.x += specific_asteroid->speed.x; 
		specific_asteroid->position.y += specific_asteroid->speed.y; 
	}
    
}

void Asteroid::render(Asteroid* specific_asteroid)
{
	switch (specific_asteroid->size)
	{
		case big:
		{
			if (specific_asteroid->active) 
			{
				DrawCircleV(specific_asteroid->position, specific_asteroid->radius, RED); 
			}

			break;
		}
		case medium:
		{
			if (specific_asteroid->active) 
			{
				DrawCircleV(specific_asteroid->position, specific_asteroid->radius, RED); 
			}
			break;
		}
		case small:
		{
			if (specific_asteroid->active) 
			{
				DrawCircleV(specific_asteroid->position, specific_asteroid->radius, RED); 
			}

			break;
		}
	}

}


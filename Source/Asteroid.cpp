#include "Classes.h"

void Asteroid::initialize(Vector2 new_position, Vector2 new_speed, Vector2 new_radius, bool active_state)
{


}

void Asteroid::update(Asteroid* specific_asteroid)
{
    
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


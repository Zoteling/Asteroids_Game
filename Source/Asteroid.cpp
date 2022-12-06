#include "Classes.h"

//void Asteroid::initialize(Vector2 new_position, Vector2 new_speed, int new_radius, bool active_state, Size new_size)
//{
//	position = new_position;
//	speed = new_speed;
//	radius = new_radius;
//	active = active_state;
//}

void Asteroid::update()
{


	//if (active && CheckCollisionCircles(shoot[i].position, shoot[i].radius, bigMeteor[a].position, bigMeteor[a].radius))
	//{
	//	shoot[i].active = false;
	//	shoot[i].lifeSpawn = 0;
	//	bigMeteor[a].active = false;
	//	destroyedMeteorsCount++;

	//	for (int j = 0; j < 2; j++)
	//	{
	//		if (midMeteorsCount % 2 == 0)
	//		{
	//			mediumMeteor[midMeteorsCount].position = Vector2(bigMeteor[a].position.x, bigMeteor[a].position.y);
	//			mediumMeteor[midMeteorsCount].speed = (Vector2){ cos(shoot[i].rotation * DEG2RAD) * METEORS_SPEED * -1, sin(shoot[i].rotation * DEG2RAD) * METEORS_SPEED * -1 };
	//		}
	//		else
	//		{
	//			mediumMeteor[midMeteorsCount].position = (Vector2){ bigMeteor[a].position.x, bigMeteor[a].position.y };
	//			mediumMeteor[midMeteorsCount].speed = (Vector2){ cos(shoot[i].rotation * DEG2RAD) * METEORS_SPEED, sin(shoot[i].rotation * DEG2RAD) * METEORS_SPEED };
	//		}

	//		mediumMeteor[midMeteorsCount].active = true;
	//		midMeteorsCount++;
	//	}
	//	//bigMeteor[a].position = (Vector2){-100, -100};
	//	bigMeteor[a].color = RED;
	//	a = MAX_BIG_METEORS;
	//}
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


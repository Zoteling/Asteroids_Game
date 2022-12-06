#include "Classes.h"

void Asteroid::initialize()
{


}

void Asteroid::update()
{
    
}

void Asteroid::render()
{
	for (int i = 0; i < MAX_GIGA_METEOR; i++)
	{
		if (gigaMeteor[i].active) DrawCircleV(gigaMeteor[i].position, gigaMeteor[i].radius, RED);

		else DrawCircleV(bigMeteor[i].position, bigMeteor[i].radius, Fade(DARKBLUE, 0.3f));
	}


	for (int i = 0; i < MAX_MID_METEOR; i++)
	{
		if (midMeteor[i].active) DrawCircleV(midMeteor[i].position, midMeteor[i].radius, RED);

		else DrawCircleV(midMeteor[i].position, mediumMeteor[i].radius, Fade(DARKBLUE, 0.3f));

	}

	for (int i = 0; i < MAX_SMOL_METEOR; i++)
	{
		if (smolMeteor[i].active) DrawCircleV(smolMeteor[i].position, smolMeteor[i].radius, RED);

		else DrawCircleV(smolMeteor[i].position, smolMeteor[i].radius, Fade(DARKBLUE, 0.3f));
	}
}


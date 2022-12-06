#include "raylib.h"
#include "Classes.h"

const int big_asteroid_count = 4;
const int medium_asteroid_count = 8;
const int small_asteroid_count = 16;

//Asteroids
Asteroid big_asteroid[big_asteroid_count];
Asteroid medium_asteroid[medium_asteroid_count];
Asteroid small_asteroid[small_asteroid_count];

void Level::update()
{
	time_from_start += 1 / 60.f;

	player.update();

}

void Level::render()
{
	player.render();
}

void Level::reset()
{
	player = {};

    for (int i = 0; i < big_asteroid_count; i++)
    {
        int posx, posy;
        bool correctRange = false;

        posx = GetRandomValue(0, GetScreenWidth());

        while (!correctRange)
        {
            if (posx > GetScreenWidth() / 2 - 150 && posx < GetScreenWidth() / 2 + 150) posx = GetRandomValue(0, GetScreenWidth());
            else correctRange = true;
        }

        correctRange = false;

        posy = GetRandomValue(0, GetScreenHeight());

        while (!correctRange)
        {
            if (posy > GetScreenWidth() / 2 - 150 && posy < GetScreenWidth() / 2 + 150)  posy = GetRandomValue(0, GetScreenWidth());
            else correctRange = true;
        }

        big_asteroid[i].position = Vector2(posx, posy);

        /*correctRange = false;
        velx = GetRandomValue(-METEORS_SPEED, METEORS_SPEED);
        vely = GetRandomValue(-METEORS_SPEED, METEORS_SPEED);

        while (!correctRange)
        {
            if (velx == 0 && vely == 0)
            {
                velx = GetRandomValue(-METEORS_SPEED, METEORS_SPEED);
                vely = GetRandomValue(-METEORS_SPEED, METEORS_SPEED);
            }
            else correctRange = true;
        }*/

        big_asteroid[i].speed = Vector2(0, 0);
        big_asteroid[i].radius = 40;
        big_asteroid[i].active = true;
        big_asteroid[i].color = PURPLE;
    }

    ////asteroids
    //for (int i = 0; i < MAX_MEDIUM_METEORS; i++)
    //{
    //    mediumMeteor[i].position = (Vector2){ -100, -100 };
    //    mediumMeteor[i].speed = (Vector2){ 0,0 };
    //    mediumMeteor[i].radius = 20;
    //    mediumMeteor[i].active = false;
    //    mediumMeteor[i].color = BLUE;
    //}

    //for (int i = 0; i < MAX_SMALL_METEORS; i++)
    //{
    //    smallMeteor[i].position = (Vector2){ -100, -100 };
    //    smallMeteor[i].speed = (Vector2){ 0,0 };
    //    smallMeteor[i].radius = 10;
    //    smallMeteor[i].active = false;
    //    smallMeteor[i].color = BLUE;
    //}

    //midMeteorsCount = 0;
    //smallMeteorsCount = 0;
}



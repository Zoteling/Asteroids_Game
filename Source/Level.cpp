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

    //render asteroids
    for (int i = 0; i < big_asteroid_count; i++)
    {

    }

    for (int i = 0; i < big_asteroid_count; i++)
    {

    }
}

void Level::reset()
{
	player = {};

    for (int i = 0; i < big_asteroid_count; i++)
    {
        int posx, posy;

        int random_x = GetRandomValue(0, 1);
        if (random_x == 1) posx = GetRandomValue(0, GetScreenWidth() / 2 - 200);
        else posx = GetRandomValue(GetScreenWidth() / 2 + 200, GetScreenWidth());

        int random_y = GetRandomValue(0, 1);
        if (random_y == 1) posy = GetRandomValue(0, GetScreenHeight() / 2 - 200);
        else posy = GetRandomValue(GetScreenHeight() / 2 + 200, GetScreenHeight());

        big_asteroid[i].position = Vector2(posx, posy);

        Asteroid = new Asteroid();

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



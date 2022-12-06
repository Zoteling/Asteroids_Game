#include "raylib.h"
#include "Classes.h"

const int max_big_asteroid_count = 4;
const int max_medium_asteroid_count = 8;
const int max_small_asteroid_count = 16;

//Asteroids
Asteroid big_asteroids[max_big_asteroid_count] = {};
//Asteroid medium_asteroids[max_medium_asteroid_count];
//Asteroid small_asteroids[max_small_asteroid_count];

int big_asteroid_count;
int medium_asteroid_count;
int small_asteroid_count;

const int asteroid_speed = 2;

void Level::update()
{
	time_from_start += 1 / 60.f;

	player.update();

    for (int i = 0; i < big_asteroid_count; i++)
    {
        big_asteroids[i].update();
    }

}

void Level::render()
{
	player.render();

    //render asteroids
    for (int i = 0; i < max_big_asteroid_count; i++) big_asteroids[i].render();
    //for (int i = 0; i < max_medium_asteroid_count; i++) medium_asteroids[i].render();
    //for (int i = 0; i < max_medium_asteroid_count; i++) small_asteroids[i].render();
}

void Level::reset()
{
	player = {};

    player.initialize();
    /*big_asteroids[big_asteroid_count] = {};
    medium_asteroids = {};
    small_asteroids[small_asteroid_count] = {};*/

    for (int i = 0; i < max_big_asteroid_count; i++)
    {
        //Random position
        int posx, posy;

        int random_x = GetRandomValue(0, 1);
        if (random_x == 1) posx = GetRandomValue(0, GetScreenWidth() / 2 - 200);
        else posx = GetRandomValue(GetScreenWidth() / 2 + 200, GetScreenWidth());

        int random_y = GetRandomValue(0, 1);
        if (random_y == 1) posy = GetRandomValue(0, GetScreenHeight() / 2 - 200);
        else posy = GetRandomValue(GetScreenHeight() / 2 + 200, GetScreenHeight());

        Vector2 position = Vector2((float)posx, (float)posy);

        //Random rotation
        int velx = 0;
        int vely = 0;

        while (!(velx == 0 && vely == 0))
        {
            velx = GetRandomValue(-asteroid_speed, asteroid_speed);
            vely = GetRandomValue(-asteroid_speed, asteroid_speed);
        }

        Vector2 speed = Vector2(velx, vely);

        Asteroid new_asteroid;
        new_asteroid.position = position;
        new_asteroid.speed = speed;
        new_asteroid.active = true;
        new_asteroid.radius = 40;
        new_asteroid.size = Size::big;

        big_asteroids[i] = new_asteroid;
    }

    //asteroids
    /*for (int i = 0; i < max_medium_asteroid_count; i++)
    {
        medium_asteroids[i].position = Vector2(-100, -100);
        medium_asteroids[i].speed = Vector2(0, 0);
        medium_asteroids[i].radius = 20;
        medium_asteroids[i].active = false;
    }

    for (int i = 0; i < max_small_asteroid_count; i++)
    {
        small_asteroids[i].position = Vector2(-100, -100);
        small_asteroids[i].speed = Vector2(0, 0);
        small_asteroids[i].radius = 10;
        small_asteroids[i].active = false;
    }*/

    big_asteroid_count = max_big_asteroid_count;
    medium_asteroid_count = 0;
    small_asteroid_count = 0;
}



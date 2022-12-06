#include "raylib.h"
#include "Classes.h"

void check_for_bullet_asteroid_collisions(Bullet* bullet, Asteroid* asteroid, Level* level)
{
    if (CheckCollisionCircles(bullet->position, bullet->radius, asteroid->position, asteroid->radius))
    {
        bullet->active = false;
        bullet->lifeSpawn = 0;
        asteroid->active = false;
        //score++

        if (asteroid->size == big)
        {
            for (int i = 0; i < 2; i++)
            {
                //Speed
                level->medium_asteroids[level->medium_asteroid_count].position = Vector2(asteroid->position.x, asteroid->position.y);

                //Rotation
                if (level->medium_asteroid_count % 2 == 0)
                    level->medium_asteroids[level->medium_asteroid_count].speed = Vector2(cosf(bullet->player_rotation_when_shot * DEG2RAD) * level->asteroid_speed * -1, sinf(bullet->player_rotation_when_shot * DEG2RAD) * level->asteroid_speed * -1);
                else level->medium_asteroids[level->medium_asteroid_count].speed = Vector2(cosf(bullet->player_rotation_when_shot * DEG2RAD) * level->asteroid_speed, sinf(bullet->player_rotation_when_shot * DEG2RAD) * level->asteroid_speed);

                //Set active and update count
                level->medium_asteroids[level->medium_asteroid_count].active = true;
                level->medium_asteroid_count++;
            }

            level->big_asteroid_count--;
        }
        else if (asteroid->size == medium)
        {
            for (int i = 0; i < 2; i++)
            {
                //Speed
                level->small_asteroids[level->small_asteroid_count].position = Vector2(asteroid->position.x, asteroid->position.y);

                //Rotation
                if (level->small_asteroid_count % 2 == 0)
                    level->small_asteroids[level->small_asteroid_count].speed = Vector2(cosf(bullet->player_rotation_when_shot * DEG2RAD) * level->asteroid_speed * -1, sinf(bullet->player_rotation_when_shot * DEG2RAD) * level->asteroid_speed * -1);
                else level->small_asteroids[level->small_asteroid_count].speed = Vector2(cosf(bullet->player_rotation_when_shot * DEG2RAD) * level->asteroid_speed, sinf(bullet->player_rotation_when_shot * DEG2RAD) * level->asteroid_speed);

                //Set active and update count
                level->small_asteroids[level->small_asteroid_count].active = true;
                level->small_asteroid_count++;
            }

            level->medium_asteroid_count--;
        }
        else level->small_asteroid_count--;
    }
}

void Level::update()
{
	time_from_start += 1 / 60.f;

	player.update();

    for (int i = 0; i < big_asteroid_count; i++)
    {
        big_asteroids[i].update();
        for (int x = 0; x < player.max_bullets; x++)
            if (big_asteroids[i].active && player.bullets[x].active) check_for_bullet_asteroid_collisions(&player.bullets[x], &big_asteroids[i], this);
    }

    for (int i = 0; i < medium_asteroid_count; i++)
    {
        medium_asteroids[i].update();
        for (int x = 0; x < player.max_bullets; x++)
            if (medium_asteroids[i].active && player.bullets[x].active) check_for_bullet_asteroid_collisions(&player.bullets[x], &medium_asteroids[i], this);
    }

    for (int i = 0; i < small_asteroid_count; i++)
    {
        small_asteroids[i].update();
        for (int x = 0; x < player.max_bullets; x++)
            if (small_asteroids[i].active && player.bullets[x].active) check_for_bullet_asteroid_collisions(&player.bullets[x], &small_asteroids[i], this);
    }
}

void Level::render()
{
	player.render();

    //render asteroids
    for (int i = 0; i < max_big_asteroid_count; i++) big_asteroids[i].render();
    for (int i = 0; i < max_medium_asteroid_count; i++) medium_asteroids[i].render();
    for (int i = 0; i < small_asteroid_count; i++) small_asteroids[i].render();
}

void Level::reset()
{
	player = {};

    player.initialize();
    big_asteroids[big_asteroid_count] = {};
    medium_asteroids[medium_asteroid_count] = {};
    small_asteroids[small_asteroid_count] = {};

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
        new_asteroid.radius = 80;
        new_asteroid.size = Size::big;

        big_asteroids[i] = new_asteroid;
    }

    //Handle asteroid collissions
    //for (int x = 0; x < max_big_asteroid_count; x++) check_for_bullet_asteroid_collisions(&bullets[i], &level->big_asteroids[x]);
    //for (int x = 0; x < max_big_asteroid_count; x++) check_for_bullet_asteroid_collisions(&bullets[i], &medium_asteroids[x]);
    //for (int x = 0; x < max_big_asteroid_count; x++) check_for_bullet_asteroid_collisions(&bullets[i], &small_asteroids[x]);


    //asteroids
    for (int i = 0; i < max_medium_asteroid_count; i++)
    {
        Asteroid new_asteroid;
        new_asteroid.position = Vector2(-100, -100);
        new_asteroid.speed = Vector2(0, 0);
        new_asteroid.radius = 40;
        new_asteroid.active = false;
        new_asteroid.size = Size::medium;

        medium_asteroids[i] = new_asteroid;
    }

    for (int i = 0; i < max_small_asteroid_count; i++)
    {
        Asteroid new_asteroid;
        new_asteroid.position = Vector2(-100, -100);
        new_asteroid.speed = Vector2(0, 0);
        new_asteroid.radius = 20;
        new_asteroid.active = false;
        new_asteroid.size = Size::small;

        small_asteroids[i] = new_asteroid;
    }

    big_asteroid_count = max_big_asteroid_count;
    medium_asteroid_count = 0;
    small_asteroid_count = 0;
}



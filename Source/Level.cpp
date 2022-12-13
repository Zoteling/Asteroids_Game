#include "raylib.h"
#include "Classes.h"

void spawn_asteroid(std::vector<Asteroid>* asteroids_vector, int asteroid_radius)
{
    int diameter = asteroid_radius * 2;

    //spawned position
    int posx, posy;

    posx = GetRandomValue(-200, GetScreenWidth() + 200);
    posy = GetRandomValue(-200, GetScreenHeight() + 200);

    Rectangle asteroid_rec;
    asteroid_rec.width = diameter;
    asteroid_rec.height = diameter;
    asteroid_rec.x = posx;
    asteroid_rec.y = posy;

    Rectangle map;
    map.width = GetScreenWidth();
    map.height = GetScreenHeight();
    map.x = 0;
    map.y = 0;

    while (CheckCollisionRecs(map, asteroid_rec))
    {
        posx = GetRandomValue(-200, GetScreenWidth() + 200);
        posy = GetRandomValue(-200, GetScreenHeight() + 200);

        asteroid_rec.x = posx;
        asteroid_rec.y = posy;
    }

    Vector2 position = Vector2((float)posx, (float)posy);

    //target position
    int target_posx, target_posy;

    int random_x = GetRandomValue(0, 1);
    if (random_x == 1) target_posx = GetRandomValue(0, GetScreenWidth() / 2 - diameter);
    else target_posx = GetRandomValue(GetScreenWidth() / 2 + diameter, GetScreenWidth());

    int random_y = GetRandomValue(0, 1);
    if (random_y == 1) target_posy = GetRandomValue(0, GetScreenHeight() / 2 - diameter);
    else target_posy = GetRandomValue(GetScreenHeight() / 2 + diameter, GetScreenHeight());

    Vector2 target_position = Vector2((float)target_posx, (float)target_posy);

    //direction
    Vector2 speed = Vector2((position.x - target_position.x) * .002f, (position.y - target_position.y) * .002f);

    //spawn
    Asteroid asteroid = Asteroid(position, speed, asteroid_radius, big);
    asteroids_vector->push_back(asteroid);
}

void check_for_bullet_asteroid_collisions(Bullet bullets[], Level* level, Player* player)
{
    for (int i = 0; i < player->max_bullets; i++)
    {
        //Big asteroids
        for (int j = 0; j < level->big_asteroids.size(); j++)
        {
            if (CheckCollisionCircles(bullets[i].position, bullets[i].radius, level->big_asteroids[j].position, level->big_asteroids[j].radius) && bullets[i].active)
            {
                //Destroy bullets
                bullets[i].active = false;
                bullets[i].lifeSpawn = 0;

                spawn_asteroid(&level->big_asteroids, 80);

                //Make Smaller Chunks
                for (int i = 0; i < 2; i++)
                {
                    //Speed
                    Vector2 position = Vector2(level->big_asteroids[j].position.x, level->big_asteroids[j].position.y);

                    //Rotation
                    Vector2 speed = {};

                    if (level->medium_asteroids.size() % 2 == 0)
                        speed = Vector2(cosf(bullets[i].player_rotation_when_shot * DEG2RAD) * level->asteroid_speed * -1, sinf(bullets[i].player_rotation_when_shot * DEG2RAD) * level->asteroid_speed * -1);
                    else speed = Vector2(cosf(bullets[i].player_rotation_when_shot * DEG2RAD) * level->asteroid_speed, sinf(bullets[i].player_rotation_when_shot * DEG2RAD) * level->asteroid_speed);

                    float radius = 40.0f;

                    Asteroid new_medium_asteroid = Asteroid(position, speed, radius, medium);

                    //Set active and update count
                    level->medium_asteroids.push_back(new_medium_asteroid);
                }

                //Destroy asteroid
                Asteroid* a = &level->big_asteroids[j];
                //delete a;
                level->big_asteroids.erase(level->big_asteroids.begin() + j);
                //delete a;

                //increment score
                level->score++;

                return;
            }
        }
        //Medium asteroids
        for (int j = 0; j < level->medium_asteroids.size(); j++)
        {
            if (CheckCollisionCircles(bullets[i].position, bullets[i].radius, level->medium_asteroids[j].position, level->medium_asteroids[j].radius) && bullets[i].active)
            {
                //Destroy bullets
                bullets[i].active = false;
                bullets[i].lifeSpawn = 0;

                //Make Smaller Chunks
                for (int i = 0; i < 2; i++)
                {
                    //Speed
                    Vector2 position = Vector2(level->medium_asteroids[j].position.x, level->medium_asteroids[j].position.y);

                    //Rotation
                    Vector2 speed = {};

                    if (level->small_asteroids.size() % 2 == 0)
                        speed = Vector2(cosf(bullets[i].player_rotation_when_shot * DEG2RAD) * level->asteroid_speed * -1, sinf(bullets[i].player_rotation_when_shot * DEG2RAD) * level->asteroid_speed * -1);
                    else speed = Vector2(cosf(bullets[i].player_rotation_when_shot * DEG2RAD) * level->asteroid_speed, sinf(bullets[i].player_rotation_when_shot * DEG2RAD) * level->asteroid_speed);

                    float radius = 20.0f;

                    Asteroid new_small_asteroid = Asteroid(position, speed, radius, small);

                    //Set active and update count
                    level->small_asteroids.push_back(new_small_asteroid);
                }

                //Destroy asteroid
                Asteroid* a = &level->medium_asteroids[j];
                //delete a;
                level->medium_asteroids.erase(level->medium_asteroids.begin() + j);

                //increment score
                level->score++;

                return;
            }
        }
        for (int j = 0; j < level->small_asteroids.size(); j++)
        {
            if (CheckCollisionCircles(bullets[i].position, bullets[i].radius, level->small_asteroids[j].position, level->small_asteroids[j].radius) && bullets[i].active)
            {
                //Destroy bullets
                bullets[i].active = false;
                bullets[i].lifeSpawn = 0;

                //Destroy asteroid
                Asteroid* a = &level->small_asteroids[j];
                level->small_asteroids.erase(level->small_asteroids.begin() + j);
                

                //increment score
                level->score++;

                return;
            }
        }
    }
}

void check_if_any_asteroid_is_out_of_bounds(Asteroid* asteroid, std::vector<Asteroid>* asteroids, int index)
{
    int offset = 300;

    if (asteroid->position.x > GetScreenWidth() + offset ||
        asteroid->position.x < 0 - offset ||
        asteroid->position.y > GetScreenHeight() + offset ||
        asteroid->position.y < 0 - offset)
            asteroids->erase(asteroids->begin() + index);
}

void player_asteroid_collision(Player* player, Asteroid* asteroid, Level* level) 
{
    Vector2 player_position = Vector2(GetScreenWidth() / 2, GetScreenHeight() / 2);

    if (CheckCollisionCircles(player_position, player->rotation, asteroid->position, asteroid->radius))
    {
        current_state = State::END_GAME;
        level->reset();
    }

}

void Level::update()
{
	time_from_start += 1 / 60.f;

	player.update();

    for (int i = 0; i < big_asteroids.size(); i++)
    {
        big_asteroids[i].update();
        check_if_any_asteroid_is_out_of_bounds(&big_asteroids[i], &big_asteroids, i);
    }
    for (int i = 0; i < medium_asteroids.size(); i++)
    {
        medium_asteroids[i].update();
        check_if_any_asteroid_is_out_of_bounds(&medium_asteroids[i], &medium_asteroids, i);
    }
    for (int i = 0; i < small_asteroids.size(); i++)
    {
        small_asteroids[i].update();
        check_if_any_asteroid_is_out_of_bounds(&small_asteroids[i], &small_asteroids, i);
    }

    check_for_bullet_asteroid_collisions(player.bullets, this, &player);
}

void Level::render()
{
	player.render();

    //render asteroids
    for (int i = 0; i < big_asteroids.size(); i++) big_asteroids[i].render();
    for (int i = 0; i < medium_asteroids.size(); i++) medium_asteroids[i].render();
    for (int i = 0; i < small_asteroids.size(); i++) small_asteroids[i].render();
}

void Level::reset()
{
	player = {};

    player.initialize();
    //also delete
    big_asteroids.clear();
    medium_asteroids.clear();
    small_asteroids.clear();

    for (int i = 0; i < 10; i++)
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

        while ((velx == 0 && vely == 0))
        {
            velx = GetRandomValue(-asteroid_speed, asteroid_speed);
            vely = GetRandomValue(-asteroid_speed, asteroid_speed);
        }

        Vector2 speed = Vector2(velx, vely);

        Asteroid new_asteroid{position, speed, 80, Size::big };
        
        big_asteroids.push_back(new_asteroid);
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
    }


    //starting big asteroids
    for (int i = 0; i < 4; i++) spawn_asteroid(&big_asteroids, 80);
}



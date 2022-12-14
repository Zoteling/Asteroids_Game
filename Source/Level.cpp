#include "raylib.h"
#include "Classes.h"

void spawn_asteroid(std::vector<Asteroid>* asteroids_vector, int asteroid_radius)
{
    float diameter = (float)asteroid_radius * 2.0f;

    //spawned position
    float posx, posy;

    posx = (float)GetRandomValue(-200, GetScreenWidth() + 200);
    posy = (float)GetRandomValue(-200, GetScreenHeight() + 200);

    Rectangle asteroid_rec;
    asteroid_rec.width = diameter;
    asteroid_rec.height = diameter;
    asteroid_rec.x = posx;
    asteroid_rec.y = posy;

    //map
    Rectangle map;
    map.width = (float)GetScreenWidth();
    map.height = (float)GetScreenHeight();
    map.x = 0;
    map.y = 0;

    //get position outside of map
    while (CheckCollisionRecs(map, asteroid_rec))
    {
        posx = (float)GetRandomValue(-200, GetScreenWidth() + 200);
        posy = (float)GetRandomValue(-200, GetScreenHeight() + 200);

        asteroid_rec.x = posx;
        asteroid_rec.y = posy;
    }

    Vector2 position = Vector2((float)posx, (float)posy);

    //target position
    int target_posx, target_posy;

    int random_x = GetRandomValue(0, 1);
    if (random_x == 1) target_posx = GetRandomValue(0, GetScreenWidth() / 2 - (int)diameter);
    else target_posx = GetRandomValue(GetScreenWidth() / 2 + (int)diameter, GetScreenWidth());

    int random_y = GetRandomValue(0, 1);
    if (random_y == 1) target_posy = GetRandomValue(0, GetScreenHeight() / 2 - (int)diameter);
    else target_posy = GetRandomValue(GetScreenHeight() / 2 + (int)diameter, GetScreenHeight());

    Vector2 target_position = Vector2((float)target_posx, (float)target_posy);

    //direction
    Vector2 speed = Vector2((position.x - target_position.x) * .002f, (position.y - target_position.y) * .002f);

    //spawn
    Asteroid asteroid = Asteroid(position, speed, (float)asteroid_radius, big);
    asteroids_vector->push_back(asteroid);
}

void check_for_bullet_asteroid_collisions(Bullet bullets[], Level* level, Player* player, Sound asteroid_explosion_sound)
{
    for (int i = 0; i < player->max_bullets; i++)
    {
        //Big asteroids
        for (int j = 0; j < level->big_asteroids.size(); j++)
        {
            if (CheckCollisionCircles(bullets[i].position, bullets[i].radius, level->big_asteroids[j].position, level->big_asteroids[j].radius) && bullets[i].active)
            {
                PlaySoundMulti(asteroid_explosion_sound);

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
                level->big_asteroids.erase(level->big_asteroids.begin() + j);

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
                PlaySoundMulti(asteroid_explosion_sound);

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
                level->medium_asteroids.erase(level->medium_asteroids.begin() + j);

                //increment score
                level->score++;

                return;
            }
        }
        //Small asteroids
        for (int j = 0; j < level->small_asteroids.size(); j++)
        {
            if (CheckCollisionCircles(bullets[i].position, bullets[i].radius, level->small_asteroids[j].position, level->small_asteroids[j].radius) && bullets[i].active)
            {
                PlaySoundMulti(asteroid_explosion_sound);

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

void player_asteroid_collision(Player* player, Asteroid* asteroid, Level* level, GameState*state, Sound player_death)
{
    Vector2 player_position = Vector2((float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 2));

    if (CheckCollisionCircles(player_position, (float)(player->player_base_height / 2), asteroid->position, asteroid->radius))
    {
        PlaySoundMulti(player_death);
        state->current_state = State::end_game;
        level->reset();
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

void Level::update(GameState* state, Sound sounds[3])
{
	time_from_start += 1 / 60.f;

	player.update(sounds[0]);

    for (int i = 0; i < big_asteroids.size(); i++)
    {
        big_asteroids[i].update();
        check_if_any_asteroid_is_out_of_bounds(&big_asteroids[i], &big_asteroids, i);
        player_asteroid_collision(&player, &big_asteroids[i], this, state, sounds[2]);
    }
    for (int i = 0; i < medium_asteroids.size(); i++)
    {
        medium_asteroids[i].update();
        check_if_any_asteroid_is_out_of_bounds(&medium_asteroids[i], &medium_asteroids, i);
        player_asteroid_collision(&player, &medium_asteroids[i], this, state, sounds[2]);
    }
    for (int i = 0; i < small_asteroids.size(); i++)
    {
        small_asteroids[i].update();
        check_if_any_asteroid_is_out_of_bounds(&small_asteroids[i], &small_asteroids, i);
        player_asteroid_collision(&player, &small_asteroids[i], this, state, sounds[2]);
    }

    check_for_bullet_asteroid_collisions(player.bullets, this, &player, sounds[1]);
}

void Level::render(Texture2D textures[3])
{
	player.render(textures[0], textures[1]);

    //render asteroids
    for (int i = 0; i < big_asteroids.size(); i++) big_asteroids[i].render(textures[2]);
    for (int i = 0; i < medium_asteroids.size(); i++) medium_asteroids[i].render(textures[2]);
    for (int i = 0; i < small_asteroids.size(); i++) small_asteroids[i].render(textures[2]);
}

void Level::reset()
{
	player = {};

    player.initialize();

    big_asteroids.clear();
    medium_asteroids.clear();
    small_asteroids.clear();

    //starting big asteroids
    for (int i = 0; i < 4; i++) spawn_asteroid(&big_asteroids, 80);
}

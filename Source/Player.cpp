#include "raylib.h"
#include "Level.h"
#include <math.h>

const int max_bullets = 20;
static Bullet bullets[max_bullets] = { };



void Player::initialize()
{
    // Initialization of bullets
    for (int i = 0; i < max_bullets; i++)
    {
        bullets[i].position = Vector2(0, 0);
        bullets[i].speed = Vector2(0, 0);
        bullets[i].radius = 10;
        bullets[i].active = false;
        bullets[i].lifeSpawn = 0;
        bullets[i].color = WHITE;
    }
}

void Player::update()
{
    //Movement
    if (IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT))
    {
        rotation -= 2;
    }
    else if (IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT))
    {
        rotation += 2;
    }

    //Shooting
    if (IsKeyPressed(KEY_SPACE))
    {
        float bullet_speed_multiplier = 10.0f;

        for (int i = 0; i < max_bullets; i++)
        {
            if (!bullets[i].active)
            {
                /* Fix so that this is ship height variable*///40.0f
                /*Fix cringe*/
                int PLAYER_BASE_SIZE = 40;
                int shipHeight = (int)((PLAYER_BASE_SIZE / 2) / tanf(20 * DEG2RAD));
                Vector2 pos_of_v1 = { (GetScreenWidth() / 2) + sinf(rotation * DEG2RAD) * (shipHeight), (GetScreenHeight() / 2) - cosf(rotation * DEG2RAD) * (shipHeight) };

                bullets[i].position = Vector2(pos_of_v1.x, pos_of_v1.y);
                bullets[i].active = true;
                bullets[i].speed.x = sinf(rotation * DEG2RAD) * bullet_speed_multiplier;
                bullets[i].speed.y = cosf(rotation * DEG2RAD) * bullet_speed_multiplier;
                bullets[i].player_rotation_when_shot = (float)rotation;
                break;
            }
        }
    }

    //Handle Active Bullets
    for (int i = 0; i < max_bullets; i++)
    {
        if (bullets[i].active)
        {
            //Increase lifetime
            bullets[i].lifeSpawn++;
            bullets[i].position.x += bullets[i].speed.x;
            bullets[i].position.y -= bullets[i].speed.y;

            //Despawn if old
            if (bullets[i].lifeSpawn >= 160)
            {
                bullets[i].position = Vector2(0, 0);
                bullets[i].speed = Vector2(0, 0);
                bullets[i].lifeSpawn = 0;
                bullets[i].active = false;
            }

            //Handle wall collisions
            if (bullets[i].position.x > GetScreenWidth() + bullets[i].radius ||
            bullets[i].position.x < 0 - bullets[i].radius ||
            bullets[i].position.y > GetScreenHeight() + bullets[i].radius ||
            bullets[i].position.y < 0 - bullets[i].radius)
            {
                bullets[i].active = false;
                bullets[i].lifeSpawn = 0;
            }
        }
    }
}

void Player::render()
{
    int PLAYER_BASE_SIZE = 40;
    int shipHeight = (int)((PLAYER_BASE_SIZE / 2) / tanf(20 * DEG2RAD));

    Vector2 v1 = { (GetScreenWidth() / 2) + sinf(rotation * DEG2RAD) * (shipHeight), (GetScreenHeight() / 2) - cosf(rotation * DEG2RAD) * (shipHeight) };
    Vector2 v2 = { (GetScreenWidth() / 2) - cosf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), (GetScreenHeight() / 2) - sinf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
    Vector2 v3 = { (GetScreenWidth() / 2) + cosf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), (GetScreenHeight() / 2) + sinf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
    DrawTriangle(v1, v2, v3, color);

    // Draw shoot
    for (int i = 0; i < max_bullets; i++)
    {
        if (bullets[i].active) DrawCircleV(bullets[i].position, bullets[i].radius, color);
    }
}

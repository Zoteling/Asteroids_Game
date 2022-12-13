#include "raylib.h"
#include "Classes.h"
#include <math.h>

void Player::initialize()
{
    texture = LoadTexture("Assets/Player.png");
    texture_bullets = LoadTexture("Assets/Bullet.png");

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
                int shipHeight = (int)((player_base_height / 2) / tanf(20 * DEG2RAD));
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
    Vector2 position = Vector2(75 / 2, 75 / 2);
    Rectangle source = Rectangle(0, 0, 98, 75);
    Rectangle dest = Rectangle((GetScreenWidth() / 2) - (0 / 2), (GetScreenHeight() / 2) - (0 / 2), 75, 75);

    DrawTexturePro(texture, source, dest, position, rotation, WHITE);

    // Draw shoot
    for (int i = 0; i < max_bullets; i++)
    {
        Vector2 bullet_position = Vector2(48 / 2, 46 / 2);
        Rectangle bullet_source = Rectangle(0, 0, 48, 46);
        Rectangle bullet_dest = Rectangle(bullets[i].position.x, bullets[i].position.y, 32, 32);

        if (bullets[i].active) DrawTexturePro(texture_bullets, bullet_source, bullet_dest, bullet_position, rotation, WHITE);
    }
}

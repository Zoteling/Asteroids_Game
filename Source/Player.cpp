#include "raylib.h"
#include "Classes.h"
#include <math.h>

void Player::initialize()
{
    texture = LoadTexture("Assets/Player.png");

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
    int shipHeight = (int)((player_base_height / 2) / tanf(20 * DEG2RAD));

    Vector2 v1 = { (GetScreenWidth() / 2) + sinf(rotation * DEG2RAD) * (shipHeight), (GetScreenHeight() / 2) - cosf(rotation * DEG2RAD) * (shipHeight) };
    Vector2 v2 = { (GetScreenWidth() / 2) - cosf(rotation * DEG2RAD) * (player_base_height / 2), (GetScreenHeight() / 2) - sinf(rotation * DEG2RAD) * (player_base_height / 2) };
    Vector2 v3 = { (GetScreenWidth() / 2) + cosf(rotation * DEG2RAD) * (player_base_height / 2), (GetScreenHeight() / 2) + sinf(rotation * DEG2RAD) * (player_base_height / 2) };
    DrawTriangle(v1, v2, v3, color);

    /*Vector2 position = Vector2(GetScreenWidth() / 2, GetScreenHeight() / 2);
    Rectangle source = Rectangle(GetScreenWidth() / 2, GetScreenHeight() / 2, 40, 40);
    Rectangle dest = Rectangle(GetScreenWidth() / 2, GetScreenHeight() / 2, 40, 40);

    DrawTexturePro(texture, source, dest, position, rotation, WHITE);*/
   // DrawTextureEx(texture, position, rotation, 2, WHITE);

    // Draw shoot
    for (int i = 0; i < max_bullets; i++)
    {
        if (bullets[i].active) DrawCircleV(bullets[i].position, bullets[i].radius, GREEN);
    }
}

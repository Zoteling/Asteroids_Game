#include "raylib.h"
#include "Level.h"
#include <math.h>

static Bullet shoot[10] = { 0 };

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

    }
}

void Player::render()
{
    int PLAYER_BASE_SIZE = 40;
    int shipHeight = (int)((PLAYER_BASE_SIZE / 2) / tanf(20 * DEG2RAD));

    Vector2 v1 = { (GetScreenWidth() / 2) + sinf(rotation * DEG2RAD) * (shipHeight), (GetScreenHeight() / 2) - cosf(rotation * DEG2RAD) * (shipHeight) };
    Vector2 v2 = { (GetScreenWidth() / 2) - cosf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), (GetScreenHeight() / 2) - sinf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
    Vector2 v3 = { (GetScreenWidth() / 2) + cosf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), (GetScreenHeight() / 2) + sinf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
    DrawTriangle(v1, v2, v3, GREEN);
}

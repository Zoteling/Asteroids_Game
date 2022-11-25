#include "raylib.h"
#include "Player.h"
#include "Level.h"
#include <math.h>

void Player::update(Level* level)
{
    /*if (IsKeyPressed(KEY_LEFT) && !IsKeyPressed(KEY_RIGHT))
    {
        rotation += 1;
    }
    else if (IsKeyPressed(KEY_RIGHT) && !IsKeyPressed(KEY_LEFT))
    {
        rotation -= 1;
    }*/
}

void Player::render(Level* level)
{
    /*float PLAYER_BASE_SIZE = 20.0f;

    Vector2 v1 = { (GetScreenWidth() / 2) + sinf(rotation * DEG2RAD) * (10), (GetScreenHeight() / 2) - cosf(rotation * DEG2RAD) * (10) };
    Vector2 v2 = { (GetScreenWidth() / 2) - cosf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), (GetScreenHeight() / 2) - sinf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
    Vector2 v3 = { (GetScreenWidth() / 2) + cosf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2), (GetScreenHeight() / 2) + sinf(rotation * DEG2RAD) * (PLAYER_BASE_SIZE / 2) };
    DrawTriangle(v1, v2, v3, MAROON);*/
}

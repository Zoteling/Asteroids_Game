#pragma once
#include "raylib.h"
#include "Level.h"

class Player
{
public:
    int rotation = 0;
    int score = 0;

    virtual ~Player() = default;

    virtual void update(Level* level);
    virtual void render(Level* level);
};

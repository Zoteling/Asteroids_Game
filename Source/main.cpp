/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Classes.h"
#include <string>
#include <stack>

void process_main_menu(GameState* state)
{
    DrawText("Asteroids But Worse", GetScreenWidth() / 2 - 220, 20, 40, RAYWHITE);
    DrawText("Press Enter To Play", GetScreenWidth() / 2 - 125, GetScreenHeight() / 2, 20, RAYWHITE);
    DrawText("Controls: Space to shoot! Arrow Keys to rotate!", GetScreenWidth() / 2 - 260, GetScreenHeight() - 120, 20, RAYWHITE);

    if (IsKeyPressed(KEY_ENTER))
    {
        state->current_state = State::game;
    }

}

void process_end_game(GameState* state, Level* level)
{
    DrawText("Asteroids But Worse", GetScreenWidth() / 2 - 220, 20, 40, RAYWHITE);
    DrawText(TextFormat("Score: %i", level->score), GetScreenWidth() / 2 - 165, 180, 80, RAYWHITE);
    DrawText("Press Enter To Retry", GetScreenWidth() / 2 - 125, GetScreenHeight() / 2, 20, RAYWHITE);

    if (IsKeyPressed(KEY_ENTER))
    {
        level->score = 0;
        state->current_state = State::game;
    }

}

void update(GameState* state, Level* level)
{
    if (IsKeyPressed(KEY_K))
    {
        state->current_state = State::end_game;
        level->reset();
    }
    level->update(state);
}

void render(Level* level)
{
    level->render();
    DrawText(TextFormat("Score: %i", level->score), 20, 20, 40, RAYWHITE);
}

void process_game(GameState* state, Level* level)
{
    update(state, level);
    render(level);
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    const int screenWidth = 1200;
    const int screenHeight = 800;

    // menu stuff goes here (for later) 

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Level level{};
    GameState state;
    state.current_state = State::main_menu;
    level.reset();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        DisableCursor();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();


        ClearBackground(BLACK);
        
        switch (state.current_state)
        {
            case State::main_menu:
                process_main_menu(&state);
                break;
            case State::game:
                process_game(&state, &level);
                break;
            case State::end_game:
                process_end_game(&state, &level);
                break;
        }

        //process_game_frame(&level);
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    EnableCursor();

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
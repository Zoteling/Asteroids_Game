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

enum class State
{
    MAIN_MENU,
    GAME,
    END_GAME
};

State current_state;
static int score = 0;

void process_main_menu()
{
    DrawText("ASTEROIDS BUT WORSE", GetScreenWidth() / 2 - 250, 20, 40, RAYWHITE);
    DrawText("PRESS ENTER TO PLAY", GetScreenWidth() / 2 - 125, GetScreenHeight() / 2, 20, RAYWHITE);

    if (IsKeyPressed(KEY_ENTER))
    {
        current_state = State::GAME;
    }

}

void process_end_game()
{
    DrawText("ASTEROIDS BUT WORSE", GetScreenWidth() / 2 - 250, 20, 40, RAYWHITE);
    DrawText(TextFormat("Score: %i", score), GetScreenWidth() / 2 - 165, 180, 80, RAYWHITE);
    DrawText("PRESS ENTER TO RETRY", GetScreenWidth() / 2 - 125, GetScreenHeight() / 2, 20, RAYWHITE);

    if (IsKeyPressed(KEY_ENTER))
    {
        score = 0;
        current_state = State::GAME;
    }

}

void update(Level* level)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        score++;
    }

    if (IsKeyPressed(KEY_K))
    {
        current_state = State::END_GAME;
        level->reset();
    }
    level->update();
}

void render(Level* level)
{
    DrawText(TextFormat("Score: %i", score), 20, 20, 40, RAYWHITE);
    level->render();
}

void process_game(Level* level)
{
    update(level);
    render(level);
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    
    const int screenWidth = 1200;//GetScreenWidth() * .5f;
    const int screenHeight = 800;//GetScreenHeight() * .5f;

    // menu stuff goes here (for later) 

    bool IsCursorOnScreen(void);
    {
        return true; 
    }

    void cursor_update(void); 
    {
        EnableCursor(); 
    }


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Level level{};

    level.reset();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        void cursor_update();
        {
            DisableCursor(); 
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();


        ClearBackground(GRAY);
        
        switch (current_state)
        {
            case State::MAIN_MENU:
                process_main_menu();
                break;
            case State::GAME:
                process_game(&level);
                break;
            case State::END_GAME:
                process_end_game();
                break;
        }

        //process_game_frame(&level);
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
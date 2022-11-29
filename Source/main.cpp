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
#include "Level.h"

#include <stack>

//enum class State
//{
//    MAIN_MENU,
//    GAME
//};
//
//std::stack<State> states;
//
//void main_menu()
//{
//    const Vector2i button_size = Vector2i(300, 64);
//    const int button_margin_y = 10;
//    const int button_count = 3;
//
//    Rectangle2i button_rect;
//    button_rect.min = (get_window_size() - button_size * Vector2i(1, button_count) - Vector2i(0, button_count - 1) * button_margin_y) / 2;
//    button_rect.size = button_size;
//
//    if (gui_button(button_rect, "PLAY"))
//    {
//        states.push(State::GAME);
//    }
//    button_rect.min.y += button_size.y + button_margin_y;
//
//    if (gui_button(button_rect, "OPTIONS"))
//    {
//        states.push(State::OPTIONS);
//    }
//
//    button_rect.min.y += button_size.y + button_margin_y;
//
//    if (gui_button(button_rect, "EXIT"))
//    {
//        close_window();
//    }


void update(Level* level)
{
    level->update();
}

void render(Level* level)
{
    level->render();
}

void process_game_frame(Level* level)
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
    const int screenWidth = 1920;
    const int screenHeight = 1080;

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

    Level level{ /*Vector2{(float)get_window_width(), (float)get_window_height()}*/ };

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

       /* State current_state = states.top();

        switch (current_state)
        {
        case State::MAIN_MENU:
            do_main_menu_frame();
            break;
        case State::GAME:
            do_game_frame(&level);
            break;
        }*/

        BeginDrawing();


        ClearBackground(BLACK);

        process_game_frame(&level);
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
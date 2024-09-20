#include "raylib.h"
#include "Food.h"
#include <iostream>
#include "Snake.h"

int main(void)
{
    const int screenWidth = 750;
    const int screenHeight = 750;
    Color LightGreen = { 173, 204, 96, 255 };
    Color DarkGreen = { 43, 51, 24, 255};
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    Snake snake;
    Food food;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(LightGreen);

        snake.DrawSnake();
        food.DrawFood();

        if (IsKeyPressed(KEY_DOWN)) {
            food.ChangePosition();
            std::cout << food.Position.x << ", " << food.Position.y;
        }

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

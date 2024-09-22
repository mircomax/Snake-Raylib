#include "raylib.h"
#include "Food.h"
#include <iostream>
#include "Snake.h"


void Update(Snake& snake, double interval) {
    static double accumulatedTime = 0.0;  // Accumulo del tempo per l'aggiornamento
    double deltaTime = GetFrameTime();     // Tempo trascorso tra i frame (secondi)

    accumulatedTime += deltaTime;  // Accumula il tempo trascorso

    // Logica di aggiornamento del movimento basata su un intervallo fisso
    while (accumulatedTime >= interval) {
        snake.MovimentoSnake();    // Muovi il serpente
        accumulatedTime -= interval;  // Riduci l'accumulo per il prossimo aggiornamento
    }
}

void ChangeDirection(Snake& snake) { // Per permettere all'user di muovere il serpente
    switch (GetKeyPressed()) {
    case KEY_DOWN:
        // Muove verso il basso se non sta andando verso l'alto
        if(snake.DirezioneMovimento.y !=  -1) snake.DirezioneMovimento = {0, 1}; 
        break;
    case KEY_UP:
        // Muove verso l'alto se non sta andando verso il basso
        if (snake.DirezioneMovimento.y != 1) snake.DirezioneMovimento = {0, -1}; 
        break;
    case KEY_RIGHT:
        // Muove verso destra se non sta andando verso sinistra
        if (snake.DirezioneMovimento.x != -1) snake.DirezioneMovimento = {1, 0}; 
        break;
    case KEY_LEFT:
        // Muove verso sinistra se non sta andando verso destra
        if (snake.DirezioneMovimento.x != 1) snake.DirezioneMovimento = {-1, 0}; 
        break;
    default: // Se non viene premuta nessuna freccia non succede niente
        break;
    }
}


int main(void)
{
    srand(time(NULL));
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

        ChangeDirection(snake); // Cambiare la direzione del serpente in base all'input dell'user
        snake.CollisioneCibo(food); // Controllare le collisioni a ogni frame

        ClearBackground(LightGreen);

        Update(snake, 0.3); // Fare muovere verso la direzione stabilita il serpente 
        snake.DrawSnake();
        food.DrawFood();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

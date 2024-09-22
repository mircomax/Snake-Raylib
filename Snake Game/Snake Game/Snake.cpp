#include "Snake.h"
#include "raylib.h"
#include "Food.h"
#include <deque>
#include <iostream>
#include <raymath.h>

Snake::Snake() {
    // Posizioni di partenza
    FirstPositionX = 6.0f;
    FirstPositionY = 6.0f;
    // Coordinate del serpente appena inizia il gioco
    body = { Vector2{FirstPositionX, FirstPositionY}, Vector2{FirstPositionX - 1.0f, FirstPositionY}, Vector2{FirstPositionX - 2.0f, FirstPositionY} };
    DirezioneMovimento = { 1,0 }; // Direzione iniziale
    head = { (body.at(0)).x * 30, (body.at(0)).y * 30, 30, 30 }; // Testa del serpente 
}

void Snake::DrawSnake() {
    for (int i = 0; i < body.size(); i++) { // For per disegnare ogni volta il serpente intero basandosi sul deque
        Rectangle snake = { (body.at(i)).x * 30, (body.at(i)).y * 30, 30, 30 }; 
        DrawRectangleRounded(snake, 0.5, 6, { 43, 51, 24, 255 });
    }
}

void Snake::MovimentoSnake() {
    head = { (body.at(0)).x * 30, (body.at(0)).y * 30, 30, 30 }; // Aggiornate coordinate della testa 

    // Cancellato l'ultimo tratto e spostato avanti per fare sembrare che si stia muovendo
    body.pop_back(); 
    body.push_front(Vector2Add(body.at(0),DirezioneMovimento));
}

void Snake::CollisioneCibo(Food& food) {
    if (CheckCollisionRecs(food.food, head)) { // Controllate collisioni tra cibo e testa del serpente
        food.ChangePosition(); // Cibo spostato in un punto casuale 
        body.push_front(Vector2Add(body.at(0), DirezioneMovimento)); // Aggiunto un tratto al serpente
    }
}


#include "Snake.h"
#include "raylib.h"
#include <deque>
#include <iostream>

Snake::Snake() {
    FirstPositionX = 6.0f;
    FirstPositionY = 6.0f;
    body = { Vector2{FirstPositionX, FirstPositionY}, Vector2{FirstPositionX - 1.0f, FirstPositionY}, Vector2{FirstPositionX - 2.0f, FirstPositionY} };
}

void Snake::DrawSnake() {
    for (int i = 0; i < body.size(); i++) {
        DrawRectangle((body.at(i)).x * 30, (body.at(i)).y * 30, 30, 30, DARKGREEN);
    }
}

void Snake::AllungaSnake() {

}
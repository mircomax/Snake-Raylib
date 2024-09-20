#include "Food.h"
#include "raylib.h"
#include <random>
#include <ctime>

Food::Food() {
	cellCount = 25;
	cellsize = 30;
	Position = {(float)(rand() % 25), (float)(rand() % 25) };
	srand(time(NULL));
}

void Food::DrawFood() {
	DrawRectangle(Position.x * cellsize, Position.y * cellsize, cellsize, cellsize, { 43, 51, 24, 255 });
}

void Food::ChangePosition() {
	Position = { (float)(rand() % 25), (float)(rand() % 25) };
}
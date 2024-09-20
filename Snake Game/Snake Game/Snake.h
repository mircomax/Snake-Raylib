#pragma once
#include "raylib.h"
#include <deque>
#include <iostream>

class Snake
{
public:
	std::deque<Vector2> body;
	float FirstPositionX, FirstPositionY;

	Snake();
	void DrawSnake();
	void AllungaSnake();
};


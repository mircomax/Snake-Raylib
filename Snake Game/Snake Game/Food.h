#pragma once
#include <raylib.h>
#include <random>
#include <ctime>

class Food
{
private:
	int cellCount;
	int cellsize;
public:
	Vector2 Position;
	Food();
	void DrawFood();
	void ChangePosition();
};


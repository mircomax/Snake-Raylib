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
	Rectangle food;
	Vector2 Position; // Coordinate del cibo
	Food();
	void DrawFood(); // Disegnare il cibo 
	void ChangePosition(); // Randomizzare la posizione del cibo
};


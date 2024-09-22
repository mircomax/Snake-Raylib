#include "Food.h"
#include "raylib.h"
#include <random>
#include <ctime>

Food::Food() {
	cellCount = 25; // Numero di cells immaginarie nell'interfaccia
	cellsize = 30; // Grandezza delle suddette cells
	Position = {(float)(rand() % 25), (float)(rand() % 25) }; // Randomizzata la posizione del cibo
	food = { Position.x * cellsize, Position.y * cellsize, (float)cellsize, (float)cellsize }; // Rettangolo usato per controllare collisioni
}

void Food::DrawFood() { //Disegnare il cibo
	food = { Position.x * cellsize, Position.y * cellsize, (float)cellsize, (float)cellsize }; // Aggiornate coordinate del rettangolo
	DrawRectangleRounded(food, 0.5, 6, { 43, 51, 24, 255 }); // Disegnato rettangolo
}

void Food::ChangePosition() {
	Position = { (float)(rand() % 25), (float)(rand() % 25) }; // Randomizzare posizione del cibo
}


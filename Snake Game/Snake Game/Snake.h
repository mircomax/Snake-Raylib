#pragma once
#include "raylib.h"
#include "Food.h"
#include <deque>
#include <iostream>

class Snake
{
public:
	std::deque<Vector2> body; // Deque che rappresenta il serpente
	float FirstPositionX, FirstPositionY;
	Vector2 DirezioneMovimento; // Direzione del Movimento
	Rectangle head; // Testa del serpente 

	Snake();
	void DrawSnake(); // Disegnarlo
	void MovimentoSnake(); // Funzione per muoverlo
	void CollisioneCibo(Food& food); // Funzione per gestire la collisione col cibo 
	void FinePartita();
};


#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include "character.h"

using namespace std;

class Game {
private:
	Character * players[2];
	int current_turn;
	int num_of_characters;
public:
	Game();
	void RemoveCharacter(int index);
	void AddCharacter(Character * c);
	void NextTurn();
	void Print();
	int getCharacters() { return num_of_characters; };
	int getTurn() { return current_turn; };
};

#endif
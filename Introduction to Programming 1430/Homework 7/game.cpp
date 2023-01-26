#include <iostream>
#include "game.h"
#include <string>
#include "character.h"

using namespace std;

Game::Game() {
	current_turn = 0;
	num_of_characters = 0;
}
void Game::RemoveCharacter(int index) {
	if (index < 0 || index >= num_of_characters) {
		cout << "Invalid index!" << endl;
	}
	else {
		num_of_characters--;
		players[num_of_characters] = nullptr;

	}
}
void Game::AddCharacter(Character* c) {
	if (num_of_characters == 2) {
		cout << "Character limit reached, please wait for the next game!" << endl;
	}
	else {

		players[num_of_characters] = c;
		num_of_characters++;
	}

}
void Game::NextTurn() {
	if (num_of_characters != 2) {
		cout << "Need more players!" << endl;
	}
	else {
		players[0]->Attack(players[1]);
		if (players[1]->getHealth() <= 0) {
			cout << players[0]->getName()<<" wins!" << endl;
		}
		else {
			players[1]->Attack(players[0]);
			if (players[0]->getHealth() <= 0) {
				cout << players[1]->getName()<<" wins!" << endl;
			}
			else {

			}
		}
	}
}
void Game::Print() {
	players[0]->Print();
	players[1]->Print();
}

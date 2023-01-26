#include <iostream>
#include <fstream>
#include <string>

#include "character.h"
#include "barbarian.h"
#include "mage.h"
#include "game.h"

using namespace std;


int main()
{
	string filename;
	cin >> filename;
	ifstream input(filename);

	Game game;
	if (!input.is_open()) {
		cout << "file not found!" << endl;
		exit(0);
	}

	string name, occupation, race, level, health;
	for (int i = 0; i < 2; i++) {
		getline(input, occupation);
		getline(input, name);
		getline(input, race);
		getline(input, level);
		getline(input, health);

		if (occupation == "Barbarian") {
			string weapon_name, weapon_damage, weapon_cost, stamina;

			getline(input, stamina);
			getline(input, weapon_name);
			getline(input, weapon_damage);
			getline(input, weapon_cost);
			//	Create the Barbarian object
			//	Equip the weapon to the Barbarian
			//	Add the Barbarian character to the game
			int level1 = stoi(level);
			int stamina1 = stoi(stamina);
			int health1 = stoi(health);
			int weapon_damage1 = stoi(weapon_damage);
			int weapon_cost1 = stoi(weapon_cost);
			Barbarian* barb = new Barbarian(name, race, level1, health1, stamina1);
			barb->EquipWeapon(weapon_name, weapon_damage1, weapon_cost1);
			game.AddCharacter(barb);
		}

		else if (occupation == "Mage") {
			string mana;
			getline(input, mana);
			int level1 = stoi(level);
			int health1 = stoi(health);
			int mana1 = stoi(mana);
			Mage* mag=new Mage(name, race, level1, health1, mana1);
			//	Create a Mage object
			string spell_num;
			getline(input, spell_num);
			for (int i = 0; i < stoi(spell_num); i++) {
				string spell_name, spell_damage, spell_cost;
				getline(input, spell_name);
				getline(input, spell_damage);
				getline(input, spell_cost);
				int spell_damage1 = stoi(spell_damage);
				int spell_cost1 = stoi(spell_cost);
				mag->AddSpell(spell_name, spell_damage1, spell_cost1);
				//		Add the spell to the Mage

			}
			//	Add the Mage to the game
			game.AddCharacter(mag);
		}
		string newline;
		getline(input, newline);

	}



	int option = -1;
	do {
		cout << "Please choose an option: " << endl
			<< "1 - Next Turn" << endl
			<< "2 - Print All Characters" << endl
			<< "3 - Exit" << endl;

		cin >> option;
		cout << endl;

		switch (option) {
		case 1: game.NextTurn(); break;
		case 2: game.Print(); break;
		case 3: exit(0);
		default:
			cout << "Invalid Option!" << endl;
		}
		cout << endl;
	} while (option != 3);

	return 0;
}



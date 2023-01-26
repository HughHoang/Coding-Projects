#ifndef MAGE_H
#define MAGE_H

#include <iostream>
#include <string>
#include "character.h"
using namespace std;

struct spell {
	string name;
	int damage;
	int mana_cost;
};

class Mage : public Character {

private:
	spell spells[10];
	int numOfSpells = 0;
	int mana = 100;
	int active_Spell = 0;
public:
	//constructors
	Mage(string name, string race, int level, int health, int mana);
	//getters
	void setMana(int mana_);

	//setters
	int getMana() const;

	//other functions
	int AddSpell(string spell_name, int spell_damage, int mana_cost);
	void nextSpell();
	void Attack(Character * target);
	void Print();
};


#endif
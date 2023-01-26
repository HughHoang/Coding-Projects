//include the necessary header files
#include <iostream>
#include <string>
using namespace std;
#include "mage.h"

Mage::Mage(string name_ = "", string race_ = "", int ilevel = 0, int ihealth = 0, int imana = 0) : Character(name_, race_, ilevel, ihealth), mana(imana) {
	mana = imana;
}
void Mage::setMana(int mana_) {
	mana = mana_;
}
int Mage::getMana() const {
	return mana;
}
int Mage::AddSpell(string spell_name, int spell_damage, int mana_cost) {
	if (numOfSpells < 10) {
		spells[numOfSpells].name = spell_name;
		spells[numOfSpells].damage = spell_damage;
		spells[numOfSpells].mana_cost = mana_cost;
		numOfSpells++;
		return numOfSpells;
	}
	else {
		cout << "Spell limits reached!";
		return numOfSpells;
	}

}
void Mage::nextSpell() {
	if (active_Spell == numOfSpells-1) {
		active_Spell = 0;
	}
	else {
		active_Spell++;
	}
}
void Mage::Attack(Character* target) {
	if (numOfSpells == 0) {
		cout << "This mage has no spells!" << endl;
	}
	else if (spells[active_Spell].mana_cost > mana) {
		cout << "Insufficient mana points!" << endl;
	}
	else {
		cout << getName() << " attacked " << target->getName() << " with spell:" << spells[active_Spell].name << ", dealing " << spells[active_Spell].damage << " damage." << endl;
		mana -= spells[active_Spell].mana_cost;
		target->SetHealth(target->getHealth() - spells[active_Spell].damage);
		nextSpell();
	}
}
void Mage::Print() {
	cout << "Character Status: " << endl << "Name: " << getName() << endl << "Race : " << getRace() << endl << "Level : " << getLevel() << endl << "Health : " << getHealth() << endl;
	cout << "Spells: " << endl;
	for (int i = 0; i < numOfSpells; i++) {
		cout << spells[i].name;
		
	}
	cout << "---" << endl;
}

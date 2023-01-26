//include the necessary header files
#include <iostream>
#include <string>
using namespace std;
#include "barbarian.h"

Barbarian::Barbarian(string name_ = "", string race_ = "", int ilevel = 0, int ihealth = 0, int stamina_ = 0) : Character(name_, race_, ilevel, ihealth), stamina(stamina_) {
	stamina = stamina_;
}

void Barbarian::SetStamina(int stamina_) {
	stamina = stamina_;
}
int Barbarian::getStamina() const {
	return stamina;
}
void Barbarian::EquipWeapon(string name1, int damage1, int stamina_cost1) {
	active_weapon.name = name1;
	active_weapon.damage = damage1;
	active_weapon.stamina_cost = stamina_cost1;
}
void Barbarian::Attack(Character* target) {
	cout << getName() << " attacked " << target->getName() << " with a " << active_weapon.name << ", dealing " << active_weapon.damage << " damage." << endl;
	stamina -= active_weapon.stamina_cost;
	target->SetHealth(target->getHealth() - active_weapon.damage);
}
void Barbarian::Print() {
	cout << "Character Status: " << endl << "Name: " << getName() << endl << "Race : " << getRace() << endl << "Level : " << getLevel() << endl << "Health : " << getHealth() << endl << "Weapon: " << active_weapon.name << endl<< "---" << endl;
}


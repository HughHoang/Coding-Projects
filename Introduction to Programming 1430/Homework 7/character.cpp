//include the necessary header files
#include <iostream>
#include <string>
#include "character.h"

using namespace std;
Character::Character(string name_ = "", string race_ = "", int ilevel = 0, int ihealth = 0) : name(name_), race(race_), level(ilevel), health(ihealth) {
	name = name_;
	race = race_;
	level = ilevel;
	health = ihealth;
}
string Character::getName() const {
	return name;
}
string Character::getRace() const {
	return race;
}
int Character::getLevel() const {
	return level;
}
int Character::getHealth() const {
	return health;
}
void Character::SetName(string name_) {
	name = name_;
}
void Character::SetRace(string race_) {
	race = race_;
}
void Character::SetLevel(int ilevel) {
	level = ilevel;
}
void Character::SetHealth(int ihealth) {
	health = ihealth;
}

void Character::Print() {
	cout << "Character Status: " << endl << "Name: " << name << endl << "Race : " << race << endl << "Level : " << level << endl << "Health : " << health << endl;
	cout << "---"<<endl;
}
void Character::Attack(Character* target) {

}

#include<iostream>
#include <iomanip> 
#include <string>
#include <fstream>
#include <sstream>
#include "antique.h"
#include "merchant.h"
using namespace std;

class Antique {
public:
    void mutators(string setName, float setPrice);
    void accessors(string getName, float getPrice);
    string toString();

private:
    string name;  // NoName indicates name was not set
    float price;         // -1 indicates rating was not set
};
Antique::Antique() {  // Default constructor
    name = "";         // Default name: NoName indicates name was not set
    price = 0;             // Default rating: -1 indicates rating was not set
}
void Antique::mutators(string setName, float setPrice) {
    name = setName;
    price = setPrice;
}
void Antique::accessors(string getName, float getPrice) {
    name = getName;
    price = getPrice;
}
Antique::Antique() {
    name = "";
    price = 0;
}
string Antique::toString() {

}

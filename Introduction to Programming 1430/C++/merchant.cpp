#include<iostream>
#include <iomanip> 
#include <string>
#include <fstream>
#include <sstream>
#include "antique.h"
#include "merchant.h"
class Merchant {
public:
    Merchant(Antique antiques[], int quantities[]);
    void haggle();
    void printMenu();
    void selectAntique(int budget);

private:
    Antique antiques[10];  // NoName indicates name was not set
    int quantities[10];
    float revenue;
};

Merchant::Merchant(Antique antiques[], int quantities[]) {  // Default constructor
    revenue = 0;
}
void Merchant::haggle() {
    cout << "You have successfully haggled and everything is 10% off.";
}
void Merchant::printMenu() {
    for (int i = 0; i < 10; i++) {
        cout << i << ")" << ": $";
    }
}
void Merchant::selectAntique(int budget) {
    int selAnt;
    cout << "Enter antique number:" << endl;
    cin >> selAnt;
    if (quantities[selAnt] == 0) {
        cout << "Sorry! Antique is out of stock.";
    }
    if (budget < 0) {
        cout << "Insufficient funds.";
    }
    else {
        budget -= 0;
            revenue += 0;
            quantities[selAnt] -= 1;
        cout << "Enjoy your " << "!";

    }
}

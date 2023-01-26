//The Location class has been provided, there are no changes needed here
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
# pragma once

class Location{
    string name;
    float x, y;
    public:
    string getName();
    float getX();
    float getY();
    void setName(string name_);
    void setX(float x_);
    void setY(float y_);
    Location();
    Location(string name_, float x_, float y_);
    Location operator + (Location const &other);
    bool operator == (Location const &other);
};


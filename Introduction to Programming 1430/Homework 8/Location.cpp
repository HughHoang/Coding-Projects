//The Location class has been provided, there are no changes needed here
#include "Location.h"

Location::Location(){
    name = "";
    x = 0;
    y = 0;
}


Location::Location(string name_, float x_, float y_){
    name = name_;
    x = x_;
    y = y_;
}

Location Location::operator + (Location const &other) { 
    return Location(name + other.name, x + other.x, y + other.y); 
} 

bool Location::operator == (Location const &other){
    return (name == other.name && x == other.x && y == other.y);    
}

void Location::setName(string name_){
    name = name_;
}
void Location::setX(float x_){
    x = x_;
}
void Location::setY(float y_){
    y = y_;
}

string Location::getName(){
    return name;
}

float Location::getX(){
    return x;
}

float Location::getY(){
    return y;
}
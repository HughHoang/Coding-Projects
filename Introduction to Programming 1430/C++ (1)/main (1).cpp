#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

#include "TreasureMap.h"
#include "FileReadException.h"
#include "Location.h"

using namespace std;

//overload operator << of Location class, no changes needed
ostream& operator<<(ostream& os, Location& pt) {
	return os << pt.getName();
}

//overload operator >> of Location class, no changes needed
istream& operator >> (istream& os, Location& pt) {
	string name;
	float x,y;
	os >> name >> x >> y;
	pt.setName(name);
	pt.setX(x);
	pt.setY(y);
	
	return os;
}


//FIX ME: Implement readmap function that reads from a file and return a proper TreasureMap object
template<typename T>
TreasureMap<T> readMap(string file_name, int max_steps) {
    ifstream input;
    input.open(file_name);

    if (input.is_open()) {
        TreasureMap<T> Tmap = new TreasureMap<T>(max_steps);
        T a;
        string line;
        int count = 0;

        while (input >> a)
        {
            if (count == max_steps) {

                FileReadException err = new FileReadException("Error reading map : " );
                throw err;
            }
            Tmap.addStep(a);
            count++;
        }
        return Tmap;

    }
    else {
        FileReadException err = new FileReadException("Error reading map: ");
        throw err;
    }
}

int main()
{
    string file_name, file_type;
    int max_steps;
    cin >> file_name >> file_type >> max_steps;

    try {
        if (file_type == "string") {
        }
        else if (file_type == "int") {
            //FIX ME: Create a TreasureMap of type int, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
        }
        else if (file_type == "char") {
            //FIX ME: Create a TreasureMap of type char, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
        }
        else if (file_type == "location") {
            //FIX ME: Create a TreasureMap of type Location, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
        }
    }
    catch (FileReadException& err) {
        cout << err.getMessage();
        //FIX ME: prints out the exception message using getMessage() here
    }
    return 0;
}


#include <string>
#include <iostream>
#include <fstream>
#include "FileReadException.h"
using namespace std;
FileReadException::FileReadException(string str) {
    err_message = str;
}


string FileReadException::getMessage() {
    return err_message;
}
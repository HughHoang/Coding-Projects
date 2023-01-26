#ifndef FILEREADEXCEPTION_H
#define FILEREADEXCEPTION_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;
# pragma once

class FileReadException {
private:
    string err_message;
public:
    FileReadException(string str);
    string getMessage();
};
#endif

#include <iostream>
#include <fstream>
#include "User.h"

User::User(string first, string last, string nCode, string bDay, bool pos) {
    this -> first = first;
    this -> last = last;
    this -> nCode = nCode;
    this -> bDay = bDay;
    this -> pos = pos;
    numberOfUsers ++;
}

int User::numberOfUsers = 0;

bool User::saveToFile() {
    string fileName = (this -> nCode).append(".txt");
    ofstream fileStream;
    try {
        fileStream.open("./Users/Standard/" + fileName); // open the file, or create it.
        // TODO
        fileStream << "SAVED NOW";
        fileStream.close(); // We always need to close our files.
    } catch (const exception& ex) {
        cerr << ex.what() << endl;
        system("pause");
        return false;
    }
    return true;
}

User::~User() = default;
#include <iostream>
#include <fstream>
#include "Admin.h"

Admin::Admin(string first, string last, string nCode, string bDay, bool pos):
User(first, last, nCode, bDay, pos) {}

bool Admin::addUser(User user) {
    user.saveToFile();
    return true;
}

Admin::~Admin() = default;
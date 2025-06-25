#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "training.h"

using namespace std;

class current_user_info {
    string* name;
    int capacity;
    int currentUsers;

public:
    current_user_info();
    ~current_user_info();

    void appendUserToFile(const string& newUser);
    bool isPresent(const string& username);
};

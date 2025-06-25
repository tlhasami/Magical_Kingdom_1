#include "user.h"

current_user_info::current_user_info()
{
    name = nullptr;

    ifstream userFile("users.txt");
    if (!userFile.is_open())
    {
        cerr << "Error: Could not open user.txt file!" << endl;
        exit(EXIT_FAILURE);
    }

    // calculate number of user
    currentUsers = 0;
    string line;
    while (getline(userFile, line))
    {
        ++currentUsers;
    }

    // allocate memory for user names
    capacity = currentUsers;
    name = new string[capacity];

    // move the file reading pointers to the start
    userFile.clear();
    userFile.seekg(0, ios::beg);

    for (int i = 0; i < currentUsers; ++i)
    {
        getline(userFile, name[i]);
        cout << name[i] << endl;
    }

    userFile.close();
}

void current_user_info::appendUserToFile(const string &newUser)
{
    ofstream userFile("users.txt", ios::app);
    if (!userFile.is_open())
    {
        cerr << "Error: Could not open users.txt for appending!" << endl;
        return;
    }
    userFile << newUser << '\n';
    userFile.close();

    // Update in-memory name list
    string *newArray = new string[currentUsers + 1];
    for (int i = 0; i < currentUsers; ++i)
    {
        newArray[i] = name[i];
    }
    newArray[currentUsers] = newUser;

    delete[] name;
    name = newArray;
    ++currentUsers;
    capacity = currentUsers;
}

bool current_user_info::isPresent(const string &username)
{
    for (int i = 0; i < currentUsers; ++i)
    {
        if (name[i] == username)
        {
            return true;
        }
    }
    return false;
}

current_user_info::~current_user_info()
{
    delete[] name;
}

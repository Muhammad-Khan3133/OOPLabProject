#pragma once

#include <iostream>
#include <fstream>
#include "HabitManager.h"
#include "User.h"
using namespace std;

class FileManager
{
public:
    void saveData(HabitManager& manager);
    void loadData(HabitManager& manager);
    void saveUser(User& user);
    string loadUser();
};
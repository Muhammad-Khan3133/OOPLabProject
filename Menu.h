#pragma once
#include "HabitManager.h"
#include "FileManager.h"
#include "User.h"
using namespace std;

class Menu
{
private:
    HabitManager manager;
    FileManager file;
    User currentUser;
public:
    void run();
};

#pragma once
#include <fstream>
#include "HabitManager.h"
using namespace std;

class FileManager
{
public:
    void saveData(HabitManager& manager);
};
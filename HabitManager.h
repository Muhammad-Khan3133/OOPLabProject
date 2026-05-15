#pragma once
#include <vector>
#include "DerivedHabits.h"
using namespace std;

class HabitManager
{
private:
    vector<Habit*> habits;
public:
    void addHabit();
    void viewHabits();
    void completeHabit();
    void deleteHabit();
    void editHabit();
    void showStatistics();
    vector<Habit*>& getHabits();
    ~HabitManager();
};

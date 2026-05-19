#pragma once
#include "Habit.h"
using namespace std;

class DailyHabit : public Habit
{
public:
    DailyHabit(string n, string c, int g);
    void calculateStreak();
    string getType();
};

class WeeklyHabit : public Habit
{
public:
    WeeklyHabit(string n, string c, int g);
    void calculateStreak();
    string getType();
};
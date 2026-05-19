#pragma once
#include <iostream>
#include <string>
using namespace std;

class Habit
{
protected:
    string name;
    string category;
    int streak;
    int longestStreak;
    bool completed;
    int goal;

public:
    Habit();
    Habit(string n, string c, int g);
    virtual void calculateStreak() = 0;
    void displayStats();
    string getName();
    string getCategory();
    int getGoal();
    virtual string getType() = 0;
    virtual ~Habit();
};
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

public:
    Habit();
    Habit(string n, string c);
    virtual void calculateStreak() = 0;
    void displayStats();
    string getName();
    string getCategory();
    virtual string getType() = 0;
    virtual ~Habit();
};
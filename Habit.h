#pragma once
#include <iostream>
#include <string>
#include <ctime>
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
    time_t lastCompleted;

public:
    Habit();
    Habit(string n, string c, int g);
    virtual void complete() = 0;
    virtual string getType() = 0;
    void displayStats();
    string getName();
    string getCategory();
    int getGoal();
    int getStreak();
    time_t getLastCompleted();
    void setStreak(int s);
    void setLastCompleted(time_t t);
    virtual ~Habit();
};
#include "Habit.h"

Habit::Habit()
{
    name = "Unknown";
    category = "General";
    streak = 0;
    longestStreak = 0;
    completed = false;
    goal = 1;
    lastCompleted = 0;
}
Habit::Habit(string n, string c, int g)
{
    name = n;
    category = c;
    streak = 0;
    longestStreak = 0;
    completed = false;
    goal = g;
    lastCompleted = 0;
}
void Habit::displayStats()
{
    cout << "----------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Category: " << category << endl;
    cout << "Type: " << getType() << endl;
    cout << "Current Streak: " << streak << endl;
    cout << "Longest Streak: " << longestStreak << endl;
    cout << "Goal: " << goal << endl;
    int progress = (streak * 100) / goal;
    if (progress > 100)
        progress = 100;
    cout << "Progress: [";
    int bars = progress / 5;
    for (int i = 0; i < bars; i++)
        cout << "█";
    for (int i = bars; i < 20; i++)
        cout << "░";
        cout << "] " << progress << "%" << endl;
        cout << "----------------------------------" << endl;
}
string Habit::getName()
{
    return name;
}
string Habit::getCategory()
{
    return category;
}
int Habit::getGoal()
{
    return goal;
}
time_t Habit::getLastCompleted()
{
    return lastCompleted;
}
void Habit::setLastCompleted(time_t t)
{
    lastCompleted = t;
}
Habit::~Habit()
{
}
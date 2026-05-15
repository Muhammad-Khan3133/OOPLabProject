#include "Habit.h"
using namespace std;

Habit::Habit()
{
    name = "Unknown";
    category = "General";
    streak = 0;
    longestStreak = 0;
    completed = false;
}
Habit::Habit(string n, string c)
{
    name = n;
    category = c;
    streak = 0;
    longestStreak = 0;
    completed = false;
}
void Habit::displayStats()
{
    cout << "----------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Category: " << category << endl;
    cout << "Type: " << getType() << endl;
    cout << "Current Streak: " << streak << endl;
    cout << "Longest Streak: " << longestStreak << endl;
    if(completed)
    {
        cout << "Status: Completed" << endl;
    }
    else
    {
        cout << "Status: Pending" << endl;
    }
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
Habit::~Habit()
{
}
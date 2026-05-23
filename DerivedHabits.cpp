#include "DerivedHabits.h"
#include <iostream>
#include <ctime>
using namespace std;

DailyHabit::DailyHabit(string n, string c, int g) : Habit(n, c, g)
{
}
void DailyHabit::complete()
{
    time_t now = time(0);
    if (lastCompleted != 0)
    {
        double secondsPassed = difftime(now, lastCompleted);
        if (secondsPassed < 86400)
        {
            cout << "Come back in 24 hours!" << endl;
            return;
        }
        if (secondsPassed > 172800)
        {
            cout << "Streak reset due to inactivity." << endl;
            streak = 0;
        }
    }
    streak++;
    lastCompleted = now;
    cout << "Daily habit completed!" << endl;
}
string DailyHabit::getType()
{
    return "Daily";
}
WeeklyHabit::WeeklyHabit(string n, string c, int g) : Habit(n, c, g)
{
}
void WeeklyHabit::complete()
{
    time_t now = time(0);
    if (lastCompleted != 0)
    {
        double secondsPassed = difftime(now, lastCompleted);
        if (secondsPassed < 604800)
        {
            cout << "Come back next week!" << endl;
            return;
        }
        if (secondsPassed > 1209600)
        {
            cout << "Streak reset due to inactivity." << endl;
            streak = 0;
        }
    }
    streak++;
    lastCompleted = now;
    cout << "Weekly habit completed!" << endl;
}
string WeeklyHabit::getType()
{
    return "Weekly";
}
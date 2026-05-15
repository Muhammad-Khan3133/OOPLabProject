#include "DerivedHabits.h"
using namespace std;

DailyHabit::DailyHabit(string n, string c)
    : Habit(n, c)
{
}
void DailyHabit::calculateStreak()
{
    streak++;

    completed = true;

    if(streak > longestStreak)
    {
        longestStreak = streak;
    }
}
string DailyHabit::getType()
{
    return "Daily";
}
WeeklyHabit::WeeklyHabit(string n, string c) : Habit(n, c)
{
}
void WeeklyHabit::calculateStreak()
{
    streak += 7;

    completed = true;

    if(streak > longestStreak)
    {
        longestStreak = streak;
    }
}
string WeeklyHabit::getType()
{
    return "Weekly";
}
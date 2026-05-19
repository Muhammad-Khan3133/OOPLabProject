#include "DerivedHabits.h"
using namespace std;

DailyHabit::DailyHabit(string n, string c, int g) : Habit(n, c, g)
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
WeeklyHabit::WeeklyHabit(string n, string c, int g) : Habit(n, c, g)
{
}
void WeeklyHabit::calculateStreak()
{
    streak++;
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
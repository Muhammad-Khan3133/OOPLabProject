#include "HabitManager.h"
using namespace std;

void HabitManager::addHabit()
{
    string name;
    string category;
    int type;

    cout << endl;
    cout << "========== ADD HABIT ==========" << endl;

    cout << "Enter Habit Name: ";
    cin >> name;

    cout << "Enter Category: ";
    cin >> category;

    cout << endl;
    cout << "1. Daily Habit" << endl;
    cout << "2. Weekly Habit" << endl;
    cout << endl;

    while(true)
    {
        cout << "Select Type: ";
        cin >> type;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid Choice." << endl;
            continue;
        }

        if(type == 1 || type == 2)
        {
            break;
        }

        cout << "Invalid Choice." << endl;
    }

    if(type == 1)
    {
        habits.push_back(new DailyHabit(name, category));
    }
    else
    {
        habits.push_back(new WeeklyHabit(name, category));
    }

    cout << endl;
    cout << "Habit Added Successfully!" << endl;
}

void HabitManager::viewHabits()
{
    cout << endl;
    cout << "========== YOUR HABITS ==========" << endl;

    if(habits.empty())
    {
        cout << "No Habits Found." << endl;
        return;
    }

    for(int i = 0; i < habits.size(); i++)
    {
        cout << endl;
        cout << "Habit #" << i + 1 << endl;

        habits[i]->displayStats();
    }
}

void HabitManager::completeHabit()
{
    int choice;

    viewHabits();

    if(habits.empty())
    {
        return;
    }

    while(true)
    {
        cout << endl;
        cout << "Select Habit Number: ";
        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid Habit Number." << endl;
            continue;
        }

        if(choice > 0 && choice <= habits.size())
        {
            break;
        }

        cout << "Invalid Habit Number." << endl;
    }

    habits[choice - 1]->calculateStreak();

    cout << endl;
    cout << "Habit Completed Successfully!" << endl;
}

void HabitManager::deleteHabit()
{
    int choice;

    viewHabits();

    if(habits.empty())
    {
        return;
    }

    while(true)
    {
        cout << endl;
        cout << "Enter Habit Number To Delete: ";
        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid Habit Number." << endl;
            continue;
        }

        if(choice > 0 && choice <= habits.size())
        {
            break;
        }

        cout << "Invalid Habit Number." << endl;
    }

    delete habits[choice - 1];

    habits.erase(habits.begin() + (choice - 1));

    cout << endl;
    cout << "Habit Deleted Successfully." << endl;
}

void HabitManager::editHabit()
{
    int choice;
    string newName;
    string newCategory;

    viewHabits();

    if(habits.empty())
    {
        return;
    }

    while(true)
    {
        cout << endl;
        cout << "Enter Habit Number To Edit: ";
        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid Habit Number." << endl;
            continue;
        }

        if(choice > 0 && choice <= habits.size())
        {
            break;
        }

        cout << "Invalid Habit Number." << endl;
    }

    cout << "Enter New Habit Name: ";
    cin >> newName;

    cout << "Enter New Category: ";
    cin >> newCategory;

    delete habits[choice - 1];

    habits[choice - 1] = new DailyHabit(newName, newCategory);

    cout << endl;
    cout << "Habit Updated Successfully!" << endl;
}

void HabitManager::showStatistics()
{
    int dailyCount = 0;
    int weeklyCount = 0;

    for(int i = 0; i < habits.size(); i++)
    {
        if(habits[i]->getType() == "Daily")
        {
            dailyCount++;
        }
        else
        {
            weeklyCount++;
        }
    }

    cout << endl;
    cout << "========== STATISTICS ==========" << endl;
    cout << "Total Habits: " << habits.size() << endl;
    cout << "Daily Habits: " << dailyCount << endl;
    cout << "Weekly Habits: " << weeklyCount << endl;
    cout << "================================" << endl;
}

vector<Habit*>& HabitManager::getHabits()
{
    return habits;
}

HabitManager::~HabitManager()
{
    for(int i = 0; i < habits.size(); i++)
    {
        delete habits[i];
    }
}
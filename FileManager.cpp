#include "FileManager.h"
#include "DerivedHabits.h"
#include <fstream>
#include <iostream>
using namespace std;

void FileManager::saveData(HabitManager& manager)
{
    ofstream file("habits.txt");
    if(!file)
    {
        cout << "Error opening file for saving!" << endl;
        return;
    }
    vector<Habit*>& habits = manager.getHabits();
    for(int i = 0; i < habits.size(); i++)
    {
        file << habits[i]->getName() << endl;
        file << habits[i]->getCategory() << endl;
        file << habits[i]->getType() << endl;
        file << habits[i]->getGoal() << endl;
        file << habits[i]->getLastCompleted() << endl;
    }
    file.close();
    cout << "Habits Saved Successfully!" << endl;
}
void FileManager::loadData(HabitManager& manager)
{
    ifstream file("habits.txt");
    if(!file)
    {
        cout << "No saved habits found." << endl;
        return;
    }
    string name;
    string category;
    string type;
    int goal;
    time_t lastCompleted;
    while(getline(file, name))
    {
        getline(file, category);
        getline(file, type);
        file >> goal;
        file >> lastCompleted;
        file.ignore(); 

        Habit* habit = nullptr;
        if(type == "Daily")
        {
            habit = new DailyHabit(name, category, goal);
        }
        else if(type == "Weekly")
        {
            habit = new WeeklyHabit(name, category, goal);
        }
        if(habit != nullptr)
        {
            habit->setLastCompleted(lastCompleted);
            manager.getHabits().push_back(habit);
        }
    }
    file.close();
}
void FileManager::saveUser(User& user)
{
    ofstream file("user.txt");
    if(!file)
    {
        cout << "Error saving user!" << endl;
        return;
    }
    file << user.getUsername();
    file.close();
    cout << "User Saved Successfully!" << endl;
}
string FileManager::loadUser()
{
    ifstream file("user.txt");
    if(!file)
    {
        return "";
    }
    string username;
    getline(file, username);
    file.close();
    return username;
}
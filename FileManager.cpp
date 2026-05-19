#include "FileManager.h"
#include "DerivedHabits.h"

using namespace std;

void FileManager::saveData(HabitManager& manager)
{
    ofstream file("habits.txt");
    vector<Habit*>& habits = manager.getHabits();
    for(int i = 0; i < habits.size(); i++)
    {
        file << habits[i]->getName() << endl;
        file << habits[i]->getCategory() << endl;
        file << habits[i]->getType() << endl;
        file << habits[i]->getGoal() << endl;
    }
    file.close();

    cout << "Habits Saved Successfully!" << endl;
}
void FileManager::loadData(HabitManager& manager)
{
    ifstream file("habits.txt");
    string name;
    string category;
    string type;
    int goal;

    while(getline(file, name))
    {
        getline(file, category);
        getline(file, type);
        file >> goal;
        file.ignore();
        if(type == "Daily")
        {
            manager.getHabits().push_back(new DailyHabit(name, category, goal));
        }
        else if(type == "Weekly")
        {
            manager.getHabits().push_back(new WeeklyHabit(name, category, goal));
        }
    }
    file.close();
}
void FileManager::saveUser(User& user)
{
    ofstream file("user.txt");
    file << user.getUsername();
    file.close();
    cout << "User Saved Successfully!" << endl;
}
string FileManager::loadUser()
{
    ifstream file("user.txt");
    string username;
    getline(file, username);
    file.close();
    return username;
}
#include "FileManager.h"
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

    while(getline(file, name))
    {
        getline(file, category);
        getline(file, type);

        if(type == "Daily")
        {
            manager.getHabits().push_back(new DailyHabit(name, category));
        }
        else
        {
            manager.getHabits().push_back(new WeeklyHabit(name, category));
        }
    }
    file.close();
}
void FileManager::saveUser(User& user)
{
    ofstream file("user.txt");
    file << user.getUsername() << endl;
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
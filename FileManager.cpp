#include "FileManager.h"
using namespace std;

void FileManager::saveData(HabitManager& manager)
{
    ofstream file("habits.txt");
    vector<Habit*>& habits = manager.getHabits();
    for(int i = 0; i < habits.size(); i++)
    {
        file << habits[i]->getName() << " ";
        file << habits[i]->getCategory() << " ";
        file << habits[i]->getType() << endl;
    }
    file.close();
    cout << "Data Saved Successfully!" << endl;
}
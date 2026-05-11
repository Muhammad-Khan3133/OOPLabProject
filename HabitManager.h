#include <vector>
#include <memory>
#include <string>
#include "Habit.h"

using namespace std;

class HabitManager {
private:
    vector<shared_ptr<Habit>> habits;
    int nextId;

public:
    HabitManager();

    void addHabit(shared_ptr<Habit> habit);
    bool deleteHabit(int id);
    bool editHabit(int id, const string& newName,
                   const string& newCategory,
                   const string& newDifficulty);

    shared_ptr<Habit> findById(int id);
    vector<shared_ptr<Habit>> searchByName(const string& keyword) const;
    vector<shared_ptr<Habit>> filterByCategory(const string& cat) const;

    void listAll() const;
    void dashboard() const;

    const vector<shared_ptr<Habit>>& getAll() const;
    int getNextId();
};

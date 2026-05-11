#include "HabitManager.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

HabitManager::HabitManager() : nextId(1) {}

void HabitManager::addHabit(shared_ptr<Habit> habit) {
    habits.push_back(habit);
    if (habit->getId() >= nextId) nextId = habit->getId() + 1;
}

bool HabitManager::deleteHabit(int id) {
    auto it = remove_if(habits.begin(), habits.end(),
        [id](const shared_ptr<Habit>& h){ return h->getId() == id; });
    if (it == habits.end()) return false;
    habits.erase(it, habits.end());
    return true;
}

bool HabitManager::editHabit(int id, const string& name,
                               const string& cat,
                               const string& diff) {
    auto h = findById(id);
    if (!h) return false;
    if (!name.empty()) h->setName(name);
    if (!cat.empty())  h->setCategory(cat);
    if (!diff.empty()) h->setDifficulty(diff);
    return true;
}

shared_ptr<Habit> HabitManager::findById(int id) {
    for (auto& h : habits)
        if (h->getId() == id) return h;
    return nullptr;
}

vector<shared_ptr<Habit>>
HabitManager::searchByName(const string& keyword) const {
    vector<shared_ptr<Habit>> result;
    for (auto& h : habits) {
        string lower = h->getName();
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        string kl = keyword;
        transform(kl.begin(), kl.end(), kl.begin(), ::tolower);
        if (lower.find(kl) != string::npos) result.push_back(h);
    }
    return result;
}

vector<shared_ptr<Habit>>
HabitManager::filterByCategory(const string& cat) const {
    vector<shared_ptr<Habit>> result;
    for (auto& h : habits) {
        string hc = h->getCategory();
        transform(hc.begin(), hc.end(), hc.begin(), ::tolower);
        string cl = cat;
        transform(cl.begin(), cl.end(), cl.begin(), ::tolower);
        if (hc == cl) result.push_back(h);
    }
    return result;
}

void HabitManager::listAll() const {
    if (habits.empty()) {
        cout << "\n  No habits found.\n";
        return;
    }
    cout << "\n  " << string(65, '-') << endl;
    cout << "  " << left
              << setw(4)  << "ID"
              << setw(20) << "Name"
              << setw(10) << "Type"
              << setw(10) << "Category"
              << setw(8)  << "Streak"
              << setw(8)  << "Longest"
              << "Badge\n";
    cout << "  " << string(65, '-') << endl;
    for (auto& h : habits) {
        cout << "  " << left
                  << setw(4)  << h->getId()
                  << setw(20) << h->getName()
                  << setw(10) << h->getType()
                  << setw(10) << h->getCategory()
                  << setw(8)  << h->getStreakCount()
                  << setw(8)  << h->getLongestStreak()
                  << h->getAchievementBadge() << endl;
    }
    cout << "  " << string(65, '-') << endl;
}

void HabitManager::dashboard() const {
    cout << "\n  ════════════════════════════════════════\n";
    cout << "           HABIT TRACKER DASHBOARD\n";
    cout << "  ════════════════════════════════════════\n";
    cout << "  Today: " << Habit::todayDate() << endl;
    cout << "  Total habits: " << habits.size() << "\n\n";

    for (auto& h : habits) {
        double rate = StreakCalculator::completionRate(h.get(), 30);
        int bar = (int)(rate / 5);
        cout << "  [" << setw(2) << h->getId() << "] "
                  << left << setw(18) << h->getName()
                  << " Streak:" << setw(4) << h->getStreakCount()
                  << " [";
        for (int i = 0; i < 20; ++i)
            cout << (i < bar ? "█" : "░");
        cout << "] " << fixed << setprecision(0) << rate << "%\n";
    }
    cout << "  ════════════════════════════════════════\n";
}

const vector<shared_ptr<Habit>>& HabitManager::getAll() const {
    return habits;
}

int HabitManager::getNextId() { return nextId++; }

#include "Habit.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

Habit::Habit(int id, const string& name, const string& category,
             const string& difficulty)
    : id(id), name(name), category(category),
      streakCount(0), longestStreak(0), difficulty(difficulty) {}

Habit::~Habit() {}

string Habit::todayDate() {
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    ostringstream oss;
    oss << (1900 + t->tm_year) << "-"
        << setw(2) << setfill('0') << (1 + t->tm_mon) << "-"
        << setw(2) << setfill('0') << t->tm_mday;
    return oss.str();
}

void Habit::markComplete(const string& date) {
    if (!isCompletedOn(date)) {
        completionHistory.push_back(date);
        sort(completionHistory.begin(), completionHistory.end());
    }
    calculateStreak();
}

bool Habit::isCompletedOn(const string& date) const {
    return find(completionHistory.begin(), completionHistory.end(), date)
           != completionHistory.end();
}

void Habit::displayStats() const {
    cout << "\n  +-----------------------------------------+\n";
    cout << "  | Habit: " << left << setw(33) << name << "|\n";
    cout << "  | Type : " << setw(33) << getType()    << "|\n";
    cout << "  | Cat  : " << setw(33) << category     << "|\n";
    cout << "  | Diff : " << setw(33) << difficulty   << "|\n";
    cout << "  | Streak       : " << setw(25) << streakCount   << "|\n";
    cout << "  | Longest      : " << setw(25) << longestStreak << "|\n";
    cout << "  | Total days   : " << setw(25) << completionHistory.size() << "|\n";
    cout << "  | Badge        : " << setw(25) << getAchievementBadge() << "|\n";
    cout << "  +-----------------------------------------+\n";
}

string Habit::getAchievementBadge() const {
    if (longestStreak >= 100) return "🏆 Legendary (100+)";
    if (longestStreak >= 30)  return "🥇 Master (30+)";
    if (longestStreak >= 14)  return "🥈 Dedicated (14+)";
    if (longestStreak >= 7)   return "🥉 Consistent (7+)";
    if (longestStreak >= 3)   return "⭐ On a Roll (3+)";
    return "🌱 Just Started";
}


int         Habit::getId()         const { return id; }
string Habit::getName()       const { return name; }
string Habit::getCategory()   const { return category; }
int         Habit::getStreakCount() const { return streakCount; }
int         Habit::getLongestStreak() const { return longestStreak; }
string Habit::getDifficulty() const { return difficulty; }
const vector<string>& Habit::getHistory() const { return completionHistory; }


void Habit::setName(const string& n)     { name = n; }
void Habit::setCategory(const string& c) { category = c; }
void Habit::setDifficulty(const string& d) { difficulty = d; }
void Habit::setStreakCount(int s)   { streakCount = s; }
void Habit::setLongestStreak(int l) { longestStreak = l; }
void Habit::setHistory(const vector<string>& h) { completionHistory = h; }

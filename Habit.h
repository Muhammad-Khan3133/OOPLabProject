#pragma once
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Habit {
protected:
    int id;
    string name;
    string category;
    int streakCount;
    int longestStreak;
    string difficulty;   
    vector<string> completionHistory; 

public:
    Habit(int id, const string& name, const string& category,
          const string& difficulty = "Medium");
    virtual ~Habit();

    
    virtual void calculateStreak() = 0;
    virtual string getType() const = 0;

    
    void markComplete(const string& date);
    bool isCompletedOn(const string& date) const;
    void displayStats() const;
    string getAchievementBadge() const;

    
    int getId() const;
    string getName() const;
    string getCategory() const;
    int getStreakCount() const;
    int getLongestStreak() const;
    string getDifficulty() const;
    const vector<string>& getHistory() const;

    
    void setName(const string& name);
    void setCategory(const string& category);
    void setDifficulty(const string& difficulty);
    void setStreakCount(int s);
    void setLongestStreak(int l);
    void setHistory(const vector<string>& h);

    static string todayDate();
};

#include "Menu.h"
using namespace std;

void Menu::run()
{
    string username;

    file.loadData(manager);
    username = file.loadUser();
    cout << endl;
    cout << "======================================" << endl;
    cout << "        WELCOME TO HABIT TRACKER      " << endl;
    cout << "======================================" << endl;
    cout << endl;
    if(username != "")
    {
        cout << "Welcome Back, " << username << "!" << endl;
        currentUser.setUsername(username);
    }
    else
    {
        cout << "Enter Username: ";
        cin >> username;
        currentUser.setUsername(username);
        file.saveUser(currentUser);
    }
    int choice = -1;
    while(choice != 0)
    {
        cout << endl;
        cout << "======================================" << endl;
        cout << "         HABIT TRACKER SYSTEM         " << endl;
        cout << "======================================" << endl;
        cout << endl;
        cout << "Logged In As: " << currentUser.getUsername() << endl;
        cout << endl;

        cout << "1. Add Habit" << endl;
        cout << "2. View Habits" << endl;
        cout << "3. Complete Habit" << endl;
        cout << "4. Delete Habit" << endl;
        cout << "5. Edit Habit" << endl;
        cout << "6. Show Statistics" << endl;
        cout << "7. Save Data" << endl;
        cout << "0. Exit Program" << endl;
        cout << endl;
        cout << "======================================" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case 1:
                manager.addHabit();
                break;
            case 2:
                manager.viewHabits();
                break;
            case 3:
                manager.completeHabit();
                break;
            case 4:
                manager.deleteHabit();
                break;
            case 5:
                manager.editHabit();
                break;
            case 6:
                manager.showStatistics();
                break;
            case 7:
                file.saveData(manager);
                file.saveUser(currentUser);
                break;
            case 0:
                file.saveData(manager);
                file.saveUser(currentUser);
                cout << "Saving Data and Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid Choice." << endl;
        }
    }
}
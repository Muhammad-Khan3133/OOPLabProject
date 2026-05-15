#pragma once
#include <string>
using namespace std;

class User
{
private:
    string username;

public:
    User();
    void setUsername(string u);
    string getUsername();
};
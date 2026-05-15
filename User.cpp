#include "User.h"
using namespace std;

User::User()
{
    username = "Guest";
}
void User::setUsername(string u)
{
    username = u;
}
string User::getUsername()
{
    return username;
}
#ifndef USER_H
#define USER_H

#include "consts.h"
#include <iostream>
#include <string>

enum Levels
{
    NON_AUTH = 0,
    STUDENT = 1,
    SUPPLY = 2,
    COMEND = 3
};

class User
{
private:
    int id;
    std::string login;
    std::string password;
    Levels privelegeLevel;

public:
    User(int id, std::string login, std::string password, Levels privelegeLevel);
    User();
    ~User();
    Levels getUserLevel();
    std::string getLogin();
    std::string getPassword();
    int getId();
};

#endif // USER_H

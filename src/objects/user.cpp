#include "user.h"

User::User(int id, std::string login, std::string password, Levels privelegeLevel)
{
    this->id = id;
    this->login = login;
    this->password = password;
    this->privelegeLevel = privelegeLevel;
}

User::User()
{
    this->id = NONE;
    this->login = EMPTY;
    this->password = EMPTY;
    this->privelegeLevel = NON_AUTH;
}

User::~User()
{}

Levels User::getUserLevel()
{
    return this->privelegeLevel;
}

int User::getId()
{
    return this->id;
}

std::string User::getLogin()
{
    return this->login;
}

std::string User::getPassword()
{
    return this->password;
}

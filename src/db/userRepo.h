#ifndef USERREPO_H
#define USERREPO_H

#include <iostream>
#include <string>
#include "../objects/user.h"

class InterfaceUserRepo
{
public:
    virtual int getUserId(std::string login);
    virtual User getUser(int id);
    virtual void addUser(std::string login, std::string password, Levels privelegeLevel);
};

#endif // USERREPO_H

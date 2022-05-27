#ifndef INTERFACEUSERREPO_H
#define INTERFACEUSERREPO_H

#include <iostream>
#include <string>
#include "../objects/user.h"

class InterfaceUserRepo
{
private:
    int connection;

public:
    virtual int getUserId(std::string login);
    virtual User getUser(int id);
    virtual void addUser(std::string login, std::string password, Levels privelegeLevel);
};

#endif // INTERFACEUSERREPO_H

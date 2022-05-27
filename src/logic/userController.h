#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include "../objects/user.h"
#include "../db/userRepo.h"

class UserController
{
private:
    InterfaceUserRepo *repository;
public:
    UserController(InterfaceUserRepo &repository);
    ~UserController();

    int getUserId(std::string login);
    User getUser(int id);
    void addUser(std::string login, std::string password, Levels privelageLevel);
    bool userExists(std::string login);
};

#endif // USERCONTROLLER_H

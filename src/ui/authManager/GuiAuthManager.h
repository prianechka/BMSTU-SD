#ifndef GUIAUTHMANAGER_H
#define GUIAUTHMANAGER_H

#include "../../logic/userController.h"
#include "../../db/pgUserRepo.h"

class GUIAuthManager {
public:
    GUIAuthManager(UserController &controller);
    GUIAuthManager();
    ~GUIAuthManager() = default;
    bool isAuthorized(std::string login);
    Levels TryToAuthorize(std::string login, std::string password);
    int GetUserID(std::string login);

private:
    std::string login;
    std::string password;
    UserController controller;
};

#endif // GUIAUTHMANAGER_H

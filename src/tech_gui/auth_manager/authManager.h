#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "authGetter.h"
#include "authPrinter.h"

#include "../../logic/userController.h"
#include "../../db/pgUserRepo.h"

class AuthManager {
public:
    AuthManager(UserController &controller);
    AuthManager();
    ~AuthManager() = default;
    bool isAuthorized(std::string login);
    Levels TryToAuthorize();
    int GetUserID(std::string login);
    std::string getLogin();
private:
    AuthGetter getter;
    AuthPrinter printer;
    std::string login;
    std::string password;
    UserController controller;
};

#endif // AUTHMANAGER_H

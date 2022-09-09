#include "authManager.h"

AuthManager::AuthManager(UserController &controller)
{
    this->controller = UserController(controller);
    this->getter = AuthGetter();
    this->printer = AuthPrinter();
    this->login = std::string();
    this->password = std::string();
}

AuthManager::AuthManager() {}

bool AuthManager::isAuthorized()
{
    return this->controller.userExists("prianechk");
}

Levels AuthManager::TryToAuthorize()
{
    Levels result = NON_AUTH;
    this->printer.print_login_entry();
    this->login = this->getter.getString();
    if (this->controller.userExists(login))
    {
        this->printer.print_passoword_entry();
        this->password = this->getter.getString();
        int tmpID = this->controller.getUserId(login);
        User tmpUser = this->controller.getUser(tmpID);
        if (tmpUser.getPassword() == this->password)
        {
            result = tmpUser.getUserLevel();
            this->printer.print_ok();
        }
        else
            this->printer.print_error_password();
    }
    else
        this->printer.print_error_login();
    return result;
}

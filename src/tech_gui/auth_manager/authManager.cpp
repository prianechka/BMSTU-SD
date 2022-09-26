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

bool AuthManager::isAuthorized(std::string login)
{
    return this->controller.userExists(login);
}

Levels AuthManager::TryToAuthorize()
{
    Levels result = NON_AUTH;
    this->printer.print_login_entry();
    this->login = this->getter.getString();
    try
    {
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
                throw IncorrectPassportException(__FILE__, typeid(*this).name(), __LINE__);
        }
        else
            throw LoginNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
    return result;
}

int AuthManager::GetUserID(std::string login)
{
    int result = NONE;
    try
    {
        if (this->controller.userExists(login))
            result = this->controller.getUserId(login);
        else
            throw LoginNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
    return result;
}

std::string AuthManager::getLogin()
{
    return this->login;
}

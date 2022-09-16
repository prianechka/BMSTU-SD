#include "GuiAuthManager.h"

GUIAuthManager::GUIAuthManager(UserController &controller)
{
    this->controller = UserController(controller);
    this->login = std::string();
    this->password = std::string();
}

GUIAuthManager::GUIAuthManager() {}

bool GUIAuthManager::isAuthorized(std::string login)
{
    return this->controller.userExists(login);
}

Levels GUIAuthManager::TryToAuthorize(std::string login, std::string password)
{
    Levels result = NON_AUTH;
    if (this->controller.userExists(login))
    {
        int tmpID = this->controller.getUserId(login);
        User tmpUser = this->controller.getUser(tmpID);
        if (tmpUser.getPassword() == password)
        {
            result = tmpUser.getUserLevel();
        }
        else
            throw IncorrectPassportException(__FILE__, typeid(*this).name(), __LINE__);
    }
    else
        throw LoginNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    return result;
}

int GUIAuthManager::GetUserID(std::string login)
{
    return this->controller.getUserId(login);
}

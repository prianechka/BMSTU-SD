#include "userController.h"

UserController::UserController(InterfaceUserRepo &repository)
{
    this->repository = &repository;
}

UserController::UserController()
{}

UserController::~UserController(){}

UserController::UserController(UserController &controller)
{
    this->repository = controller.repository;
}

int UserController::getUserId(std::string login)
{
    int id = this->repository->getUserId(login);
    if (id == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return id;
}

User UserController::getUser(int id)
{
    User tmpUser = this->repository->getUser(id);
    if (tmpUser.getId() == NONE)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpUser;
}

void UserController::addUser(std::string login, std::string password, Levels privelegeLevel)
{
    this->repository->addUser(login, password, privelegeLevel);
    int id = this->repository->getUserId(login);
    if (id == NONE)
        throw UserAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

bool UserController::userExists(std::string login)
{
    return this->repository->getUserId(login) > NONE;
}

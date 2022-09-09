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
    return this->repository->getUserId(login);
}

User UserController::getUser(int id)
{
    return this->repository->getUser(id);
}

void UserController::addUser(std::string login, std::string password, Levels privelegeLevel)
{
    return this->repository->addUser(login, password, privelegeLevel);
}

bool UserController::userExists(std::string login)
{
    return this->repository->getUserId(login) >= 0;
}

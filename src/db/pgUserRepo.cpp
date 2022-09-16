#include "pgUserRepo.h"
#include <QDebug>

PgUserRepo::PgUserRepo(ConnectionParams params)
{
    this->connectString = params.getString();
    try
    {
        this->connection = std::shared_ptr<pqxx::connection>(
                              new pqxx::connection(this->connectString.c_str()));
        if (!this->connection->is_open())
        {
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
        }
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}


int PgUserRepo::getUserId(std::string login)
{
    int resultId = -1;
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetUserId().get_text(login);
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            if (result.size() == 1)
                resultId = result[0][0].as<int>();
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultId;
}

User PgUserRepo::getUser(int id)
{
    User resultUser;
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetUser().get_text(id);
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            if (result.size() > 0)
            {
                resultUser = User(id, result[0][1].as<std::string>(), result[0][2].as<std::string>(),
                                  Levels(result[0][3].as<int>()));
            }
            else
                resultUser = User();
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultUser;
}

void PgUserRepo::addUser(std::string login, std::string password, Levels privelegeLevel)
{
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLAddUser().get_text(login, password, privelegeLevel);
            pqxx::work curConnect(*this->connection);
            curConnect.exec(sql);
            curConnect.commit();
        }
        else
        {
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
        }
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}

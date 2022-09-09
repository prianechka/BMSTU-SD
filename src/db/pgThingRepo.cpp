#include "pgThingRepo.h"

PgThingRepo::PgThingRepo(ConnectionParams params)
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

void PgThingRepo::addThing(ThingDTO thing)
{
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLAddThing().get_text(thing);
            pqxx::work curConnect(*this->connection);
            curConnect.exec(sql);
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}

std::vector<Thing> PgThingRepo::getThings()
{
    std::vector<Thing> resultThings = std::vector<Thing>();
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetThings().get_text();
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            for (size_t i = 0; i < result.size(); i++)
            {
                Thing currentThing = Thing(result[i][0].as<int>(), result[i][1].as<int>(),
                                           std::time_t(nullptr), result[i][3].as<std::string>(),
                                            result[i][4].as<int>(), result[i][5].as<int>());
                resultThings.push_back(currentThing);
            }
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultThings;
}

void PgThingRepo::deleteThing(int id)
{
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLDeleteThing().get_text(id);
            pqxx::work curConnect(*this->connection);
            curConnect.exec(sql);
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}

Thing PgThingRepo::getThing(int id)
{
    Thing resultThing;
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetThing().get_text(id);
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            if (result.size() == 1)
                resultThing = Thing(result[0][0].as<int>(), result[0][1].as<int>(),
                        std::time_t(nullptr), result[0][3].as<std::string>(),
                        result[0][4].as<int>(), result[0][5].as<int>());
            else
                resultThing = Thing();
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultThing;
}

void PgThingRepo::transferThing(int id, int srcRoomID, int dstRoomID)
{
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLTransferThingRoom().get_text(id, srcRoomID, dstRoomID);
            pqxx::work curConnect(*this->connection);
            curConnect.exec(sql);
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}

int PgThingRepo::getThingIDByMarkNumber(int markNumber)
{
    int id = NONE;
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetThing().get_text(markNumber);
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            if (result.size() > 0)
                id = result[0][0].as<int>();
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return id;
}

/*
int main()
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);
    PgThingRepo rep = PgThingRepo(connectParams);
    std::vector<Thing> resultThings = rep.getThings();
    for (size_t i = 0; i < resultThings.size(); i++)
    {
        std::cout << resultThings[i].getID() << " " << resultThings[i].getMarkNumber() << std::endl;
    }
}
*/

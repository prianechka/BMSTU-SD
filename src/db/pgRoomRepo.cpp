#include "pgRoomRepo.h"

PgRoomRepo::PgRoomRepo(ConnectionParams params)
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

void PgRoomRepo::addRoom(RoomDTO room)
{
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLAddRoom().get_text(room);
            pqxx::work curConnect(*this->connection);
            curConnect.exec(sql);
            curConnect.commit();
        }
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}

std::vector<Room> PgRoomRepo::getRooms()
{
    std::vector<Room> resultRooms = std::vector<Room>();
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetRooms().get_text();
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            for (size_t i = 0; i < result.size(); i++)
            {
                Room currentRoom = Room(result[i][0].as<int>(), result[i][1].as<std::string>(),
                                        result[i][2].as<int>());
                resultRooms.push_back(currentRoom);
            }
            curConnect.commit();
        }
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultRooms;
}

Room PgRoomRepo::getRoom(int id)
{
    Room resultRoom;
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetRoom().get_text(id);
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            if (result.size() == 1)
                resultRoom = Room(result[0][0].as<int>(), result[0][1].as<std::string>(),
                                  result[0][2].as<int>());
            else
                resultRoom = Room();
            curConnect.commit();
        }
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultRoom;
}

void PgRoomRepo::deleteRoom(int id)
{
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLDeleteRoom().get_text(id);
            pqxx::work curConnect(*this->connection);
            curConnect.exec(sql);
            curConnect.commit();
        }
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}

std::vector<Thing> PgRoomRepo::getRoomThings(int id)
{
    std::vector<Thing> resultThings = std::vector<Thing>();
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetRoomThings().get_text(id);
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            for (size_t i = 0; i < result.size(); i++)
            {
                Thing currentThing = Thing(result[i][0].as<int>(), result[i][1].as<int>(),
                                           std::time_t(nullptr), result[i][3].as<std::string>(),
                                            result[i][4].as<int>(), id);
                resultThings.push_back(currentThing);
            }
            curConnect.commit();
        }
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultThings;
}

/*
int main()
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);
    PgRoomRepo rep = PgRoomRepo(connectParams);
    rep.deleteRoom(2);
}
*/

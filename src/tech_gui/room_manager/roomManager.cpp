#include "roomManager.h"

RoomManager::RoomManager(){}

RoomManager::RoomManager(RoomController &roomController)
{
    this->roomController = roomController;
    this->printer = RoomPrinter();
}

void RoomManager::printAllRooms()
{
    std::vector<Room> rooms = this->roomController.getRooms();
    for (size_t i = 0; i < rooms.size(); i++)
        this->printer.printRoom(rooms[i]);
}

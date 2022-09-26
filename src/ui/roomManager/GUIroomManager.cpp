#include "GUIroomManager.h"

GUIRoomManager::GUIRoomManager(){}

GUIRoomManager::GUIRoomManager(RoomController &roomController)
{
    this->roomController = roomController;
}

Room GUIRoomManager::getRoomByID(int id)
{
    return this->roomController.getRoom(id);
}

std::vector<Room> GUIRoomManager::getRooms()
{
    return this->roomController.getRooms();
}

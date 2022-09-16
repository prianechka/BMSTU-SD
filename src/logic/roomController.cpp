#include "roomController.h"

RoomController::RoomController(InterfaceRoomRepo &repository)
{
    this->Repository = &repository;
}

RoomController::RoomController() {}

RoomController::~RoomController(){}

void RoomController::addRoom(std::string roomType, int number)
{
    this->Repository->addRoom(RoomDTO(roomType, number));
}

std::vector<Room> RoomController::getRooms()
{
    return this->Repository->getRooms();
}

Room RoomController::getRoom(int id)
{
    Room tmpRoom = this->Repository->getRoom(id);
    if (tmpRoom.getID() == NONE)
        throw RoomNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpRoom;
}

void RoomController::deleteRoom(int id)
{
    Room tmpRoom = this->Repository->getRoom(id);
    if (tmpRoom.getID() >= NONE)
    {
        try
        {
            this->Repository->deleteRoom(id);
            Room checkRoom = this->Repository->getRoom(id);
            if (checkRoom.getID() != NONE)
                throw BadRoomDeleteException(__FILE__, typeid(*this).name(), __LINE__);
        }
        catch (RoomNotFoundException)
        {}
    }
    else
        throw RoomNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
}

std::vector<Thing> RoomController::getRoomThings(int id)
{
    Room tmpRoom = this->Repository->getRoom(id);
    if (tmpRoom.getID() == NONE)
        throw RoomNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return this->Repository->getRoomThings(id);
}

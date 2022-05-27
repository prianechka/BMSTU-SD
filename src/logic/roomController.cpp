#include "roomController.h"

RoomController::RoomController(InterfaceRoomRepo &repository)
{
    this->Repository = &repository;
}

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
    return this->Repository->getRoom(id);
}

void RoomController::deleteRoom(int id)
{
    Room tmpRoom = this->Repository->getRoom(id);
    if (tmpRoom.getID() >= 0)
        this->Repository->deleteRoom(id);
}

std::vector<Thing> RoomController::getRoomThings(int id)
{
    return this->Repository->getRoomThings(id);
}

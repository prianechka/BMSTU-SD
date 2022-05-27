#include "roomController.h"

RoomController::RoomController(InterfaceRoomRepo &repository)
{
    this->Repository = &repository;
}

RoomController::~RoomController(){}

void RoomController::addRoom(std::string roomType, int number)
{
    this->Repository->addRoom(roomType, number);
}

std::vector<Room> RoomController::getRooms()
{
    return this->Repository->getRooms();
}

Room RoomController::getRoomInfo(int id)
{
    return this->Repository->getRoomInfo(id);
}

void RoomController::deleteRoom(int id)
{
    this->Repository->deleteRoom(id);
}

std::vector<Thing> RoomController::getRoomThings(int id)
{
    return this->Repository->getRoomThings(id);
}

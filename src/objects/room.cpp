#include "room.h"

Room::Room(int id, std::string roomType, int roomNumber)
{
    this->id = id;
    this->roomType = roomType;
    this->roomNumber = roomNumber;
}

Room::Room()
{
    this->id = NONE;
    this->roomType = EMPTY;
    this->roomNumber = NONE;
}

Room::~Room()
{}

int Room::getID()
{
    return this->id;
}

std::string Room::getRoomType()
{
    return this->roomType;
}

int Room::getRoomNumber()
{
    return this->roomNumber;
}

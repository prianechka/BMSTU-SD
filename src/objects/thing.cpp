#include "thing.h"

Thing::Thing(int id, int markNumber, std::time_t creationDate, std::string thingType, int ownerID, int roomID)
{
    this->id = id;
    this->markNumber = markNumber;
    this->creationDate = creationDate;
    this->thingType = thingType;
    this->ownerID = ownerID;
    this->roomID = roomID;
}

Thing::Thing()
{
    this->id = NONE;
    this->markNumber = NONE;
    this->creationDate = CUR_TIME;
    this->thingType = EMPTY;
    this->ownerID = NONE;
    this->roomID = NONE;
}

Thing::~Thing()
{}

int Thing::getID()
{
    return this->id;
}

int Thing::getRoomID()
{
    return this->roomID;
}

int Thing::getOwnerID()
{
    return this->ownerID;
}

int Thing::getMarkNumber()
{
    return this->markNumber;
}

std::string Thing::getThingType()
{
    return this->thingType;
}

void Thing::setRoomID(int newID)
{
    this->roomID = newID;
}

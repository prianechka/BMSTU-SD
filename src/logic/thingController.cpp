#include "thingController.h"

ThingController::ThingController(InterfaceThingRepo &repository)
{
    this->repository = &repository;
}

ThingController::ThingController() {}

ThingController::~ThingController(){}

void ThingController::addThing(int markNumber, std::string thingType)
{
    this->repository->addThing(ThingDTO(markNumber, thingType));
    int id = this->repository->getThingIDByMarkNumber(markNumber);
    if (id == NONE)
        throw BadThingAddException(__FILE__, typeid(*this).name(), __LINE__);
}

std::vector<Thing> ThingController::getThings()
{
    return this->repository->getThings();
}

std::vector<Thing> ThingController::getFreeThings()
{
    std::vector<Thing> allThings = this->repository->getThings();
    std::vector<Thing> result;

    for (Thing tmpThing : allThings)
    {
        if (tmpThing.getOwnerID() == NONE)
            result.push_back(tmpThing);
    }
    return result;
}

Thing ThingController::getThing(int id)
{
    Thing tmpThing = this->repository->getThing(id);
    if (tmpThing.getID() == NONE)
        throw ThingNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpThing;
}

void ThingController::deleteThing(int id)
{
    Thing tmpThing = this->getThing(id);
    if (tmpThing.getID() >= NONE)
        this->repository->deleteThing(id);
    else
        throw ThingNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
}


int ThingController::getThingRoom(int id)
{
    Thing tmpThing = this->repository->getThing(id);
    if (tmpThing.getID() == NONE)
        throw ThingNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpThing.getRoomID();
}

void ThingController::transferThing(int id, int srcRoomID, int dstRoomID)
{
    Thing tmpThing = this->repository->getThing(id);
    if (tmpThing.getID() == NONE)
        throw ThingNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
    {
        if (tmpThing.getRoomID() != srcRoomID)
            throw ThingNotRoomException(__FILE__, typeid(*this).name(), __LINE__);
        else
        {
            if (dstRoomID == NONE)
                throw RoomNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
            this->repository->transferThing(id, srcRoomID, dstRoomID);
            tmpThing = this->repository->getThing(id);
            if (tmpThing.getRoomID() != dstRoomID)
                throw ThingBadTransferException(__FILE__, typeid(*this).name(), __LINE__);
        }
    }
}

int ThingController::getCurrentOwner(int id)
{
    Thing tmpThing = this->repository->getThing(id);
    if (tmpThing.getID() == NONE)
        throw ThingNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return tmpThing.getOwnerID();
}

int ThingController::getThingIDByMarkNumber(int markNumber)
{
    int id = this->repository->getThingIDByMarkNumber(markNumber);
    if (id == NONE)
        throw ThingNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return id;
}

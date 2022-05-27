#include "thingController.h"

ThingController::ThingController(InterfaceThingRepo &repository)
{
    this->repository = &repository;
}

ThingController::~ThingController(){}

void ThingController::addThing(int markNumber, std::string thingType)
{
    this->repository->addThing(markNumber, thingType);
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
        if (tmpThing.getRoomID() == -1)
            result.push_back(tmpThing);
    }
    return result;
}

void ThingController::deleteThing(int id)
{
    this->repository->deleteThing(id);
}

Thing ThingController::getThingInfo(int id)
{
    return this->repository->getThingInfo(id);
}

int ThingController::getThingRoom(int id)
{
    return this->repository->getThingInfo(id).getRoomID();
}

void ThingController::transferThing(int id, int srcRoomID, int dstRoomID)
{
    this->repository->transferThing(id, srcRoomID, dstRoomID);
}

int ThingController::getCurrentOwner(int id)
{
    return this->repository->getThingInfo(id).getOwnerID();
}

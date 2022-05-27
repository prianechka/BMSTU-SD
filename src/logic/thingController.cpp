#include "thingController.h"

ThingController::ThingController(InterfaceThingRepo &repository)
{
    this->repository = &repository;
}

ThingController::~ThingController(){}

void ThingController::addThing(int markNumber, std::string thingType)
{
    this->repository->addThing(ThingDTO(markNumber, thingType));
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

Thing ThingController::getThing(int id)
{
    return this->repository->getThing(id);
}

void ThingController::deleteThing(int id)
{
    Thing tmpThing = this->getThing(id);
    if (tmpThing.getID() >= 0)
        this->repository->deleteThing(id);
}


int ThingController::getThingRoom(int id)
{
    return this->repository->getThing(id).getRoomID();
}

void ThingController::transferThing(int id, int srcRoomID, int dstRoomID)
{
    this->repository->transferThing(id, srcRoomID, dstRoomID);
}

int ThingController::getCurrentOwner(int id)
{
    return this->repository->getThing(id).getOwnerID();
}

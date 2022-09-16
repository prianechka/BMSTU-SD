#ifndef THINGCONTROLLER_H
#define THINGCONTROLLER_H

#include "../db/thingRepo.h"
#include "../objects/room.h"
#include "../objects/thing.h"
#include "../db/exceptions.h"

class ThingController
{
private:
    InterfaceThingRepo *repository;
public:
    ThingController(InterfaceThingRepo &repository);
    ThingController();
    ~ThingController();

    void addThing(int markNumber, std::string thingType);
    std::vector<Thing> getThings();
    std::vector<Thing> getFreeThings();
    Thing getThing(int id);
    int getThingIDByMarkNumber(int markNumber);
    void deleteThing(int id);
    int getThingRoom(int id);
    void transferThing(int id, int srcRoomID, int dstRoomID);
    int getCurrentOwner(int id);
};

#endif // THINGCONTROLLER_H

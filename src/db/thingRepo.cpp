#include "thingRepo.h"

void InterfaceThingRepo::addThing(ThingDTO thing)
{}

void InterfaceThingRepo::deleteThing(int id)
{}

Thing InterfaceThingRepo::getThing(int id)
{}

void InterfaceThingRepo::transferThing(int id, int srcRoomID, int dstRoomID)
{}

std::vector<Thing> InterfaceThingRepo::getThings()
{}

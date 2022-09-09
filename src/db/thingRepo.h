#ifndef THINGREPO_H
#define THINGREPO_H

#include "../objects/thing.h"
#include <vector>

class InterfaceThingRepo
{
public:
    virtual void addThing(ThingDTO thing);
    virtual std::vector<Thing> getThings();
    virtual void deleteThing(int id);
    virtual Thing getThing(int id);
    virtual void transferThing(int id, int srcRoomID, int dstRoomID);
    virtual int getThingIDByMarkNumber(int markNumber);
};

#endif // THINGREPO_H

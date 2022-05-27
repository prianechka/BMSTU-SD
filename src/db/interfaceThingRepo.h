#ifndef INTERFACETHINGREPO_H
#define INTERFACETHINGREPO_H

#include "../objects/thing.h"
#include <vector>

class InterfaceThingRepo
{
private:
    int connection;
public:
    virtual void addThing(int markNumber, std::string type);
    virtual std::vector<Thing> getThings();
    virtual void deleteThing(int id);
    virtual Thing getThingInfo(int id);
    virtual void transferThing(int id, int srcRoomID, int dstRoomID);
};

#endif // INTERFACETHINGREPO_H

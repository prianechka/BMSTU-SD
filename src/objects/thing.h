#ifndef THING_H
#define THING_H

#include "consts.h"
#include <ctime>
#include <string>

class Thing
{
private:
    int id;
    int markNumber;
    std::time_t creationDate;
    std::string thingType;
    int ownerID;
    int roomID;

public:
    Thing(int id, int markNumber, std::time_t creationDate, std::string thingType, int ownerID, int roomID);
    Thing();
    ~Thing();
    int getID();
    int getOwnerID();
    int getRoomID();
    void setRoomID(int newID);
    std::string getThingType();
    int getMarkNumber();
};

#endif // THING_H

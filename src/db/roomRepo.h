#ifndef ROOMREPO_H
#define ROOMREPO_H

#include <iostream>
#include <string>
#include <vector>
#include "../objects/room.h"
#include "../objects/thing.h"

class InterfaceRoomRepo
{
public:
    virtual void addRoom(RoomDTO room);
    virtual std::vector<Room> getRooms();
    virtual Room getRoom(int id);
    virtual std::vector<Thing> getRoomThings(int id);
    virtual void deleteRoom(int id);
};

#endif // ROOMREPO_H

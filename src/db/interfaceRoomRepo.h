#ifndef INTERFACEROOMREPO_H
#define INTERFACEROOMREPO_H

#include <iostream>
#include <string>
#include <vector>
#include "../objects/room.h"
#include "../objects/thing.h"

class InterfaceRoomRepo
{
private:
    int connection;

public:
    virtual void addRoom(std::string roomType, int roomNumber);
    virtual std::vector<Room> getRooms();
    virtual Room getRoomInfo(int id);
    virtual std::vector<Thing> getRoomThings(int id);
    virtual void deleteRoom(int id);
};

#endif // INTERFACEROOMREPO_H

#ifndef ROOMCONTROLLER_H
#define ROOMCONTROLLER_H

#include "../objects/room.h"
#include "../objects/thing.h"
#include "../db/interfaceRoomRepo.h"

class RoomController
{
private:
    InterfaceRoomRepo *Repository;
public:
    RoomController(InterfaceRoomRepo &Repository);
    ~RoomController();

    void addRoom(std::string roomType, int number);
    std::vector<Room> getRooms();
    Room getRoomInfo(int id);
    void deleteRoom(int id);
    std::vector<Thing> getRoomThings(int id);
};

#endif // ROOMCONTROLLER_H

#ifndef PGROOMREPO_H
#define PGROOMREPO_H
#include "interfaceRoomRepo.h"

class PgRoomRepo : public InterfaceRoomRepo
{
public:
    void addRoom(std::string roomType, int roomNumber) override;
    std::vector<Room> getRooms() override;
    Room getRoomInfo(int id) override;
    std::vector<Thing> getRoomThings(int id) override;
    void deleteRoom(int id) override;
};


#endif // PGROOMREPO_H

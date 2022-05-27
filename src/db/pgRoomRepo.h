#ifndef PGROOMREPO_H
#define PGROOMREPO_H
#include "roomRepo.h"

class PgRoomRepo : public InterfaceRoomRepo
{
private:
    int connection;
public:
    void addRoom(RoomDTO room) override;
    std::vector<Room> getRooms() override;
    Room getRoom(int id) override;
    std::vector<Thing> getRoomThings(int id) override;
    void deleteRoom(int id) override;
};


#endif // PGROOMREPO_H

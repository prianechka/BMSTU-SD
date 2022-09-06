#ifndef PGROOMREPO_H
#define PGROOMREPO_H

#include "roomRepo.h"
#include "../objects/room.h"
#include "../objects/connection.h"
#include "exceptions.h"
#include "sql.h"

class PgRoomRepo : public InterfaceRoomRepo
{
private:
    std::string connectString;
    std::shared_ptr<pqxx::connection> connection;

public:
    PgRoomRepo(ConnectionParams params);
    ~PgRoomRepo() = default;
    void addRoom(RoomDTO room) override;
    std::vector<Room> getRooms() override;
    Room getRoom(int id) override;
    void deleteRoom(int id) override;
    std::vector<Thing> getRoomThings(int id) override;
};


#endif // PGROOMREPO_H

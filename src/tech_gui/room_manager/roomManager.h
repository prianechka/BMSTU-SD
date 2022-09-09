#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include "roomPrinter.h"
#include "../../logic/roomController.h"

class RoomManager {
public:
    RoomManager();
    RoomManager(RoomController &roomController);
    ~RoomManager() = default;
    void printAllRooms();
private:
    RoomController roomController;
    RoomPrinter printer;
};

#endif // ROOMMANAGER_H

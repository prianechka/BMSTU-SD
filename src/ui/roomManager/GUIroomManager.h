#ifndef GUIROOMMANAGER_H
#define GUIROOMMANAGER_H

#include "../../logic/roomController.h"

class GUIRoomManager {
public:
    GUIRoomManager();
    GUIRoomManager(RoomController &roomController);
    Room getRoomByID(int id);
    std::vector<Room> getRooms();
private:
    RoomController roomController;
};

#endif // GUIROOMMANAGER_H

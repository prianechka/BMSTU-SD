#include "roomPrinter.h"

void RoomPrinter::printRoom(Room room)
{
    std::cout << room.getID() << " тип комнаты: " << room.getRoomType() \
              << ", номер комнаты: " << room.getRoomNumber() << std::endl;
}

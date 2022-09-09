#ifndef ROOMPRINTER_H
#define ROOMPRINTER_H

#include <iostream>
#include <string>
#include "../../objects/room.h"

class RoomPrinter
{
public:
    RoomPrinter() = default;
    ~RoomPrinter() = default;
    void printRoom(Room room);
};

#endif // ROOMPRINTER_H

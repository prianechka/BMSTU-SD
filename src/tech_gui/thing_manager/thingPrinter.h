#ifndef THINGPRINTER_H
#define THINGPRINTER_H

#include <iostream>
#include <string>
#include "../../objects/thing.h"
#include "../../objects/room.h"
#include "../../objects/consts.h"

class ThingPrinter {
public:
    ThingPrinter() = default;
    ~ThingPrinter() = default;
    void printThingInfo(Thing thing, Room tmpRoom);
    void printInputStudentNumber();
    void printMarkInput();
    void printTypeInput();
    void printRoomIDInput();
    void printAddOK();
    void printException(const std::exception &e);
};

#endif // THINGPRINTER_H

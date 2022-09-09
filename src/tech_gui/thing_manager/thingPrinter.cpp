#include "thingPrinter.h"

void ThingPrinter::printThingInfo(Thing thing, Room tmpRoom)
{
    std::cout << thing.getID() << " " << thing.getThingType() << ", маркировочный номер = " <<
                 thing.getMarkNumber() << " ";

    if (tmpRoom.getRoomType() == "Склад" || tmpRoom.getID() == NONE)
    {
        std::cout << "находится на складе";
    }
    else
    {
        std::cout << "находится в комнате " << tmpRoom.getRoomNumber();
    }
    std::cout << std::endl;
}

void ThingPrinter::printInputStudentNumber()
{
    std::cout << NUMBER_INPUT_MESSAGE;
}

void ThingPrinter::printStudentNotFound()
{
    std::cout << STUDENT_NOT_FOUND;
}

void ThingPrinter::printMarkInput()
{
    std::cout << MARK_INPUT;
}

void ThingPrinter::printTypeInput()
{
    std::cout << TYPE_INPUT;
}

void ThingPrinter::printRoomIDInput()
{
    std::cout << ROOM_ID_INPUT;
}

void ThingPrinter::printThingNotFound()
{
    std::cout << THING_IS_NOT_FOUND;
}

void ThingPrinter::printRoomNotFound()
{
    std::cout << ROOM_NOT_FOUND;
}

void ThingPrinter::printAddOK()
{
    std::cout << ADD_OK;
}

void ThingPrinter::printAddError()
{
    std::cout << ADD_ERROR;
}

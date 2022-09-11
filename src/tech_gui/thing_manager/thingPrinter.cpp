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

void ThingPrinter::printMarkInput()
{
    std::cout << MARK_NUM_INPUT_MESSAGE;
}

void ThingPrinter::printTypeInput()
{
    std::cout << TYPE_INPUT_MESSAGE;
}

void ThingPrinter::printRoomIDInput()
{
    std::cout << ROOM_ID_INPUT_MESSAGE;
}

void ThingPrinter::printAddOK()
{
    std::cout << ADD_OK;
}

void ThingPrinter::printException(const std::exception &e)
{
    std::cout << e.what() << std::endl;
}

void ThingPrinter::printInputStudentNumber()
{
    std::cout << NUMBER_INPUT_MESSAGE;
}

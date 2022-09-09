#include "thingManager.h"

ThingManager::ThingManager(ThingController &thingController,
                           StudentController &studentController,
                           RoomController &roomController)
{
    this->thingController = thingController;
    this->studentController = studentController;
    this->roomController = roomController;
    this->printer = ThingPrinter();
    this->getter = ThingGetter();
}

ThingManager::ThingManager(){}

void ThingManager::handleThings(std::vector<Thing> things)
{
    for (size_t i = 0; i < things.size(); i++)
    {
        Thing tmpThing = things[i];
        Room tmpRoom = roomController.getRoom(tmpThing.getRoomID());
        this->printer.printThingInfo(things[i], tmpRoom);
    }
}

void ThingManager::viewAllThings()
{
    std::vector<Thing> things = this->thingController.getThings();
    handleThings(things);
}

void ThingManager::viewFreeThings()
{
    std::vector<Thing> things = this->thingController.getFreeThings();
    handleThings(things);
}

void ThingManager::viewStudentThings()
{
    this->printer.printInputStudentNumber();
    std::string studNumber = this->getter.getString();
    int id = this->studentController.getStudentIDByNumber(studNumber);
    if (id != NONE)
    {
        std::vector<Thing> things = this->studentController.getStudentThings(id);
        handleThings(things);
    }
    else
        this->printer.printStudentNotFound();
}

void ThingManager::addNewThing()
{
    this->printer.printTypeInput();
    std::string type = this->getter.getString();

    this->printer.printMarkInput();
    int markNumber = this->getter.getInt();

    this->thingController.addThing(markNumber, type);
    int id = this->thingController.getThingIDByMarkNumber(markNumber);
    if (id != NONE)
        this->printer.printAddOK();
    else
        this->printer.printAddOK();
}

void ThingManager::transferThing()
{
    this->printer.printMarkInput();
    int markNumber = this->getter.getInt();

    int thingID = this->thingController.getThingIDByMarkNumber(markNumber);
    if (thingID != NONE)
    {
        Thing tmpThing = this->thingController.getThing(thingID);

        this->printer.printRoomIDInput();
        int dstRoomID = this->getter.getInt();
        Room tmpRoom = roomController.getRoom(dstRoomID);
        if (tmpRoom.getID() != NONE)
        {
            thingController.transferThing(thingID, tmpRoom.getID(), dstRoomID);
            int id = this->thingController.getThingRoom(thingID);
            if (id == dstRoomID)
                this->printer.printAddOK();
            else
                this->printer.printAddError();
        }
        else
            this->printer.printRoomNotFound();
    }
    else
        this->printer.printThingNotFound();
}


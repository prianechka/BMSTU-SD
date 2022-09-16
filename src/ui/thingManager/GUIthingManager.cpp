#include "GUIthingManager.h"

GUIThingManager::GUIThingManager(ThingController &thingController,
                           StudentController &studentController,
                           RoomController &roomController)
{
    this->thingController = thingController;
    this->studentController = studentController;
    this->roomController = roomController;
}

GUIThingManager::GUIThingManager(){}

std::vector<Thing> GUIThingManager::viewAllThings()
{
    return this->thingController.getThings();
}

std::vector<Thing> GUIThingManager::viewFreeThings()
{
    return this->thingController.getFreeThings();
}

std::vector<Thing> GUIThingManager::viewStudentThings(std::string studNumber)
{
    int id = this->studentController.getStudentIDByNumber(studNumber);
    return this->studentController.getStudentThings(id);
}

void GUIThingManager::addNewThing(int markNumber, std::string type)
{
    this->thingController.addThing(markNumber, type);
}

void GUIThingManager::transferThing(int markNumber, int roomID)
{
    int thingID = this->thingController.getThingIDByMarkNumber(markNumber);
    Thing tmpThing = this->thingController.getThing(thingID);
    Room tmpRoom = this->roomController.getRoom(tmpThing.getRoomID());
    thingController.transferThing(thingID, tmpRoom.getID(), roomID);
}

#ifndef THINGMANAGER_H
#define THINGMANAGER_H

#include "../../logic/thingController.h"
#include "../../logic/studentController.h"
#include "../../logic/roomController.h"

class GUIThingManager {
public:
    GUIThingManager(ThingController &thingController,
                 StudentController &studentController,
                 RoomController &roomController);
    GUIThingManager();
    ~GUIThingManager() = default;
    std::vector<Thing> viewAllThings();
    std::vector<Thing> viewFreeThings();
    std::vector<Thing> viewStudentThings(std::string studNumber);
    void addNewThing(int markNumber, std::string type);
    void transferThing(int markNumber, int roomID);
private:
    ThingController thingController;
    StudentController studentController;
    RoomController roomController;

    void handleThings(std::vector<Thing> things);
};

#endif // THINGMANAGER_H

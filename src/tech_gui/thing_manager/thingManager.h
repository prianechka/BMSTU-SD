#ifndef THINGMANAGER_H
#define THINGMANAGER_H

#include "thingGetter.h"
#include "thingPrinter.h"
#include "../../logic/thingController.h"
#include "../../logic/studentController.h"
#include "../../logic/roomController.h"

class ThingManager {
public:
    ThingManager(ThingController &thingController,
                 StudentController &studentController,
                 RoomController &roomController);
    ThingManager();
    ~ThingManager() = default;
    void viewAllThings();
    void viewFreeThings();
    void viewStudentThings();
    void addNewThing();
    void transferThing();
private:
    ThingController thingController;
    StudentController studentController;
    RoomController roomController;
    ThingPrinter printer;
    ThingGetter getter;

    void handleThings(std::vector<Thing> things);
};



#endif // THINGMANAGER_H

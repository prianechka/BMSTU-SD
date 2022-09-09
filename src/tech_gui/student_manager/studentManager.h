#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "studentGetter.h"
#include "studentPrinter.h"

#include "../../logic/studentController.h"
#include "../../logic/userController.h"
#include "../../logic/roomController.h"
#include "../../logic/thingController.h"
#include "../../db/pgStudentRepo.h"

class StudentManager {
public:
    StudentManager(StudentController &studController, UserController &userController,
                   RoomController &roomController, ThingController &thingController);
    StudentManager();
    ~StudentManager() = default;
    void addNewStudent();
    void viewStudent();
    void viewAllStudent();
    void changeStudentInfo();
    void settleStudent();
    void evicStudent();
    void returnStudentThing();
    void giveStudentThing();
    void viewAllRooms();
private:
    StudentGetter getter;
    StudentPrinter printer;
    StudentController studentController;
    UserController userController;
    RoomController roomController;
    ThingController thingController;
};

#endif // STUDENTMANAGER_H

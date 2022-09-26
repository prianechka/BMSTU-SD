#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "../../logic/studentController.h"
#include "../../logic/userController.h"
#include "../../logic/roomController.h"
#include "../../logic/thingController.h"
#include "../../db/pgStudentRepo.h"
#include "../../db/pgRoomRepo.h"
#include "../../db/pgThingRepo.h"
#include "../../db/pgUserRepo.h"

struct StudentInfoDTO
{
    Student student;
    Room room;
};

class GUIStudentManager {
public:
    GUIStudentManager(StudentController &studController, UserController &userController,
                   RoomController &roomController, ThingController &thingController);
    GUIStudentManager();
    ~GUIStudentManager() = default;
    void addNewStudent(std::string name, std::string surname, std::string group,
                       std::string studNumber, std::string login, std::string password);
    StudentInfoDTO viewStudent(std::string studNumber);
    std::vector<Student> viewAllStudent();
    void changeStudentInfo(std::string stud, std::string newGroup);
    void settleStudent(std::string studNumber, int RoomID);
    void evicStudent(std::string studNumber);
    void returnStudentThing(std::string studNumber, int markNumber);
    void giveStudentThing(std::string studNumber, int markNumber);
    std::string getStudentByWebID(int webID);
private:
    StudentController studentController;
    UserController userController;
    RoomController roomController;
    ThingController thingController;
};

#endif // STUDENTMANAGER_H

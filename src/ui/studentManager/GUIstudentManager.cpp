#include "GUIstudentManager.h"
#include <QMessageBox>

GUIStudentManager::GUIStudentManager(StudentController &studController,
                               UserController &userController,
                               RoomController &roomController,
                               ThingController &thingController)
{
    this->studentController = studController;
    this->userController = userController;
    this->roomController = roomController;
    this->thingController = thingController;
}

GUIStudentManager::GUIStudentManager() {}

void GUIStudentManager::addNewStudent(std::string name, std::string surname, std::string group,
                                      std::string studNumber, std::string login, std::string password)
{
    this->userController.addUser(login, password, STUDENT);
    int webID = this->userController.getUserId(login);
    this->studentController.addStudent(surname, name, group, studNumber, webID);
    int tmpID = this->studentController.getStudentIDByNumber(studNumber);
    if (tmpID == NONE)
        throw StudentAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

StudentInfoDTO GUIStudentManager::viewStudent(std::string studentNumber)
{
    StudentInfoDTO result;
    int tmpID = this->studentController.getStudentIDByNumber(studentNumber);
    result.student = this->studentController.getStudent(tmpID);
    if (result.student.getRoomID() != NONE)
        result.room = this->roomController.getRoom(result.student.getRoomID());
    else
        result.room = Room();
    return result;
}

std::vector<Student> GUIStudentManager::viewAllStudent()
{
    return this->studentController.getAllStudents();
}

void GUIStudentManager::changeStudentInfo(std::string stud, std::string newGroup)
{
    int tmpID = this->studentController.getStudentIDByNumber(stud);
    this->studentController.changeStudentGroup(tmpID, newGroup);
}

void GUIStudentManager::settleStudent(std::string studNumber, int roomID)
{
    int tmpID = this->studentController.getStudentIDByNumber(studNumber);
    Student tmpStudent = this->studentController.getStudent(tmpID);
    this->studentController.settleStudent(tmpStudent.getID(), roomID);
}

void GUIStudentManager::evicStudent(std::string studNumber)
{
    int tmpID = this->studentController.getStudentIDByNumber(studNumber);
    Student tmpStudent = this->studentController.getStudent(tmpID);
    this->studentController.evicStudent(tmpStudent.getID());
}

void GUIStudentManager::giveStudentThing(std::string studNumber, int markNumber)
{
    int tmpID = this->studentController.getStudentIDByNumber(studNumber);
    int tmpThingID = this->thingController.getThingIDByMarkNumber(markNumber);
    int owner = this->thingController.getCurrentOwner(tmpThingID);
    if (owner == NONE)
    {
        this->studentController.transferThing(tmpID, tmpThingID);
        owner = this->thingController.getCurrentOwner(tmpThingID);
        if (owner != tmpID)
            throw ThingBadTransferException(__FILE__, typeid(*this).name(), __LINE__);
    }
    else
        throw ThingBadTransferException(__FILE__, typeid(*this).name(), __LINE__);
}

void GUIStudentManager::returnStudentThing(std::string studNumber, int markNumber)
{
    int tmpID = this->studentController.getStudentIDByNumber(studNumber);
    if (tmpID != NONE)
    {
        int tmpThingID = this->thingController.getThingIDByMarkNumber(markNumber);
        if (tmpThingID != NONE)
        {
            int owner = this->thingController.getCurrentOwner(tmpThingID);
            if (owner == tmpID)
            {
                this->studentController.returnThing(tmpID, tmpThingID);
            }
            else
                throw ThingBadTransferException(__FILE__, typeid(*this).name(), __LINE__);
        }
    }
}

std::string GUIStudentManager::getStudentByWebID(int webID)
{
    std::string result = "";
    std::vector<Student> students = this->studentController.getAllStudents();
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i].getAccID() == webID)
        {
            result = students[i].getStudentNumber();
            break;
        }
    }
    return result;
}

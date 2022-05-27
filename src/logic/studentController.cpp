#include "studentController.h"

StudentController::StudentController(InterfaceStudentRepo &repository)
{
    this->repository = &repository;
}

StudentController::~StudentController() {};

void StudentController::addStudent(std::string surname, std::string name, std::string group, std::string studentNumber)
{
    this->repository->addStudent(StudentDTO(surname, name, group, studentNumber));
}

std::vector<Student> StudentController::getAllStudents()
{
    return this->repository->getAllStudents();
}

int StudentController::getStudentIDByNumber(std::string studentNumber)
{
    int result = -1;
    std::vector<Student> studentArray = this->repository->getAllStudents();

    for (Student tmpStudent : studentArray)
    {
        if (tmpStudent.getStudentNumber() == studentNumber)
        {
            result = tmpStudent.getID();
            break;
        }
    }
    return result;
}

Student StudentController::getStudent(int id)
{
    return this->repository->getStudent(id);
}

int StudentController::getStudentRoom(int id)
{
    return this->repository->getStudent(id).getRoomID();
}

void StudentController::settleStudent(int studentID, int roomID)
{
    int tmpRoom = this->getStudentRoom(studentID);
    if (tmpRoom == NONE)
        this->repository->settleStudent(studentID, roomID);
}

void StudentController::evicStudent(int id)
{
    int tmpRoom = this->getStudentRoom(id);
    if (tmpRoom > 0)
        this->repository->evicStudent(id);
}

void StudentController::changeStudentGroup(int id, std::string newGroup)
{
    this->repository->changeStudentGroup(id, newGroup);
}

void StudentController::changeStudentName(int id, std::string newName)
{
    this->repository->changeStudentName(id, newName);
}

void StudentController::changeStudentSurname(int id, std::string newSurname)
{
    this->repository->changeStudentSurname(id, newSurname);
}

std::vector<Thing> StudentController::getStudentThings(int id)
{
    return this->repository->getStudentThings(id);
}

void StudentController::transferThing(int studentID, int thingID)
{
    this->repository->transferThing(studentID, thingID, GET);
}

void StudentController::returnThing(int studentID, int thingID)
{
    this->repository->transferThing(studentID, thingID, RET);
}

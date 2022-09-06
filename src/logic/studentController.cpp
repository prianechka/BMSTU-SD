#include "studentController.h"

StudentController::StudentController(InterfaceStudentRepo &repository)
{
    this->repository = &repository;
}

StudentController::~StudentController() {};

void StudentController::addStudent(std::string surname, std::string name, std::string group,
                                   std::string studentNumber, int webID)
{
    this->repository->addStudent(StudentDTO(surname, name, group, studentNumber), webID);
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
        this->repository->transferStudent(studentID, roomID, GET);
}

void StudentController::evicStudent(int studentID)
{
    int tmpRoom = this->getStudentRoom(studentID);
    if (tmpRoom > 0)
        this->repository->transferStudent(studentID, tmpRoom, RET);
}

void StudentController::changeStudentGroup(int id, std::string newGroup)
{
    Student tmpStudent = this->getStudent(id);
    StudentDTO tmpDTO = StudentDTO(tmpStudent.getName(), tmpStudent.getSurname(),
                                   newGroup, tmpStudent.getStudentNumber());

    this->repository->changeStudent(id, tmpDTO);
}

void StudentController::changeStudentName(int id, std::string newName)
{
    Student tmpStudent = this->getStudent(id);
    StudentDTO tmpDTO = StudentDTO(newName, tmpStudent.getSurname(),
                                   tmpStudent.getStudentGroup(), tmpStudent.getStudentNumber());

    this->repository->changeStudent(id, tmpDTO);
}

void StudentController::changeStudentSurname(int id, std::string newSurname)
{
    Student tmpStudent = this->getStudent(id);
    StudentDTO tmpDTO = StudentDTO(tmpStudent.getName(), newSurname,
                                   tmpStudent.getStudentGroup(), tmpStudent.getStudentNumber());

    this->repository->changeStudent(id, tmpDTO);
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

#include "studentController.h"

StudentController::StudentController(InterfaceStudentRepo &repository)
{
    this->repository = &repository;
}

StudentController::StudentController(){}

StudentController::~StudentController() {};

void StudentController::addStudent(std::string name, std::string surname, std::string group,
                                   std::string studentNumber, int webID)
{
    if (webID < 0)
        throw UserNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (name.length() < 1 or surname.length() < 1 or group.length() < 1 or
            studentNumber.length() < 1)
        throw StudentAddErrorException(__FILE__, typeid (*this).name(), __LINE__);
    std::vector<Student> students = this->repository->getAllStudents();
    for (size_t i = 0; i < students.size(); i++)
        if (students[i].getStudentNumber() == studentNumber)
            throw StudentAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->addStudent(StudentDTO(name, surname, group, studentNumber), webID);
    int id = this->repository->getStudentID(studentNumber);
    if (id == NONE)
        throw StudentAddErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

std::vector<Student> StudentController::getAllStudents()
{
    return this->repository->getAllStudents();
}

int StudentController::getStudentIDByNumber(std::string studentNumber)
{
    int result = NONE;
    std::vector<Student> studentArray = this->repository->getAllStudents();

    for (Student tmpStudent : studentArray)
    {
        if (tmpStudent.getStudentNumber() == studentNumber)
        {
            result = tmpStudent.getID();
            break;
        }
    }
    if (result == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    else
        return result;
}

Student StudentController::getStudent(int id)
{
    if (id < 0)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    Student tmpStudent = this->repository->getStudent(id);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    return tmpStudent;
}

int StudentController::getStudentRoom(int id)
{
    if (id < 0)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    Student tmpStudent = this->repository->getStudent(id);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    return tmpStudent.getRoomID();
}

void StudentController::settleStudent(int studentID, int roomID)
{
    Student tmpStudent = this->repository->getStudent(studentID);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpStudent.getRoomID() == NOT_LIVING)
    {
        this->repository->transferStudent(studentID, roomID, GET);
        tmpStudent = this->repository->getStudent(studentID);
        if (tmpStudent.getRoomID() != roomID)
            throw SettleErrorException(__FILE__, typeid(*this).name(), __LINE__);
    }
    else
    {
        throw BadSettleException(__FILE__, typeid(*this).name(), __LINE__);
    }
}

void StudentController::evicStudent(int studentID)
{
    Student tmpStudent = this->repository->getStudent(studentID);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    int roomID = tmpStudent.getRoomID();
    if (roomID != NOT_LIVING)
    {
        this->repository->transferStudent(studentID, roomID, RET);
        tmpStudent = this->repository->getStudent(studentID);
        if (tmpStudent.getRoomID() != NOT_LIVING)
            throw EvicErrorException(__FILE__, typeid(*this).name(), __LINE__);
    }
    else
        throw BadEvicException(__FILE__, typeid(*this).name(), __LINE__);
}

void StudentController::changeStudentGroup(int id, std::string newGroup)
{
    Student tmpStudent = this->repository->getStudent(id);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);

    StudentDTO tmpDTO = StudentDTO(tmpStudent.getName(), tmpStudent.getSurname(),
                                   newGroup, tmpStudent.getStudentNumber());
    this->repository->changeStudent(id, tmpDTO);

    tmpStudent = this->repository->getStudent(id);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpStudent.getStudentGroup() != newGroup)
        throw StudentChangeErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

void StudentController::changeStudentName(int id, std::string newName)
{
    Student tmpStudent = this->repository->getStudent(id);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);

    StudentDTO tmpDTO = StudentDTO(newName, tmpStudent.getSurname(),
                                   tmpStudent.getStudentGroup(), tmpStudent.getStudentNumber());
    this->repository->changeStudent(id, tmpDTO);

    tmpStudent = this->repository->getStudent(id);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpStudent.getName() != newName)
        throw StudentChangeErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

void StudentController::changeStudentSurname(int id, std::string newSurname)
{
    Student tmpStudent = this->repository->getStudent(id);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);

    StudentDTO tmpDTO = StudentDTO(tmpStudent.getSurname(), newSurname,
                                   tmpStudent.getStudentGroup(), tmpStudent.getStudentNumber());
    this->repository->changeStudent(id, tmpDTO);

    tmpStudent = this->repository->getStudent(id);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    if (tmpStudent.getSurname() != newSurname)
        throw StudentChangeErrorException(__FILE__, typeid(*this).name(), __LINE__);
}

std::vector<Thing> StudentController::getStudentThings(int id)
{
    Student tmpStudent = this->repository->getStudent(id);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    return this->repository->getStudentThings(id);
}

void StudentController::transferThing(int studentID, int thingID)
{
    Student tmpStudent = this->repository->getStudent(studentID);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->transferThing(studentID, thingID, GET);
}

void StudentController::returnThing(int studentID, int thingID)
{
    Student tmpStudent = this->repository->getStudent(studentID);
    if (tmpStudent.getID() == NONE)
        throw StudentNotFoundException(__FILE__, typeid(*this).name(), __LINE__);
    this->repository->transferThing(studentID, thingID, RET);
}

#include "student.h"

Student::Student(int id, int idWebAcc, std::string name, std::string surname,
                 std::time_t settleDate, std::string studentGroup, std::string studentNumber, int roomID)
{
    this->id = id;
    this->idWebAcc = idWebAcc;
    this->name = name;
    this->surname = surname;
    this->settleDate = settleDate;
    this->studentGroup = studentGroup;
    this->studentNumber = studentNumber;
    this->roomID = roomID;
}

Student::Student()
{
    this->id = NONE;
    this->idWebAcc = NONE;
    this->name = EMPTY;
    this->surname = EMPTY;
    this->settleDate = CUR_TIME;
    this->studentGroup = EMPTY;
    this->studentNumber = EMPTY;
    this->roomID = NONE;
}

Student::~Student()
{};

std::string Student::getName()
{
    return this->name;
}

std::string Student::getSurname()
{
    return this->surname;
}

std::string Student::getStudentGroup()
{
    return this->studentGroup;
}

std::string Student::getStudentNumber()
{
    return this->studentNumber;
}

int Student::getID()
{
    return this->id;
}

int Student::getRoomID()
{
    return this->roomID;
}

void Student::setRoomID(int roomID)
{
    this->roomID = roomID;
}

void Student::setGroup(std::string newGroup)
{
    this->studentGroup = newGroup;
}

void Student::setName(std::string newName)
{
    this->name = newName;
}

void Student::setSurname(std::string newSurname)
{
    this->surname = newSurname;
}

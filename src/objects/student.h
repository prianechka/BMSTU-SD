#ifndef STUDENT_H
#define STUDENT_H

#include "consts.h"
#include <iostream>
#include <string>
#include <ctime>


class Student
{
private:
    int id;
    int idWebAcc;
    std::string name;
    std::string surname;
    std::time_t settleDate;
    std::string studentGroup;
    std::string studentNumber;
    int roomID;

public:
    Student(int id, int idWebAcc, std::string name, std::string surname,
            std::time_t settleDate, std::string studentGroup, std::string studentNumber, int roomID);
    Student();
    ~Student();

    std::string getStudentGroup();
    std::string getStudentNumber();
    std::string getName();
    std::string getSurname();

    int getRoomID();
    int getID();
    int getAccID();

    void setRoomID(int roomID);
    void setGroup(std::string newGroup);
    void setName(std::string newName);
    void setSurname(std::string newSurname);
};

class StudentDTO
{
private:
    std::string name;
    std::string surname;
    std::string studentGroup;
    std::string studentNumber;

public:
    StudentDTO(std::string name, std::string surname, std::string studentGroup, std::string studentNumber);
    ~StudentDTO() = default;

    std::string getStudentGroup();
    std::string getStudentNumber();
    std::string getName();
    std::string getSurname();
};

#endif // STUDENT_H

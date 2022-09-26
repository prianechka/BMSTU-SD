#ifndef STUDENTPRINTER_H
#define STUDENTPRINTER_H

#include <vector>
#include "../../objects/student.h"
#include "../../objects/consts.h"


class StudentPrinter {
public:
    StudentPrinter() = default;
    ~StudentPrinter() = default;
    void printStudent(Student tmpStudent);
    void printStudentRoom(int number);
    void printAllStudents(std::vector<Student> allStudents);
    void printChangeStudentInfo();
    void printInputName();
    void printInputSurname();
    void printInputGroup();
    void printInputStudentNumber();
    void printInputLogin();
    void printInputPassword();
    void printIDRoom();
    void printMarkNumInput();
    void printGiveOK();
    void printReturnOK();
    void printEvicOK();
    void printException(const std::exception &e);
};

#endif // STUDENTPRINTER_H

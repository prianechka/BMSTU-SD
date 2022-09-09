#ifndef STUDENTPRINTER_H
#define STUDENTPRINTER_H

#include <vector>
#include "../../objects/student.h"

const std::string NAME_INPUT_MESSAGE = "Введите имя студента: ";
const std::string SURNAME_INPUT_MESSAGE = "Введите фамилию студента: ";
const std::string GROUP_INPUT_MESSAGE = "Введите номер группы студента: ";
const std::string NUMBER_INPUT_MESSAGE = "Введите номер студенческого билета: ";
const std::string LOG_INPUT_MESSAGE = "Введите новый логин студента: ";
const std::string PASSWORD_INPUT_MESSAGE = "Введите новый пароль студента: ";
const std::string ID_ROOM_INPUT = "Введите ID комнаты студента: ";
const std::string EVIC_ERROR = "\nСтудент уже нигде не живёт! \n";
const std::string EVIC_GOOD = "\nСтудент успешно выселен!\n";
const std::string SETTLE_ERROR = "\nСтудент уже живёт в другой комнате!\n";
const std::string SETTLE_GOOD = "\nСтудент успешно заселён!\n";
const std::string STUDENT_NOT_FOUND = "\nСтудент не найден!\n";
const std::string MARK_NUM_INPUT = "Введите маркировочный номер вещи: ";
const std::string THING_NOT_FOUND = "\nВещь не найдена!\n";
const std::string GIVE_ERROR = "\nВещь уже у другого студента!\n";
const std::string GIVE_OK = "\nВещь передана!\n";
const std::string RETURN_ERROR = "\nВещь и так была не у студента!\n";
const std::string RETURN_OK = "\nВещь отдана обратно!\n";

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
    void printSettleError();
    void printEvicError();
    void printMarkNumInput();
    void printThingNotFound();
    void printGiveError();
    void printGiveOK();
    void printReturnError();
    void printReturnOK();
    void printStudentNotFound();
};

#endif // STUDENTPRINTER_H

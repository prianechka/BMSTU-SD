#include "studentPrinter.h"

void StudentPrinter::printStudent(Student tmpStudent)
{
    std::cout << "Студент: " << tmpStudent.getSurname() << " " << tmpStudent.getName() \
              << " , группа - " << tmpStudent.getStudentGroup() << " , номер студ.билета - " \
              << tmpStudent.getStudentNumber() << std::endl;
}

void StudentPrinter::printStudentRoom(int number)
{
    if (number == NONE)
        std::cout << "Не проживает в общежитии" << std::endl;
    else
        std::cout << "Проживает в комнате " << number << std::endl;
}

void StudentPrinter::printAllStudents(std::vector<Student> allStudents)
{
    for (size_t i = 0; i < allStudents.size(); i++)
        printStudent(allStudents[i]);
}

void StudentPrinter::printInputName()
{
    std::cout << NAME_INPUT_MESSAGE;
}

void StudentPrinter::printInputSurname()
{
    std::cout << SURNAME_INPUT_MESSAGE;
}

void StudentPrinter::printInputGroup()
{
    std::cout << GROUP_INPUT_MESSAGE;
}

void StudentPrinter::printInputStudentNumber()
{
    std::cout << NUMBER_INPUT_MESSAGE;
}

void StudentPrinter::printInputLogin()
{
    std::cout << LOG_INPUT_MESSAGE;
}

void StudentPrinter::printInputPassword()
{
    std::cout << PASSWORD_INPUT_MESSAGE;
}

void StudentPrinter::printIDRoom()
{
    std::cout << ID_ROOM_INPUT;
}

void StudentPrinter::printEvicError()
{
    std::cout << EVIC_ERROR;
}

void StudentPrinter::printSettleError()
{
    std::cout << SETTLE_ERROR;
}

void StudentPrinter::printThingNotFound()
{
    std::cout << THING_NOT_FOUND;
}


void StudentPrinter::printGiveError()
{
    std::cout << GIVE_ERROR;
}

void StudentPrinter::printGiveOK()
{
    std::cout << GIVE_OK;
}

void StudentPrinter::printReturnError()
{
    std::cout << RETURN_ERROR;
}

void StudentPrinter::printReturnOK()
{
    std::cout << RETURN_OK;
}

void StudentPrinter::printStudentNotFound()
{
    std::cout << STUDENT_NOT_FOUND;
}

void StudentPrinter::printMarkNumInput()
{
    std::cout << MARK_NUM_INPUT;
}

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <iostream>
#include "../objects/consts.h"

class BaseException: public std::exception
{
    public:
    BaseException(std::string fileName, std::string className,
              int currentLine,
              std::string information);

    virtual const char *what() const noexcept override;

protected:
    std::string information;
};

class DatabaseConnectException: public BaseException
{
    public:
        DatabaseConnectException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = DB_CONNECT_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class StudentNotFoundException : public BaseException
{
    public:
        StudentNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = STUDENT_NOT_FOUND_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class UserNotFoundException : public BaseException
{
    public:
        UserNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = USER_NOT_FOUND_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class UserAddErrorException : public BaseException
{
    public:
        UserAddErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = USER_ADD_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class StudentAddErrorException : public BaseException
{
    public:
        StudentAddErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = STUDENT_ADD_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class StudentChangeErrorException : public BaseException
{
    public:
        StudentChangeErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = STUDENT_CHANGE_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class LoginNotFoundException : public BaseException
{
    public:
        LoginNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = LOGIN_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class IncorrectPassportException : public BaseException
{
    public:
        IncorrectPassportException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = PASSWORD_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class BadEvicException : public BaseException
{
    public:
        BadEvicException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = EVIC_STUDENT_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class BadSettleException : public BaseException
{
    public:
        BadSettleException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = SETTLE_STUDENT_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class SettleErrorException : public BaseException
{
    public:
        SettleErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = SETTLE_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class EvicErrorException : public BaseException
{
    public:
        EvicErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = EVIC_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class ThingNotFoundException : public BaseException
{
    public:
        ThingNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = THING_NOT_FOUND):
        BaseException(filename, classname, number_of_line, information) {};

};

class ThingNotRoomException : public BaseException
{
    public:
        ThingNotRoomException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = THING_NOT_IN_ROOM_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class ThingBadTransferException : public BaseException
{
    public:
        ThingBadTransferException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = BAD_TRANSFER_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};


class BadThingAddException : public BaseException
{
    public:
        BadThingAddException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = ADD_THING_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class RoomNotFoundException : public BaseException
{
    public:
        RoomNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = ROOM_NOT_FOUND_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class BadRoomDeleteException : public BaseException
{
    public:
        BadRoomDeleteException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = DELETE_ROOM_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class GiveThingToStudentException : public BaseException
{
    public:
        GiveThingToStudentException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = GIVE_THING_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class ReturnThingToStudentException : public BaseException
{
    public:
        ReturnThingToStudentException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = RETURN_THING_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};

class InputIntErrorException : public BaseException
{
    public:
        InputIntErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = INT_ERROR):
        BaseException(filename, classname, number_of_line, information) {};

};
#endif // EXCEPTIONS_H

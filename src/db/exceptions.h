#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <iostream>

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
                          std::string information = "Не получилось подключиться к Базе данных!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class StudentNotFoundException : public BaseException
{
    public:
        StudentNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Студент не найден!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class UserNotFoundException : public BaseException
{
    public:
        UserNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Пользователь не найден!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class UserAddErrorException : public BaseException
{
    public:
        UserAddErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Пользователя не удалось добавить!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class StudentAddErrorException : public BaseException
{
    public:
        StudentAddErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Студента не удалось добавить!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class StudentChangeErrorException : public BaseException
{
    public:
        StudentChangeErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Не удалось изменить данные студента!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class LoginNotFoundException : public BaseException
{
    public:
        LoginNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Такого логина не существует!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class IncorrectPassportException : public BaseException
{
    public:
        IncorrectPassportException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Пароль введен неверно!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class BadEvicException : public BaseException
{
    public:
        BadEvicException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Студент уже нигде не живёт!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class BadSettleException : public BaseException
{
    public:
        BadSettleException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Студент уже живёт в другой комнате!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class SettleErrorException : public BaseException
{
    public:
        SettleErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Не удалось заселить студента!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class EvicErrorException : public BaseException
{
    public:
        EvicErrorException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Не удалось выселить студента!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class ThingNotFoundException : public BaseException
{
    public:
        ThingNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Вещь не найдена!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class ThingNotRoomException : public BaseException
{
    public:
        ThingNotRoomException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Вещь не находится в этой комнате!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class ThingBadTransferException : public BaseException
{
    public:
        ThingBadTransferException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Не удалось осуществить действие!"):
        BaseException(filename, classname, number_of_line, information) {};

};


class BadThingAddException : public BaseException
{
    public:
        BadThingAddException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Вещь не удалось добавить!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class RoomNotFoundException : public BaseException
{
    public:
        RoomNotFoundException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Комната не найдена!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class BadRoomDeleteException : public BaseException
{
    public:
        BadRoomDeleteException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Не удалось удалить комнату!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class GiveThingToStudentException : public BaseException
{
    public:
        GiveThingToStudentException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Вещь уже у другого студента!"):
        BaseException(filename, classname, number_of_line, information) {};

};

class ReturnThingToStudentException : public BaseException
{
    public:
        ReturnThingToStudentException(std::string filename, std::string classname,
                          int number_of_line,
                          std::string information = "Вещь и так была не у студента!"):
        BaseException(filename, classname, number_of_line, information) {};

};
#endif // EXCEPTIONS_H

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
                          std::string information = "Can't connect to database"):
        BaseException(filename, classname, number_of_line, information) {};

};

#endif // EXCEPTIONS_H

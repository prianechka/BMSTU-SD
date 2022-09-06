#include "exceptions.h"

BaseException::BaseException(std::string fileName, std::string className,
                             int currentLine, std::string information)
{
   information = "\nFile: " + fileName + "\nClass: " + className + "\nAt line: " +
           std::to_string(currentLine) + "About error: " + information;
}

const char *BaseException::what() const noexcept
{
    const char *result = information.c_str();
    return result;
}

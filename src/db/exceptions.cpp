#include "exceptions.h"

BaseException::BaseException(std::string fileName, std::string className,
                             int currentLine, std::string information)
{
   this->information = information;
}

const char *BaseException::what() const noexcept
{
    const char *result = information.c_str();
    return result;
}

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include "../objects/consts.h"

class LogAction
{
public:
    LogAction() = default;
    ~LogAction() = default;
    void log(std::string logString);
};

#endif // LOG_H

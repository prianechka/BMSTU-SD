#include "log.h"

void LogAction::log(std::string logString)
{
    std::ofstream out(LOG_FILE, std::fstream::app);
    if (out.is_open())
    {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        out << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << ":" << logString << std::endl;
    }
}

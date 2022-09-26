#include "configManager.h"

std::string ConfigManager::getDB()
{
    std::string result = "Test";
    std::ifstream out(CONF_FILE, std::fstream::in);
    if (out.is_open())
    {
        out >> result;
    }
    return result;
}

ConnectionParams ConfigManager::getParams()
{
    std::ifstream out(PARAMS_FILE, std::fstream::in);
    if (out.is_open())
    {
        std::string user, host, dbname, password, port;
        out >> user >> host >> dbname >> password >> port;
        return ConnectionParams(user, host, dbname, password, std::atoi(port.c_str()));
    }
    else
        return ConnectionParams();
}

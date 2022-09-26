#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <iostream>
#include <fstream>
#include "../objects/connection.h"
#include "../objects/consts.h"

class ConfigManager {
public:
    ConfigManager() = default;
    ~ConfigManager() = default;
    std::string getDB();
    ConnectionParams getParams();
};

#endif // CONFIGMANAGER_H

#include "thingGetter.h"

std::string ThingGetter::getString()
{
    std::string result;
    std::cin >> result;
    return result;
}

bool ThingGetter::check_is_number(std::string req)
{
    return !req.empty() && std::all_of(req.begin(), req.end(), ::isdigit);
}

int ThingGetter::getInt()
{
    std::string str;
    int result = NONE;
    std::cin >> str;
    if (check_is_number(str))
        result = std::stoi(str);
    return result;
}

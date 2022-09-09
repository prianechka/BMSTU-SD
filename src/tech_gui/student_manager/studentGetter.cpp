#include "studentGetter.h"

std::string StudentGetter::getString() {
    std::string result;
    std::cin >> result;
    return result;
}

bool StudentGetter::check_is_number(std::string req)
{
    return !req.empty() && std::all_of(req.begin(), req.end(), ::isdigit);
}

int StudentGetter::getInt()
{
    std::string str;
    int result = NONE;
    std::cin >> str;
    if (check_is_number(str))
        result = std::stoi(str);
    return result;
}

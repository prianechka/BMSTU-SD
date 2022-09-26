#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

enum REQUEST_KEYS {
    EXIT,
    UN_AUTH,
    AUTH,
    VIEW_ALL_STUDENTS,
    VIEW_STUDENT,
    ADD_STUDENT,
    CHANGE_STUDENT,
    SETTLE_STUDENT,
    EVIC_STUDENT,
    VIEW_THINGS,
    VIEW_FREE_THINGS,
    ADD_THING,
    GIVE_THING,
    RETURN_THING,
    CHANGE_THING_LOC,
    VIEW_STUDENT_THINGS,
    VIEW_ROOMS,
    NOT_A_COMMAND
};

class RequestHandler {
public:
    RequestHandler() = default;
    ~RequestHandler() = default;
    REQUEST_KEYS handle(std::string req);
private:
    bool check_is_number(std::string req);
};

#endif // REQUEST_H

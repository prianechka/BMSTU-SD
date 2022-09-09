#ifndef STUDENTGETTER_H
#define STUDENTGETTER_H

#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include "../../objects/consts.h"

class StudentGetter
{
public:
    std::string getString();
    int getInt();
    bool check_is_number(std::string req);
};

#endif // STUDENTGETTER_H

#ifndef THINGGETTER_H
#define THINGGETTER_H

#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include "../../objects/consts.h"

class ThingGetter {
public:
    std::string getString();
    int getInt();
    bool check_is_number(std::string req);
};

#endif // THINGGETTER_H

#ifndef AUTHPRINTER_H
#define AUTHPRINTER_H

#include <iostream>
#include <string>
#include "../../objects/consts.h"

class AuthPrinter
{
public:
    AuthPrinter() = default;
    ~AuthPrinter() = default;
    void print_login_entry();
    void print_passoword_entry();
    void print_error_login();
    void print_error_password();
    void print_ok();
    void printException(const std::exception &e);
};

#endif // AUTHPRINTER_H

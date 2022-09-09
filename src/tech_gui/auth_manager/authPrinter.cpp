#include "authPrinter.h"

void AuthPrinter::print_login_entry() {
    std::cout << LOGIN_MESSAGE;
}

void AuthPrinter::print_passoword_entry() {
    std::cout << PASSWORD_MESSAGE;
}

void AuthPrinter::print_error_login() {
    std::cout << LOGIN_ERROR;
}

void AuthPrinter::print_error_password() {
    std::cout << PASSWORD_ERROR;
}

void AuthPrinter::print_ok() {
    std::cout << OK;
}

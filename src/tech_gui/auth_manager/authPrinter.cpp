#include "authPrinter.h"

void AuthPrinter::print_login_entry() {
    std::cout << LOGIN_INPUT_MESSAGE;
}

void AuthPrinter::print_passoword_entry() {
    std::cout << PASSWORD_INPUT_MESSAGE;
}

void AuthPrinter::print_ok() {
    std::cout << AUTH_OK;
}

void AuthPrinter::printException(const std::exception &e)
{
    std::cout << e.what() << std::endl;
}

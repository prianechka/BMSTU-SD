#ifndef AUTHPRINTER_H
#define AUTHPRINTER_H

#include <iostream>
#include <string>

const std::string LOGIN_MESSAGE = "Введите логин: ";
const std::string PASSWORD_MESSAGE = "Введите пароль: ";
const std::string LOGIN_ERROR = "\nТакого логина не существует!\n";
const std::string PASSWORD_ERROR = "\nПароль введен неверно!\n";
const std::string OK = "\nАвторизация прошла успешно!";

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
};

#endif // AUTHPRINTER_H

#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <string>

const std::string MENU_ENTRIES = "\n\n\
0.  Выйти из программы.\n\
1.  Выйти из аккаунта.\n\
2.  Войти в аккаунт.\n\
3.  Посмотреть список студентов.\n\
4.  Посмотреть детали студента.\n\
5.  Добавить нового студента.\n\
6.  Изменить данные студента.\n\
7.  Заселить студента.\n\
8.  Выселить студента.\n\
9.  Посмотреть список вещей.\n\
10. Посмотреть список доступных вещей.\n\
11. Добавить новую вещь.\n\
12. Выдать новую вещь студенту.\n\
13. Забрать вещь у студента.\n\
14. Изменить место хранения вещи\n\
15. Посмотреть список вещей студента\n\
16. Посмотреть список комнат\n\n\
Введите команду: ";

const std::string NOT_COMMAND = "Такой команды не существует!\nВведите заново!\n\n";
const std::string NOT_ROLE = "Эту команду невозможно выполнить в текущем статусе!\n\n";

class AppPrinter
{
public:
     AppPrinter() = default;
     ~AppPrinter() = default;
     void print_menu();
     void print_not_a_command();
     void print_not_role();
};
#endif // PRINTER_H

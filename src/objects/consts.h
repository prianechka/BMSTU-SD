#ifndef S_H
#define S_H

#define NONE -1
#define NOT_LIVING 0
#define EMPTY std::string("")
#define CUR_TIME std::time(nullptr);

#include <string>

enum transferDirection
{
    RET = 0, GET = 1
};

const std::string LOGIN_INPUT_MESSAGE = "Введите логин: ";
const std::string PASSWORD_INPUT_MESSAGE = "Введите пароль: ";
const std::string MARK_INPUT_MESSAGE = "Введите маркировочный номер: ";
const std::string TYPE_INPUT_MESSAGE = "Введите тип вещи: ";
const std::string NAME_INPUT_MESSAGE = "Введите имя студента: ";
const std::string SURNAME_INPUT_MESSAGE = "Введите фамилию студента: ";
const std::string GROUP_INPUT_MESSAGE = "Введите номер группы студента: ";
const std::string NUMBER_INPUT_MESSAGE = "Введите номер студенческого билета: ";
const std::string ID_ROOM_INPUT_MESSAGE = "Введите ID комнаты студента: ";
const std::string ROOM_ID_INPUT_MESSAGE = "Введите ID комнаты: ";
const std::string MARK_NUM_INPUT_MESSAGE = "Введите маркировочный номер вещи: ";

const std::string AUTH_OK = "\nАвторизация прошла успешно!";
const std::string EVIC_STUDENT_GOOD = "\nСтудент успешно выселен!\n";
const std::string SETTLE_STUDENT_GOOD = "\nСтудент успешно заселён!\n";
const std::string GIVE_THING_OK = "\nВещь передана!\n";
const std::string RETURN_THING_OK = "\nВещь отдана обратно!\n";
const std::string ADD_OK = "\nОперация успешно проведена!";

const std::string STUDENT_NOT_FOUND_ERROR = "\nСтудент не найден!\n";
const std::string RETURN_THING_ERROR = "\nВещь и так была не у студента!\n";
const std::string THING_NOT_FOUND = "\nВещь не найдена!\n";
const std::string GIVE_THING_ERROR = "\nВещь уже у другого студента!\n";
const std::string SETTLE_STUDENT_ERROR = "\nСтудент уже живёт в другой комнате!\n";
const std::string EVIC_STUDENT_ERROR = "\nСтудент уже нигде не живёт! \n";
const std::string USER_NOT_FOUND_ERROR = "\nПользователь не найден!";
const std::string USER_ADD_ERROR = "Пользователя не удалось добавить!";
const std::string STUDENT_ADD_ERROR = "Студента не удалось добавить!";
const std::string STUDENT_CHANGE_ERROR = "Не удалось изменить данные студента!";
const std::string LOGIN_ERROR = "\nТакого логина не существует!\n";
const std::string PASSWORD_ERROR = "\nПароль введен неверно!\n";
const std::string ROOM_NOT_FOUND_ERROR = "\nКомната не найден!";
const std::string THING_NOT_IN_ROOM_ERROR = "Вещь не находится в этой комнате!";
const std::string DELETE_ROOM_ERROR = "Не удалось удалить комнату!";
const std::string DELETE_THING_ERROR = "Не удалось удалить вещь!";
const std::string ADD_THING_ERROR = "Не удалось добавить вещь!";
const std::string SETTLE_ERROR = "Не удалось заселить студента!";
const std::string EVIC_ERROR = "Не удалось выселить студента!";
const std::string BAD_TRANSFER_ERROR = "Не удалось осуществить действие";
const std::string DB_CONNECT_ERROR = "Не получилось подключиться к Базе данных!";
const std::string INT_ERROR = "Неправильно введено целое число!";


#endif // S_H

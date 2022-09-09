#ifndef THINGPRINTER_H
#define THINGPRINTER_H

#include <iostream>
#include <string>
#include "../../objects/thing.h"
#include "../../objects/room.h"
#include "../student_manager/studentPrinter.h"

const std::string MARK_INPUT = "Введите маркировочный номер: ";
const std::string TYPE_INPUT = "Введите тип вещи: ";
const std::string ROOM_ID_INPUT = "Введите ID комнаты: ";
const std::string THING_IS_NOT_FOUND = "\nВещь не найдена!\n";
const std::string ROOM_NOT_FOUND = "\nКомната не найдена!\n";
const std::string ADD_OK = "\nОперация успешно добавлена!";
const std::string ADD_ERROR = "\nСлучилась неудача!";

class ThingPrinter {
public:
    ThingPrinter() = default;
    ~ThingPrinter() = default;
    void printThingInfo(Thing thing, Room tmpRoom);
    void printInputStudentNumber();
    void printStudentNotFound();
    void printMarkInput();
    void printTypeInput();
    void printRoomIDInput();
    void printThingNotFound();
    void printRoomNotFound();
    void printAddOK();
    void printAddError();
};

#endif // THINGPRINTER_H

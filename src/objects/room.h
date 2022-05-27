#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "consts.h"

class Room
{
private:
    int id;
    std::string roomType;
    int roomNumber;

public:
    Room(int id, std::string roomType, int roomNumber);
    Room();
    ~Room();
    int getID();
    std::string getRoomType();
    int getRoomNumber();
};

class RoomDTO
{
private:
    std::string roomType;
    int roomNumber;
public:
    RoomDTO(std::string roomType, int roomNumber);
    ~RoomDTO() = default;

    std::string getRoomType();
    int getRoomNumber();
};

#endif // ROOM_H

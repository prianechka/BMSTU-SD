#ifndef SQL_H
#define SQL_H
#include "../objects/room.h"
#include "../objects/student.h"
#include "../objects/thing.h"
#include "../objects/user.h"

class PostgreSQLChangeStudent
{
public:
    PostgreSQLChangeStudent() = default;
    ~PostgreSQLChangeStudent() = default;
    std::string get_text(int studentID, StudentDTO studentInfo);
};

class PostgreSQLGetStudent
{
public:
    PostgreSQLGetStudent() = default;
    ~PostgreSQLGetStudent() = default;
    std::string get_text(int id);
};

class PostgreSQLGetStudentID
{
public:
    PostgreSQLGetStudentID() = default;
    ~PostgreSQLGetStudentID() = default;
    std::string get_text(std::string studentNumber);
};

class PostgreSQLGetStudentsThings
{
public:
    PostgreSQLGetStudentsThings() = default;
    ~PostgreSQLGetStudentsThings() = default;
    std::string get_text(int id);
};

class PostgreSQLGetAllStudents
{
public:
    PostgreSQLGetAllStudents() = default;
    ~PostgreSQLGetAllStudents() = default;
    std::string get_text();
};

class PostgreSQLAddStudent
{
public:
    PostgreSQLAddStudent() = default;
    ~PostgreSQLAddStudent() = default;
    std::string get_text(StudentDTO newStudenttudent, int webID);
};

class PostgreSQLTransferStudent
{
public:
    PostgreSQLTransferStudent() = default;
    ~PostgreSQLTransferStudent() = default;
    std::string get_text(int studentID, int roomID, transferDirection direct);
};

class PostgreSQLTransferThing
{
public:
    PostgreSQLTransferThing() = default;
    ~PostgreSQLTransferThing() = default;
    std::string get_text(int studentID, int thingID, transferDirection direct);
};



class PostgreSQLAddRoom
{
public:
    PostgreSQLAddRoom() = default;
    ~PostgreSQLAddRoom() = default;
    std::string get_text(RoomDTO room);
};

class PostgreSQLGetRooms
{
public:
    PostgreSQLGetRooms() = default;
    ~PostgreSQLGetRooms() = default;
    std::string get_text();
};

class PostgreSQLGetRoom
{
public:
    PostgreSQLGetRoom() = default;
    ~PostgreSQLGetRoom() = default;
    std::string get_text(int id);
};

class PostgreSQLGetRoomThings
{
public:
    PostgreSQLGetRoomThings() = default;
    ~PostgreSQLGetRoomThings() = default;
    std::string get_text(int id);
};


class PostgreSQLDeleteRoom
{
public:
    PostgreSQLDeleteRoom() = default;
    ~PostgreSQLDeleteRoom() = default;
    std::string get_text(int id);
};

class PostgreSQLTransferThingRoom
{
public:
    PostgreSQLTransferThingRoom() = default;
    ~PostgreSQLTransferThingRoom() = default;
    std::string get_text(int id, int srcRoomID, int dstRoomID);
};

class PostgreSQLAddThing
{
public:
    PostgreSQLAddThing() = default;
    ~PostgreSQLAddThing() = default;
    std::string get_text(ThingDTO thing);
};

class PostgreSQLGetThings
{
public:
    PostgreSQLGetThings() = default;
    ~PostgreSQLGetThings() = default;
    std::string get_text();
};

class PostgreSQLGetThing
{
public:
    PostgreSQLGetThing() = default;
    ~PostgreSQLGetThing() = default;
    std::string get_text(int id);
};

class PostgreSQLGetThingID
{
public:
    PostgreSQLGetThingID() = default;
    ~PostgreSQLGetThingID() = default;
    std::string get_text(int id);
};

class PostgreSQLDeleteThing
{
public:
    PostgreSQLDeleteThing() = default;
    ~PostgreSQLDeleteThing() = default;
    std::string get_text(int id);
};

class PostgreSQLGetUserId
{
public:
    PostgreSQLGetUserId() = default;
    ~PostgreSQLGetUserId() = default;
    std::string get_text(std::string login);
};

class PostgreSQLGetUser
{
public:
    PostgreSQLGetUser() = default;
    ~PostgreSQLGetUser() = default;
    std::string get_text(int id);
};

class PostgreSQLAddUser
{
public:
    PostgreSQLAddUser() = default;
    ~PostgreSQLAddUser() = default;
    std::string get_text(std::string login, std::string password, Levels privelageLevel);
};


#endif // SQL_H

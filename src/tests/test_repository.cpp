#include <gtest/gtest.h>

#include "../objects/room.h"
#include "../objects/student.h"
#include "../objects/thing.h"
#include "../objects/user.h"

#include "../db/roomRepo.h"
#include "../db/thingRepo.h"
#include "../db/studentRepo.h"
#include "../db/userRepo.h"

#include "../db/pgRoomRepo.h"
#include "../db/pgThingRepo.h"
#include "../db/pgStudentRepo.h"
#include "../db/pgUserRepo.h"

#include "../logic/roomController.h"
#include "../logic/thingController.h"
#include "../logic/studentController.h"
#include "../logic/userController.h"


TEST(TestPgUserRepo, TestGetInfo)
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);
    PgUserRepo rep = PgUserRepo(connectParams);
    UserController controller(rep);

    User tmpUser = controller.getUser(controller.getUserId("prianechka"));
    ASSERT_EQ(tmpUser.getId(), 1);
    ASSERT_EQ(tmpUser.getUserLevel(), STUDENT);
}

TEST(TestPgUserRepo, TestAdd)
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);
    PgUserRepo rep = PgUserRepo(connectParams);
    UserController controller(rep);

    controller.addUser("sysch", "1234", COMEND);
    User tmpUser = controller.getUser(controller.getUserId("sysch"));
    ASSERT_EQ(tmpUser.getUserLevel(), COMEND);
    ASSERT_EQ(tmpUser.getLogin(), "sysch");
}

TEST(TestPgStudentRepo, TestGetInfo)
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);
    PgStudentRepo rep = PgStudentRepo(connectParams);
    StudentController controller(rep);

    int tmpID = controller.getStudentIDByNumber("19У609");
    Student tmpStudent = controller.getStudent(tmpID);
    ASSERT_EQ(tmpStudent.getName(), "Саша");
    ASSERT_EQ(tmpStudent.getSurname(), "Прянишников");
    ASSERT_EQ(tmpStudent.getRoomID(), 2);
    ASSERT_EQ(tmpStudent.getStudentGroup(), "ИУ7-75Б");
}

TEST(TestPgStudentRepo, TestChangeinfo)
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);
    PgStudentRepo rep = PgStudentRepo(connectParams);
    StudentController controller(rep);

    int tmpID = controller.getStudentIDByNumber("19У609");
    controller.changeStudentGroup(tmpID, "ИУ7-75Б");
    controller.changeStudentName(tmpID, "Саша");

    Student tmpStudent = controller.getStudent(tmpID);
    ASSERT_EQ(tmpStudent.getName(), "Саша");
    ASSERT_EQ(tmpStudent.getSurname(), "Прянишников");
    ASSERT_EQ(tmpStudent.getRoomID(), 2);
    ASSERT_EQ(tmpStudent.getStudentGroup(), "ИУ7-75Б");
}

TEST(TestPgStudentRepo, TestEvic)
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);
    PgStudentRepo rep = PgStudentRepo(connectParams);
    StudentController controller(rep);

    int tmpID = controller.getStudentIDByNumber("18У719");
    controller.evicStudent(tmpID);
    controller.settleStudent(tmpID, 3);

    Student tmpStudent = controller.getStudent(tmpID);
    ASSERT_EQ(tmpStudent.getName(), "Артём");
    ASSERT_EQ(tmpStudent.getSurname(), "Богаченко");
    ASSERT_EQ(tmpStudent.getRoomID(), 3);
    ASSERT_EQ(tmpStudent.getStudentGroup(), "ИУ7-65Б");
}

TEST(TestPgRoomRepo, TestGetInfo)
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);
    PgRoomRepo rep = PgRoomRepo(connectParams);
    RoomController controller(rep);

    Room tmpRoom = controller.getRoom(2);
    ASSERT_EQ(tmpRoom.getRoomNumber(), 628);
    ASSERT_EQ(tmpRoom.getRoomType(), "Комната");

    tmpRoom = controller.getRoom(8);
    ASSERT_EQ(tmpRoom.getRoomNumber(), 2);
    ASSERT_EQ(tmpRoom.getRoomType(), "Склад");
}

TEST(TestPgRoomRepo, TestRoomThings)
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);
    PgRoomRepo rep = PgRoomRepo(connectParams);
    RoomController controller(rep);

    std::vector<Thing> things = controller.getRoomThings(2);
    ASSERT_EQ(things.size(), 2);
    ASSERT_EQ(things[0].getRoomID(), 2);
    ASSERT_EQ(things[0].getThingType(), "Стол");
}

TEST(TestPgThingRepo, TestGetInfo)
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);
    PgThingRepo rep = PgThingRepo(connectParams);
    ThingController controller(rep);

    Thing tmpThing = controller.getThing(2);
    ASSERT_EQ(tmpThing.getMarkNumber(), 2);
    ASSERT_EQ(tmpThing.getThingType(), "Стол");
    ASSERT_EQ(tmpThing.getRoomID(), 2);
    ASSERT_EQ(tmpThing.getOwnerID(), 1);
    ASSERT_EQ(controller.getCurrentOwner(2), 1);
    ASSERT_EQ(controller.getThingRoom(2), 2);
}

TEST(TestPgThingRepo, TestFreeInfo)
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);
    PgThingRepo rep = PgThingRepo(connectParams);
    ThingController controller(rep);

    std::vector<Thing> tmpThings = controller.getFreeThings();
    ASSERT_EQ(tmpThings.size(), 1);
    ASSERT_EQ(tmpThings[0].getOwnerID(), -1);
}

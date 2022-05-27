#include <gtest/gtest.h>

#include "../objects/room.h"
#include "../objects/student.h"
#include "../objects/thing.h"
#include "../objects/user.h"

#include "../db/roomRepo.h"
#include "../db/thingRepo.h"
#include "../db/studentRepo.h"
#include "../db/userRepo.h"

#include "../logic/roomController.h"
#include "../logic/thingController.h"
#include "../logic/studentController.h"
#include "../logic/userController.h"

class TestRoomRepo : public InterfaceRoomRepo
{
private:
    std::vector<Room> rooms;
public:
    TestRoomRepo(std::vector<Room> rooms);
    ~TestRoomRepo();
    void addRoom(RoomDTO room) override;
    std::vector<Room> getRooms() override;
    Room getRoom(int id) override;
    void deleteRoom(int id) override;
};

TestRoomRepo::TestRoomRepo(std::vector<Room> rooms)
{
    this->rooms = rooms;
}

void TestRoomRepo::addRoom(RoomDTO room)
{
    int N = this->rooms.size();
    this->rooms.push_back(Room(N + 1, room.getRoomType(), room.getRoomNumber()));
}

std::vector<Room> TestRoomRepo::getRooms()
{
    return this->rooms;
}

Room TestRoomRepo::getRoom(int id)
{
    for (Room tmpRoom : this->rooms)
    {
        if (tmpRoom.getID() == id)
            return tmpRoom;
    }
    return Room();
}

void TestRoomRepo::deleteRoom(int id)
{
    std::vector<Room> newRoomsArray;
    for (Room tmpRoom : this->rooms)
    {
        if (tmpRoom.getID() != id)
            newRoomsArray.push_back(tmpRoom);
    }
    this->rooms = newRoomsArray;
}

TestRoomRepo::~TestRoomRepo()
{}

TEST(TestRoomController, TestAddGetInfo)
{
    std::vector<Room> rooms;
    rooms.push_back(Room(1, "StudentRoom", 628));
    rooms.push_back(Room(2, "StudentRoom", 428));
    rooms.push_back(Room(3, "Storage", 1));
    TestRoomRepo testRepo(rooms);
    RoomController controller(testRepo);

    controller.addRoom("StudentRoom", 532);
    Room room = controller.getRoom(4);
    EXPECT_EQ(room.getID(), 4);
    EXPECT_EQ(room.getRoomNumber(), 532);
    EXPECT_EQ("StudentRoom", room.getRoomType());
}

TEST(TestRoomController, TestDelete)
{
    std::vector<Room> rooms;
    rooms.push_back(Room(1, "StudentRoom", 628));
    rooms.push_back(Room(2, "StudentRoom", 428));
    rooms.push_back(Room(3, "Storage", 1));
    TestRoomRepo testRepo(rooms);
    RoomController controller(testRepo);

    controller.deleteRoom(2);
    Room room = controller.getRoom(2);
    ASSERT_EQ(room.getID(), -1);
}

class TestThingRepo : public InterfaceThingRepo
{
private:
    std::vector<Thing> things;

public:
    TestThingRepo(std::vector<Thing>);
    ~TestThingRepo();
    void addThing(ThingDTO thing) override;
    std::vector<Thing> getThings() override;
    void deleteThing(int id) override;
    Thing getThing(int id) override;
    void transferThing(int id, int srcRoomID, int dstRoomID) override;
};

void TestThingRepo::addThing(ThingDTO thing)
{
    int N = this->things.size();
    this->things.push_back(Thing(N + 1, thing.getMarkNumber(), std::time(nullptr),
                                 thing.getThingType(), NONE, NONE));
}

std::vector<Thing> TestThingRepo::getThings()
{
    return this->things;
}

void TestThingRepo::deleteThing(int id)
{
    std::vector<Thing> newThingsArray;
    for (Thing tmpThing : this->things)
    {
        if (tmpThing.getID() != id)
            newThingsArray.push_back(tmpThing);
    }
    this->things = newThingsArray;
}

Thing TestThingRepo::getThing(int id)
{
    for (Thing tmpThing : this->things)
    {
        if (tmpThing.getID() == id)
            return tmpThing;
    }
    return Thing();
}

void TestThingRepo::transferThing(int id, int srcRoomID, int dstRoomID)
{
    std::vector<Thing> newThingsArray;
    for (Thing tmpThing : this->things)
    {
        if (tmpThing.getID() == id and tmpThing.getRoomID() == srcRoomID)
            tmpThing.setRoomID(dstRoomID);
        newThingsArray.push_back(tmpThing);
    }
    this->things = newThingsArray;
}

TestThingRepo::TestThingRepo(std::vector<Thing> things)
{
    this->things = things;
}

TestThingRepo::~TestThingRepo()
{}

TEST(TestThingController, TestFreeThingsInfo)
{
    std::vector<Thing> things;
    things.push_back(Thing(1, 228, std::time(nullptr), "Stand", 1, 2));
    things.push_back(Thing(2, 227, std::time(nullptr), "Chair", -1, -1));
    things.push_back(Thing(3, 226, std::time(nullptr), "Table", 1, 2));
    TestThingRepo testRepo(things);
    ThingController controller(testRepo);

    std::vector<Thing> freeThings = controller.getFreeThings();
    ASSERT_EQ(freeThings[0].getID(), 2);
    ASSERT_EQ(freeThings[0].getMarkNumber(), 227);
    ASSERT_EQ(freeThings[0].getOwnerID(), -1);
}

TEST(TestThingController, TestAddInfo)
{
    std::vector<Thing> things;
    things.push_back(Thing(1, 228, std::time(nullptr), "Stand", 1, 2));
    things.push_back(Thing(2, 227, std::time(nullptr), "Chair", -1, -1));
    things.push_back(Thing(3, 226, std::time(nullptr), "Table", 1, 2));
    TestThingRepo testRepo(things);
    ThingController controller(testRepo);

    controller.addThing(229, "Bed");
    Thing tmpThing = controller.getThing(4);
    ASSERT_EQ(tmpThing.getID(), 4);
    ASSERT_EQ(tmpThing.getMarkNumber(), 229);
    ASSERT_EQ(tmpThing.getOwnerID(), -1);
}

TEST(TestThingController, TestSmallFuncInfo)
{
    std::vector<Thing> things;
    things.push_back(Thing(1, 228, std::time(nullptr), "Stand", 1, 2));
    things.push_back(Thing(2, 227, std::time(nullptr), "Chair", -1, -1));
    things.push_back(Thing(3, 226, std::time(nullptr), "Table", 1, 2));
    TestThingRepo testRepo(things);
    ThingController controller(testRepo);

    ASSERT_EQ(controller.getCurrentOwner(3), 1);
    ASSERT_EQ(controller.getThingRoom(1), 2);
}

TEST(TestThingController, TestDelete)
{
    std::vector<Thing> things;
    things.push_back(Thing(1, 228, std::time(nullptr), "Stand", 1, 2));
    things.push_back(Thing(2, 227, std::time(nullptr), "Chair", -1, -1));
    things.push_back(Thing(3, 226, std::time(nullptr), "Table", 1, 2));
    TestThingRepo testRepo(things);
    ThingController controller(testRepo);

    controller.deleteThing(2);
    Thing tmpThing = controller.getThing(4);
    ASSERT_EQ(tmpThing.getID(), -1);
    ASSERT_EQ(tmpThing.getMarkNumber(), -1);
    ASSERT_EQ(tmpThing.getOwnerID(), -1);
}

TEST(TestThingController, TestTransfer)
{
    std::vector<Thing> things;
    things.push_back(Thing(1, 228, std::time(nullptr), "Stand", 1, 2));
    things.push_back(Thing(2, 227, std::time(nullptr), "Chair", -1, -1));
    things.push_back(Thing(3, 226, std::time(nullptr), "Table", 1, 2));
    TestThingRepo testRepo(things);
    ThingController controller(testRepo);

    ASSERT_EQ(controller.getThingRoom(3), 2);
    controller.transferThing(3, 2, 4);
    ASSERT_EQ(controller.getThingRoom(3), 4);
}

class TestStudentRepo : public InterfaceStudentRepo
{
private:
    std::vector<Student> students;

public:
    TestStudentRepo(std::vector<Student> students);
    ~TestStudentRepo();

    void addStudent(StudentDTO student) override;
    std::vector<Student> getAllStudents() override;
    Student getStudent(int id) override;
    void settleStudent(int studentID, int roomID) override;
    void evicStudent(int studentID) override;
    void changeStudentGroup(int studentID, std::string newGroup) override;
    void changeStudentName(int studentID, std::string newName) override;
    void changeStudentSurname(int studentID, std::string newSurname) override;
};

TestStudentRepo::~TestStudentRepo()
{}

TestStudentRepo::TestStudentRepo(std::vector<Student> students)
{
    this->students = students;
}

void TestStudentRepo::addStudent(StudentDTO student)
{
    int N = this->students.size();
    this->students.push_back(Student(N + 1, N + 1, student.getName(), student.getSurname(), std::time(nullptr),
                                     student.getStudentGroup(), student.getStudentNumber(), NONE));
}

std::vector<Student> TestStudentRepo::getAllStudents()
{
    return this->students;
}

Student TestStudentRepo::getStudent(int id)
{
    for (Student tmpStudent : this->students)
    {
        if (tmpStudent.getID() == id)
            return tmpStudent;
    }
    return Student();
}

void TestStudentRepo::settleStudent(int studentID, int roomID)
{
    std::vector<Student> newArrayStudents;
    for (Student tmpStudent : this->students)
    {
        if (tmpStudent.getID() == studentID)
            tmpStudent.setRoomID(roomID);
        newArrayStudents.push_back(tmpStudent);
    }
    this->students = newArrayStudents;
}

void TestStudentRepo::evicStudent(int studentID)
{
    std::vector<Student> newArrayStudents;
    for (Student tmpStudent : this->students)
    {
        if (tmpStudent.getID() == studentID)
            tmpStudent.setRoomID(-1);
        newArrayStudents.push_back(tmpStudent);
    }
    this->students = newArrayStudents;
}

void TestStudentRepo::changeStudentGroup(int studentID, std::string newGroup)
{
    std::vector<Student> newArrayStudents;
    for (Student tmpStudent : this->students)
    {
        if (tmpStudent.getID() == studentID)
            tmpStudent.setGroup(newGroup);
        newArrayStudents.push_back(tmpStudent);
    }
    this->students = newArrayStudents;
}

void TestStudentRepo::changeStudentName(int studentID, std::string newName)
{
    std::vector<Student> newArrayStudents;
    for (Student tmpStudent : this->students)
    {
        if (tmpStudent.getID() == studentID)
            tmpStudent.setName(newName);
        newArrayStudents.push_back(tmpStudent);
    }
    this->students = newArrayStudents;
}

void TestStudentRepo::changeStudentSurname(int studentID, std::string newSurname)
{
    std::vector<Student> newArrayStudents;
    for (Student tmpStudent : this->students)
    {
        if (tmpStudent.getID() == studentID)
            tmpStudent.setSurname(newSurname);
        newArrayStudents.push_back(tmpStudent);
    }
    this->students = newArrayStudents;
}

TEST(TestStudentController, TestAdd)
{
    std::vector<Student> students;
    students.push_back(Student(1, 1, "Alex", "Priany", std::time(nullptr), "IU7-65", "19U609", 628));
    students.push_back(Student(2, 2, "Nik", "Low", std::time(nullptr), "IU7-66", "19U619", 518));
    students.push_back(Student(3, 3, "Art", "Bogch", std::time(nullptr), "IU7-65", "18U629", 628));

    TestStudentRepo testRepo(students);
    StudentController controller(testRepo);

    controller.addStudent("Sofa", "Shelia", "IU7-65", "19U622");
    Student tmpStudent = controller.getStudent(4);

    ASSERT_EQ(tmpStudent.getID(), 4);
    EXPECT_EQ(tmpStudent.getName(), "Sofa");
    EXPECT_EQ(tmpStudent.getSurname(), "Shelia");
    EXPECT_EQ(tmpStudent.getStudentGroup(), "IU7-65");
    EXPECT_EQ(tmpStudent.getStudentNumber(), "19U622");

    tmpStudent = controller.getStudent(2);
    ASSERT_EQ(tmpStudent.getID(), 2);
    EXPECT_EQ(tmpStudent.getName(), "Nik");
    EXPECT_EQ(tmpStudent.getSurname(), "Low");
    EXPECT_EQ(tmpStudent.getStudentGroup(), "IU7-66");
    EXPECT_EQ(tmpStudent.getStudentNumber(), "19U619");
}

TEST(TestStudentController, TestEvic)
{
    std::vector<Student> students;
    students.push_back(Student(1, 1, "Alex", "Priany", std::time(nullptr), "IU7-65", "19U609", 628));
    students.push_back(Student(2, 2, "Nik", "Low", std::time(nullptr), "IU7-66", "19U619", 518));
    students.push_back(Student(3, 3, "Art", "Bogch", std::time(nullptr), "IU7-65", "18U629", 628));

    TestStudentRepo testRepo(students);
    StudentController controller(testRepo);

    controller.evicStudent(2);
    Student tmpStudent = controller.getStudent(2);

    ASSERT_EQ(tmpStudent.getID(), 2);
    ASSERT_EQ(tmpStudent.getRoomID(), NONE);
}

TEST(TestStudentController, TestSettle)
{
    std::vector<Student> students;
    students.push_back(Student(1, 1, "Alex", "Priany", std::time(nullptr), "IU7-65", "19U609", 628));
    students.push_back(Student(2, 2, "Nik", "Low", std::time(nullptr), "IU7-66", "19U619", 518));
    students.push_back(Student(3, 3, "Art", "Bogch", std::time(nullptr), "IU7-65", "18U629", 628));

    TestStudentRepo testRepo(students);
    StudentController controller(testRepo);

    controller.evicStudent(2);
    controller.settleStudent(2, 412);
    Student tmpStudent = controller.getStudent(2);

    ASSERT_EQ(tmpStudent.getID(), 2);
    ASSERT_EQ(tmpStudent.getRoomID(), 412);
}

TEST(TestStudentController, TestSmallFunc)
{
    std::vector<Student> students;
    students.push_back(Student(1, 1, "Alex", "Priany", std::time(nullptr), "IU7-65", "19U609", 628));
    students.push_back(Student(2, 2, "Nik", "Low", std::time(nullptr), "IU7-66", "19U619", 518));
    students.push_back(Student(3, 3, "Art", "Bogch", std::time(nullptr), "IU7-65", "18U629", 628));

    TestStudentRepo testRepo(students);
    StudentController controller(testRepo);

    controller.addStudent("Shelia", "Sofa", "IU7-65", "19U622");
    Student tmpStudent = controller.getStudent(4);

    ASSERT_EQ(tmpStudent.getID(), 4);
    ASSERT_EQ(controller.getStudentIDByNumber("19U609"), 1);
    ASSERT_EQ(controller.getStudentRoom(3), 628);
}

TEST(TestStudentController, TestChange)
{
    std::vector<Student> students;
    students.push_back(Student(1, 1, "Alex", "Priany", std::time(nullptr), "IU7-65", "19U609", 628));
    students.push_back(Student(2, 2, "Nik", "Low", std::time(nullptr), "IU7-66", "19U619", 518));
    students.push_back(Student(3, 3, "Art", "Bogch", std::time(nullptr), "IU7-65", "18U629", 628));

    TestStudentRepo testRepo(students);
    StudentController controller(testRepo);

    controller.changeStudentGroup(2, "IU7-76");
    controller.changeStudentName(2, "Nikola");
    controller.changeStudentSurname(2, "Vuich");

    EXPECT_EQ(controller.getStudent(2).getName(), "Nikola");
    EXPECT_EQ(controller.getStudent(2).getSurname(), "Vuich");
    EXPECT_EQ(controller.getStudent(2).getStudentGroup(), "IU7-76");
}

class TestUserRepo : public InterfaceUserRepo
{
private:
    std::vector<User> users;
public:
    TestUserRepo(std::vector<User> users);
    ~TestUserRepo() = default;
    int getUserId(std::string login) override;
    User getUser(int id) override;
    void addUser(std::string login, std::string password, Levels privelegeLevel) override;
};

TestUserRepo::TestUserRepo(std::vector<User> users)
{
    this->users = users;
}

int TestUserRepo::getUserId(std::string login)
{
    int result = NONE;
    for (User tmpUser : this->users)
    {
        if (tmpUser.getLogin() == login)
        {
            result = tmpUser.getId();
            break;
        }
    }
    return result;
}

User TestUserRepo::getUser(int id)
{
    for (User tmpUser : this->users)
    {
        if (tmpUser.getId() == id)
            return tmpUser;
    }
    return User();
}

void TestUserRepo::addUser(std::string login, std::string password, Levels privelegeLevel)
{
    int N = this->users.size();
    this->users.push_back(User(N + 1, login, password, privelegeLevel));
}

TEST(TestUserController, TestAdd)
{
    std::vector<User> users;
    users.push_back(User(1, "priany", "ghzyz", STUDENT));

    TestUserRepo testRepo(users);
    UserController controller(testRepo);

    controller.addUser("sysch", "1234", COMEND);

    User tmpUser = controller.getUser(2);
    ASSERT_EQ(tmpUser.getId(), 2);
    ASSERT_EQ(tmpUser.getLogin(), "sysch");
}

TEST(TestUserController, TestGetInfo)
{
    std::vector<User> users;
    users.push_back(User(1, "priany", "ghzyz", STUDENT));

    TestUserRepo testRepo(users);
    UserController controller(testRepo);

    controller.addUser("sysch", "1234", COMEND);

    User tmpUser = controller.getUser(controller.getUserId("priany"));
    ASSERT_EQ(tmpUser.getId(), 1);
    ASSERT_EQ(tmpUser.getUserLevel(), STUDENT);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

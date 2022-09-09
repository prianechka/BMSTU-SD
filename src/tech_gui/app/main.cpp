#include "app.h"

/*
int main()
{
    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);

    PgUserRepo userRepo = PgUserRepo(connectParams);
    UserController userController(userRepo);

    PgStudentRepo studentRepo = PgStudentRepo(connectParams);
    StudentController studentController(studentRepo);

    PgRoomRepo roomRepo = PgRoomRepo(connectParams);
    RoomController roomController(roomRepo);

    PgThingRepo thingRepo = PgThingRepo(connectParams);
    ThingController thingController(thingRepo);

    AuthManager authManager(userController);
    StudentManager studentManager(studentController, userController,
                                  roomController, thingController);
    RoomManager roomManager(roomController);
    ThingManager thingManager(thingController, studentController, roomController);

    App app(authManager, studentManager, thingManager, roomManager);

    for (;;)
        app.menu();
}
*/

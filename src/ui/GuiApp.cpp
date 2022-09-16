#include "ui/authwindow.h"
#include "ui/commwindow.h"
#include "ui/suppwindow.h"
#include "ui/studentwindow.h"
#include "../db/pgRoomRepo.h"
#include <QApplication>

/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConnectionParams connectParams = ConnectionParams("bob", "localhost", "ppo", "admin", 5432);

    PgUserRepo userRepo = PgUserRepo(connectParams);
    UserController userController(userRepo);

    PgStudentRepo studentRepo = PgStudentRepo(connectParams);
    StudentController studentController(studentRepo);

    PgRoomRepo roomRepo = PgRoomRepo(connectParams);
    RoomController roomController(roomRepo);

    PgThingRepo thingRepo = PgThingRepo(connectParams);
    ThingController thingController(thingRepo);

    GUIStudentManager studentManager(studentController, userController,
                                  roomController, thingController);

    GUIThingManager thingManager(thingController, studentController, roomController);
    GUIRoomManager roomManager(roomController);
    GUIAuthManager manager(userController);

    AuthWindow w(manager, studentManager, thingManager, roomManager);
    w.show();
    return a.exec();
}
*/

#include "GuiApp.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConfigManager configManager;
    std::string DB = configManager.getDB();
    ConnectionParams connectParams;
    if (DB == "postgres")
    {
        connectParams = configManager.getParams();
        PgUserRepo userRepo = PgUserRepo(connectParams);
        PgStudentRepo studentRepo = PgStudentRepo(connectParams);
        PgRoomRepo roomRepo = PgRoomRepo(connectParams);
        PgThingRepo thingRepo = PgThingRepo(connectParams);

        StudentController studentController(studentRepo);
        RoomController roomController(roomRepo);
        ThingController thingController(thingRepo);
        UserController userController(userRepo);
        GUIStudentManager studentManager(studentController, userController,
                                          roomController, thingController);
        GUIThingManager thingManager(thingController, studentController, roomController);
        GUIRoomManager roomManager(roomController);
        GUIAuthManager manager(userController);

        AuthWindow w(manager, studentManager, thingManager, roomManager);
        w.show();
        return a.exec();
    }
}

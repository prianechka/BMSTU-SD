#ifndef APP_H
#define APP_H

#include "printer.h"
#include "request.h"
#include "states.h"

#include "../../objects/user.h"
#include "../auth_manager/authManager.h"
#include "../student_manager/studentManager.h"
#include "../room_manager/roomManager.h"
#include "../thing_manager/thingManager.h"

#include "../../logic/userController.h"
#include "../../logic/studentController.h"
#include "../../logic/thingController.h"
#include "../../logic/roomController.h"

#include "../../db/pgUserRepo.h"
#include "../../db/pgThingRepo.h"
#include "../../db/pgStudentRepo.h"
#include "../../db/pgRoomRepo.h"


class App {
public:
    App(AuthManager &authManager, StudentManager &studentManager,
        ThingManager &thingManager, RoomManager &roomManager);
    ~App() = default;
    void menu();

private:
    AppPrinter printer;
    AppState state;
    RequestHandler req_handler;
    REQUEST_KEYS getRequestKey(std::string req);
    AuthManager authManager;
    StudentManager studentManager;
    ThingManager thingManager;
    RoomManager roomManager;

    int id;
    std::string studNumber;
    void handleReq(REQUEST_KEYS key);
};

#endif // APP_H

#include "app.h"

App::App(AuthManager &authManager, StudentManager &studentManager,
         ThingManager &thingManager, RoomManager &roomManager)
{
    this->printer = AppPrinter();
    this->req_handler = RequestHandler();
    this->state = AppState();
    this->id = NONE;
    this->studNumber = "";
    this->studentManager = studentManager;
    this->authManager = authManager;
    this->thingManager = thingManager;
    this->roomManager = roomManager;
}

void App::menu()
{
    this->printer.print_menu();
    std::string req;
    std::cin >> req;
    REQUEST_KEYS key = this->getRequestKey(req);
    this->handleReq(key);
}

REQUEST_KEYS App::getRequestKey(std::string req)
{
    return this->req_handler.handle(req);
}

void App::handleReq(REQUEST_KEYS key)
{
    switch (key)
    {
    case EXIT:
        std::exit(EXIT);

    case UN_AUTH:
        if (!this->state.isUnAuth()) {
            this->state.toUnAuth();
        } else {
            this->printer.print_not_role();
        }
        break;

    case AUTH:
        if (this->state.isUnAuth())
        {
            Levels role = this->authManager.TryToAuthorize();
            switch (role) {
            case STUDENT:
                this->state.toStudentAuth();
                break;
            case SUPPLY:
                this->state.toSupplyAuth();
                break;
            case COMEND:
                this->state.toCommendAuth();
                break;
            default:
                break;
            }
        };
        break;

    case VIEW_ALL_STUDENTS:
        if (!this->state.isUnAuth())
            this->studentManager.viewAllStudent();
        else
            this->printer.print_not_role();
        break;

    case VIEW_STUDENT:
        if (!this->state.isUnAuth())
            this->studentManager.viewStudent();
        else
            this->printer.print_not_role();
        break;

    case ADD_STUDENT:
        if (this->state.isCommendAuth())
        {
            this->studentManager.addNewStudent();
        } else {
            this->printer.print_not_role();
        }
        break;

    case CHANGE_STUDENT:
        if (this->state.isCommendAuth())
        {
            this->studentManager.changeStudentInfo();
        } else {
            this->printer.print_not_role();
        };
        break;

    case SETTLE_STUDENT:
        if (this->state.isCommendAuth())
        {
            this->studentManager.settleStudent();
        } else {
            this->printer.print_not_role();
        }
        break;

    case EVIC_STUDENT:
        if (this->state.isCommendAuth())
        {
            this->studentManager.evicStudent();
        } else {
            this->printer.print_not_role();
        };
        break;

    case VIEW_THINGS:
        if (!this->state.isUnAuth())
        {
            this->thingManager.viewAllThings();
        } else {
            this->printer.print_not_role();
        }
        break;

    case VIEW_FREE_THINGS:
        if (this->state.isSupplyAuth())
        {
            this->thingManager.viewFreeThings();
        } else {
            this->printer.print_not_role();
        }
        break;

    case ADD_THING:
        if (this->state.isSupplyAuth())
        {
            this->thingManager.addNewThing();
        } else {
            this->printer.print_not_role();
        }
        break;

    case GIVE_THING:
        if (this->state.isSupplyAuth())
        {
            this->studentManager.giveStudentThing();
        } else {
            this->printer.print_not_role();
        }
        break;

    case RETURN_THING:
        if (this->state.isSupplyAuth())
        {
            this->studentManager.returnStudentThing();
        } else {
            this->printer.print_not_role();
        }
        break;

    case CHANGE_THING_LOC:
        if (!this->state.isUnAuth())
        {
            this->thingManager.transferThing();
        } else {
            this->printer.print_not_role();
        }
        break;

    case VIEW_STUDENT_THINGS:
        if (this->state.isSupplyAuth() || this->state.isCommendAuth())
        {
            this->thingManager.viewStudentThings();
        } else {
            this->printer.print_not_role();
        }
        break;

    case VIEW_ROOMS:
        if (this->state.isSupplyAuth() || this->state.isCommendAuth())
        {
            this->roomManager.printAllRooms();
        } else {
            this->printer.print_not_role();
        }
        break;

    case NOT_A_COMMAND:
        this->printer.print_not_a_command();
    }
}

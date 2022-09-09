#include "studentManager.h"

StudentManager::StudentManager(StudentController &studController,
                               UserController &userController,
                               RoomController &roomController,
                               ThingController &thingController)
{
    this->getter = StudentGetter();
    this->printer = StudentPrinter();
    this->studentController = studController;
    this->userController = userController;
    this->roomController = roomController;
    this->thingController = thingController;
}

StudentManager::StudentManager() {}

void StudentManager::addNewStudent()
{
    this->printer.printInputName();
    std::string name = this->getter.getString();

    this->printer.printInputSurname();
    std::string surname = this->getter.getString();

    this->printer.printInputGroup();
    std::string group = this->getter.getString();

    this->printer.printInputStudentNumber();
    std::string studNumber = this->getter.getString();

    this->printer.printInputLogin();
    std::string login = this->getter.getString();

    this->printer.printInputPassword();
    std::string password = this->getter.getString();

    this->userController.addUser(login, password, STUDENT);
    int id = this->userController.getUserId(login);
    if (id != NONE)
        this->studentController.addStudent(name, surname, group, studNumber, id);
}

void StudentManager::viewStudent()
{
    this->printer.printInputStudentNumber();
    std::string studentNumber = this->getter.getString();

    int tmpID = this->studentController.getStudentIDByNumber(studentNumber);
    if (tmpID != NONE)
    {
        Student tmpStudent = this->studentController.getStudent(tmpID);
        Room studentRoom = this->roomController.getRoom(tmpStudent.getRoomID());
        this->printer.printStudent(tmpStudent);
        this->printer.printStudentRoom(studentRoom.getRoomNumber());
    }
    else
        this->printer.printStudentNotFound();
}

void StudentManager::viewAllStudent()
{
    std::vector<Student> allStudents = this->studentController.getAllStudents();
    this->printer.printAllStudents(allStudents);
}

void StudentManager::changeStudentInfo()
{
    this->printer.printInputStudentNumber();
    std::string studentNumber = this->getter.getString();

    int tmpID = this->studentController.getStudentIDByNumber(studentNumber);
    if (tmpID != NONE)
    {
        this->printer.printInputGroup();
        std::string group = this->getter.getString();
        this->studentController.changeStudentGroup(tmpID, group);
    }
    else
        this->printer.printStudentNotFound();
}

void StudentManager::settleStudent()
{
    this->printer.printInputStudentNumber();
    std::string studentNumber = this->getter.getString();

    int tmpID = this->studentController.getStudentIDByNumber(studentNumber);
    if (tmpID != NONE)
    {
        Student tmpStudent = this->studentController.getStudent(tmpID);
        if (tmpStudent.getRoomID() == NONE)
        {
            this->printer.printIDRoom();
            int roomID = this->getter.getInt();
            this->studentController.settleStudent(tmpStudent.getID(), roomID);
        }
        else
            this->printer.printSettleError();
    }
    else
        this->printer.printStudentNotFound();
}

void StudentManager::evicStudent()
{
    this->printer.printInputStudentNumber();
    std::string studentNumber = this->getter.getString();

    int tmpID = this->studentController.getStudentIDByNumber(studentNumber);
    if (tmpID != NONE)
    {
        Student tmpStudent = this->studentController.getStudent(tmpID);
        Room studentRoom = this->roomController.getRoom(tmpStudent.getRoomID());
        if (tmpStudent.getRoomID() == NONE)
            this->printer.printEvicError();
        else
            this->studentController.evicStudent(tmpStudent.getID());
    }
    else
        this->printer.printStudentNotFound();
}

void StudentManager::giveStudentThing()
{
    this->printer.printInputStudentNumber();
    std::string studentNumber = this->getter.getString();

    int tmpID = this->studentController.getStudentIDByNumber(studentNumber);
    if (tmpID != NONE)
    {
        this->printer.printMarkNumInput();
        int markNumber = this->getter.getInt();
        int tmpThingID = this->thingController.getThingIDByMarkNumber(markNumber);
        if (tmpThingID != NONE)
        {
            int owner = this->thingController.getCurrentOwner(tmpThingID);
            if (owner == NONE)
            {
                this->studentController.transferThing(tmpID, tmpThingID);
                this->printer.printGiveOK();
            }
            else
                this->printer.printGiveError();
        }
        else
            this->printer.printThingNotFound();
    }
    else
        this->printer.printStudentNotFound();
}

void StudentManager::returnStudentThing()
{
    this->printer.printInputStudentNumber();
    std::string studentNumber = this->getter.getString();

    int tmpID = this->studentController.getStudentIDByNumber(studentNumber);
    if (tmpID != NONE)
    {
        this->printer.printMarkNumInput();
        int markNumber = this->getter.getInt();
        int tmpThingID = this->thingController.getThingIDByMarkNumber(markNumber);
        if (tmpThingID != NONE)
        {
            int owner = this->thingController.getCurrentOwner(tmpThingID);
            if (owner == tmpID)
            {
                this->studentController.returnThing(tmpID, tmpThingID);
                this->printer.printReturnOK();
            }
            else
                this->printer.printReturnError();
        }
        else
            this->printer.printThingNotFound();
    }
    else
        this->printer.printStudentNotFound();
}

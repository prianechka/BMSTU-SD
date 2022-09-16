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

    try
    {
        this->userController.addUser(login, password, STUDENT);
        int webID = this->userController.getUserId(login);
        this->studentController.addStudent(surname, name, group, studNumber, webID);
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}

void StudentManager::viewStudent()
{
    this->printer.printInputStudentNumber();
    std::string studentNumber = this->getter.getString();

    try
    {
        int tmpID = this->studentController.getStudentIDByNumber(studentNumber);
        if (tmpID != NONE)
        {
            Student tmpStudent = this->studentController.getStudent(tmpID);
            this->printer.printStudent(tmpStudent);
            if (tmpStudent.getRoomID() != NOT_LIVING)
            {
                Room studentRoom = this->roomController.getRoom(tmpStudent.getRoomID());
                this->printer.printStudentRoom(studentRoom.getRoomNumber());
            }
            else
                this->printer.printStudentRoom(NOT_LIVING);
        }
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
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

    try
    {
        int tmpID = this->studentController.getStudentIDByNumber(studentNumber);
        if (tmpID != NONE)
        {
            this->printer.printInputGroup();
            std::string group = this->getter.getString();
            this->studentController.changeStudentGroup(tmpID, group);
        }
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}

void StudentManager::settleStudent()
{
    this->printer.printInputStudentNumber();
    std::string studentNumber = this->getter.getString();

    try
    {
        int tmpID = this->studentController.getStudentIDByNumber(studentNumber);
        if (tmpID != NONE)
        {
            Student tmpStudent = this->studentController.getStudent(tmpID);
            if (tmpStudent.getRoomID() == NOT_LIVING)
            {
                this->printer.printIDRoom();
                int roomID = this->getter.getInt();
                this->studentController.settleStudent(tmpStudent.getID(), roomID);
            }
        }
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}

void StudentManager::evicStudent()
{
    this->printer.printInputStudentNumber();
    std::string studentNumber = this->getter.getString();

    try
    {
        int tmpID = this->studentController.getStudentIDByNumber(studentNumber);
        if (tmpID != NONE)
        {
            Student tmpStudent = this->studentController.getStudent(tmpID);
            Room studentRoom = this->roomController.getRoom(tmpStudent.getRoomID());
            if (tmpStudent.getRoomID() != NONE)
            {
                this->studentController.evicStudent(tmpStudent.getID());
                this->printer.printEvicOK();
            }
        }
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}

void StudentManager::giveStudentThing()
{
    this->printer.printInputStudentNumber();
    std::string studentNumber = this->getter.getString();
    try
    {
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
                    owner = this->thingController.getCurrentOwner(tmpThingID);
                    if (owner == tmpID)
                        this->printer.printGiveOK();
                    else
                        throw ThingBadTransferException(__FILE__, typeid(*this).name(), __LINE__);
                }
                else
                    throw ThingBadTransferException(__FILE__, typeid(*this).name(), __LINE__);
            }
        }
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}

void StudentManager::returnStudentThing()
{
    this->printer.printInputStudentNumber();
    std::string studentNumber = this->getter.getString();
    try
    {
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
                    owner = this->thingController.getCurrentOwner(tmpThingID);
                    if (owner == tmpID)
                        throw ThingBadTransferException(__FILE__, typeid(*this).name(), __LINE__);
                    this->printer.printReturnOK();
                }
            }
        }
    }
    catch (const std::exception &e)
    {
        this->printer.printException(e);
    }
}

std::string StudentManager::getStudentByWebID(int webID)
{
    std::string result = "";
    std::vector<Student> students = this->studentController.getAllStudents();
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i].getAccID() == webID)
        {
            result = students[i].getStudentNumber();
            break;
        }
    }
    return result;
}

#include "interfaceStudentRepo.h"

void InterfaceStudentRepo::addStudent(std::string surname, std::string name, std::string group, std::string studentNumber)
{}

void InterfaceStudentRepo::changeStudentGroup(int studentID, std::string newGroup)
{}

void InterfaceStudentRepo::changeStudentName(int studentID, std::string newName)
{}

void InterfaceStudentRepo::changeStudentSurname(int studentID, std::string newSurname)
{}

void InterfaceStudentRepo::evicStudent(int studentID)
{}

void InterfaceStudentRepo::settleStudent(int studentID, int roomID)
{}

std::vector<Student> InterfaceStudentRepo::getAllStudents()
{}

Student InterfaceStudentRepo::getStudentInfo(int id)
{}

std::vector<Thing> InterfaceStudentRepo::getStudentThings(int id)
{}

void InterfaceStudentRepo::transferThing(int studentID, int thingID, transferDirection direct)
{}

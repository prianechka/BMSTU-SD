#include "studentRepo.h"

void InterfaceStudentRepo::addStudent(StudentDTO student)
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

Student InterfaceStudentRepo::getStudent(int id)
{}

std::vector<Thing> InterfaceStudentRepo::getStudentThings(int id)
{}

void InterfaceStudentRepo::transferThing(int studentID, int thingID, transferDirection direct)
{}

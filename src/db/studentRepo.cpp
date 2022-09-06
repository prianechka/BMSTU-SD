#include "studentRepo.h"

void InterfaceStudentRepo::addStudent(StudentDTO student, int webID)
{}

int InterfaceStudentRepo::getStudentID(std::string studentNumber)
{}

void InterfaceStudentRepo::changeStudent(int studentID, StudentDTO studentInfo)
{}


void InterfaceStudentRepo::transferStudent(int studentID, int roomID, transferDirection direct)
{}

std::vector<Student> InterfaceStudentRepo::getAllStudents()
{}

Student InterfaceStudentRepo::getStudent(int id)
{}

std::vector<Thing> InterfaceStudentRepo::getStudentThings(int id)
{}

void InterfaceStudentRepo::transferThing(int studentID, int thingID, transferDirection direct)
{}

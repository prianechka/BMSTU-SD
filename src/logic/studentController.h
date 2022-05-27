#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H

#include "../objects/student.h"
#include "../objects/thing.h"
#include "../db/studentRepo.h"
#include <vector>

class StudentController
{
private:
    InterfaceStudentRepo *repository;

public:
    StudentController(InterfaceStudentRepo &repository);
    ~StudentController();

    void addStudent(std::string surname, std::string name, std::string group, std::string studentNumber);
    std::vector<Student> getAllStudents();
    int getStudentIDByNumber(std::string studentNumber);
    Student getStudent(int id);
    int getStudentRoom(int id);
    void evicStudent(int ID);
    void settleStudent(int studentID, int roomID);
    void changeStudentGroup(int id, std::string newGroup);
    void changeStudentName(int id, std::string newName);
    void changeStudentSurname(int id, std::string newSurname);
    std::vector<Thing> getStudentThings(int id);
    void transferThing(int studentID, int thingID);
    void returnThing(int studentID, int thingID);
};

#endif // STUDENTCONTROLLER_H

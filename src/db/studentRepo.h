#ifndef STUDENTREPO_H
#define STUDENTREPO_H

#include "../objects/student.h"
#include "../objects/thing.h"
#include <vector>

enum transferDirection
{
    RET = 0, GET = 1
};

class InterfaceStudentRepo
{
public:
    virtual void addStudent(StudentDTO newStudenttudent);
    virtual std::vector<Student> getAllStudents();
    virtual Student getStudent(int id);
    virtual void settleStudent(int studentID, int roomID);
    virtual void evicStudent(int studentID);
    virtual void changeStudentGroup(int studentID, std::string newGroup);
    virtual void changeStudentName(int studentID, std::string newName);
    virtual void changeStudentSurname(int studentID, std::string newSurname);
    virtual void transferThing(int studentID, int thingID, transferDirection direct);
    virtual std::vector<Thing> getStudentThings(int id);
};

#endif // STUDENTREPO_H

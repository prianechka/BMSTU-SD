#ifndef STUDENTREPO_H
#define STUDENTREPO_H

#include "../objects/student.h"
#include "../objects/thing.h"
#include <vector>

class InterfaceStudentRepo
{
public:
    virtual void addStudent(StudentDTO newStudent, int webID);
    virtual std::vector<Student> getAllStudents();
    virtual int getStudentID(std::string studentNumber);
    virtual Student getStudent(int id);
    virtual void transferStudent(int studentID, int roomID, transferDirection direct);
    virtual void changeStudent(int studentID, StudentDTO studentInfo);
    virtual void transferThing(int studentID, int thingID, transferDirection direct);
    virtual std::vector<Thing> getStudentThings(int id);
};

#endif // STUDENTREPO_H

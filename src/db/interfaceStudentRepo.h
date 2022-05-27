#ifndef INTERFACESTUDENTREPO_H
#define INTERFACESTUDENTREPO_H

#include "../objects/student.h"
#include "../objects/thing.h"
#include <vector>

enum transferDirection
{
    RET = 0, GET = 1
};

class InterfaceStudentRepo
{
private:
    int connection;
public:
    virtual void addStudent(std::string surname, std::string name,
                            std::string group, std::string studentNumber);
    virtual std::vector<Student> getAllStudents();
    virtual Student getStudentInfo(int id);
    virtual void settleStudent(int studentID, int roomID);
    virtual void evicStudent(int studentID);
    virtual void changeStudentGroup(int studentID, std::string newGroup);
    virtual void changeStudentName(int studentID, std::string newName);
    virtual void changeStudentSurname(int studentID, std::string newSurname);
    virtual void transferThing(int studentID, int thingID, transferDirection direct);
    virtual std::vector<Thing> getStudentThings(int id);
};

#endif // INTERFACESTUDENTREPO_H

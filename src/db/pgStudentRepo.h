#ifndef PGSTUDENTREPO_H
#define PGSTUDENTREPO_H

#include "interfaceStudentRepo.h"

class PgStudentRepo : public InterfaceStudentRepo
{
public:
    void addStudent(std::string surname, std::string name,
                            std::string group, std::string studentNumber) override;
    std::vector<Student> getAllStudents() override;
    Student getStudentInfo(int id) override;
    void settleStudent(int studentID, int roomID) override;
    void evicStudent(int studentID) override;
    void changeStudentGroup(int studentID, std::string newGroup) override;
    void changeStudentName(int studentID, std::string newName) override;
    void changeStudentSurname(int studentID, std::string newSurname) override;
};

#endif // PGSTUDENTREPO_H

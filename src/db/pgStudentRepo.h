#ifndef PGSTUDENTREPO_H
#define PGSTUDENTREPO_H

#include "studentRepo.h"

class PgStudentRepo : public InterfaceStudentRepo
{
private:
    int connection;
public:
    void addStudent(StudentDTO newStudenttudent) override;
    std::vector<Student> getAllStudents() override;
    Student getStudent(int id) override;
    void settleStudent(int studentID, int roomID) override;
    void evicStudent(int studentID) override;
    void changeStudentGroup(int studentID, std::string newGroup) override;
    void changeStudentName(int studentID, std::string newName) override;
    void changeStudentSurname(int studentID, std::string newSurname) override;
};

#endif // PGSTUDENTREPO_H

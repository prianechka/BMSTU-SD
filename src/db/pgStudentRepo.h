#ifndef PGSTUDENTREPO_H
#define PGSTUDENTREPO_H

#include "studentRepo.h"
#include "../objects/connection.h"
#include "sql.h"
#include "exceptions.h"

class PgStudentRepo : public InterfaceStudentRepo
{
private:
    std::string connectString;
    std::shared_ptr<pqxx::connection> connection;

public:
    PgStudentRepo(ConnectionParams params);
    ~PgStudentRepo() = default;
    void addStudent(StudentDTO newStudenttudent, int webID) override;
    std::vector<Student> getAllStudents() override;
    int getStudentID(std::string studentNumber) override;
    Student getStudent(int id) override;
    void transferStudent(int studentID, int roomID, transferDirection direct) override;
    void changeStudent(int studentID, StudentDTO studentInfo) override;
    void transferThing(int studentID, int thingID, transferDirection direct) override;
    std::vector<Thing> getStudentThings(int id) override;
};

#endif // PGSTUDENTREPO_H

#include "pgStudentRepo.h"

PgStudentRepo::PgStudentRepo(ConnectionParams params)
{
    this->connectString = params.getString();
    try
    {
        this->connection = std::shared_ptr<pqxx::connection>(
                              new pqxx::connection(this->connectString.c_str()));
        if (!this->connection->is_open())
        {
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
        }
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}

void PgStudentRepo::addStudent(StudentDTO newStudent, int webID)
{
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLAddStudent().get_text(newStudent, webID);
            pqxx::work curConnect(*this->connection);
            curConnect.exec(sql);
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}

std::vector<Student> PgStudentRepo::getAllStudents()
{
    std::vector<Student> resultStudents = std::vector<Student>();
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetAllStudents().get_text();
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            for (size_t i = 0; i < result.size(); i++)
            {
                Student currentStudent = Student(result[i][0].as<int>(), result[i][1].as<int>(),
                                        result[i][2].as<std::string>(), result[i][3].as<std::string>(),
                                        std::time_t(nullptr), result[i][5].as<std::string>(),
                                        result[i][6].as<std::string>(), result[i][7].as<int>());
                resultStudents.push_back(currentStudent);
            }
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultStudents;
}

int PgStudentRepo::getStudentID(std::string studentNumber)
{
    int resultID = -1;
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetStudentID().get_text(studentNumber);
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            if (result.size() == 1)
                resultID = result[0][0].as<int>();
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultID;
}

Student PgStudentRepo::getStudent(int id)
{
    Student resultStudent;
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetStudent().get_text(id);
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            if (result.size() == 1)
                resultStudent = Student(result[0][0].as<int>(), result[0][1].as<int>(),
                                        result[0][2].as<std::string>(), result[0][3].as<std::string>(),
                                        std::time_t(nullptr), result[0][5].as<std::string>(),
                                        result[0][6].as<std::string>(), result[0][7].as<int>());
            else
                resultStudent = Student();
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultStudent;
}

void PgStudentRepo::changeStudent(int studentID, StudentDTO studentInfo)
{
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLChangeStudent().get_text(studentID, studentInfo);
            pqxx::work curConnect(*this->connection);
            curConnect.exec(sql);
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}

void PgStudentRepo::transferStudent(int studentID, int roomID, transferDirection direct)
{
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLTransferStudent().get_text(studentID, roomID, direct);
            pqxx::work curConnect(*this->connection);
            curConnect.exec(sql);
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}

void PgStudentRepo::transferThing(int studentID, int thingID, transferDirection direct)
{
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLTransferThing().get_text(studentID, thingID, direct);
            pqxx::work curConnect(*this->connection);
            curConnect.exec(sql);
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
}

std::vector<Thing> PgStudentRepo::getStudentThings(int id)
{
    std::vector<Thing> resultThings = std::vector<Thing>();
    try
    {
        if (this->connection->is_open())
        {
            std::string sql = PostgreSQLGetStudentsThings().get_text(id);
            pqxx::work curConnect(*this->connection);
            pqxx::result result = curConnect.exec(sql);
            for (size_t i = 0; i < result.size(); i++)
            {
                Thing currentThing = Thing(result[i][0].as<int>(), result[i][1].as<int>(),
                                           std::time_t(nullptr), result[i][3].as<std::string>(), id,
                                           result[i][5].as<int>());
                resultThings.push_back(currentThing);
            }
            curConnect.commit();
        }
        else
            throw DatabaseConnectException(__FILE__, typeid(*this).name(), __LINE__);
    }
    catch (const std::exception &e)
    {
          std::cout << e.what() << std::endl;
    }
    return resultThings;
}


#include "sql.h"

std::string PostgreSQLChangeStudent::get_text(int studentID, StudentDTO studentInfo)
{
    return "UPDATE PPO.Student SET StudentName = '" + studentInfo.getName() +
            "', StudentSurname = '" + studentInfo.getSurname() + "', StudentGroup = '" +
            studentInfo.getStudentGroup() + "', StudentNumber = '" + studentInfo.getStudentNumber() +
            "' WHERE StudentID = " + std::to_string(studentID) + ";";
}

std::string PostgreSQLAddStudent::get_text(StudentDTO newStudent, int webID)
{
    return "INSERT INTO PPO.Student(studentname, studentsurname, studentgroup,\
            studentnumber, settledate, webaccid) VALUES ('"+
            newStudent.getName() + "', '" + newStudent.getSurname() +
            "', '" + newStudent.getStudentGroup() + "', '" +
            newStudent.getStudentNumber() + "', current_date, " +
            std::to_string(webID) + ");";
}

std::string PostgreSQLGetAllStudents::get_text()
{
    return "SELECT S.studentid, S.webaccid, S.studentname, S.studentsurname, "\
            "S.settledate, S.studentgroup, S.studentnumber, "\
            "PPO.FindStudentRoom(S.studentid) "\
            "FROM PPO.Student as S;";
}

std::string PostgreSQLGetStudentID::get_text(std::string studentNumber)
{
    return "SELECT S.studentid FROM PPO.Student as S WHERE StudentNumber = " + studentNumber + ";";
}

std::string PostgreSQLGetStudent::get_text(int id)
{
    return "SELECT S.studentid, S.webaccid, S.studentname, S.studentsurname,"\
                      "S.settledate, S.studentgroup, S.studentnumber,"\
                      "PPO.FindStudentRoom(S.studentid) "\
                      "FROM PPO.Student as S WHERE StudentID = " + std::to_string(id) + ";";
}

std::string PostgreSQLTransferStudent::get_text(int studentID, int roomID, transferDirection direct)
{
    return "INSERT INTO PPO.StudentRoomHistory (studentid, roomid, direction, transferdate) VALUES (" +
            std::to_string(studentID) + ", " +
            std::to_string(roomID) + ", " +
            std::to_string(direct) + ", current_date);";
}

std::string PostgreSQLGetStudentsThings::get_text(int id)
{
    return "SELECT T.thingid, T.marknumber, T.creationdate, T.thingtype, PPO.FindStudent(T.thingId),"\
           "PPO.FindRoom(T.thingid) FROM PPO.Thing as T WHERE PPO.FindStudent(T.ThingID) = " +
            std::to_string(id) + ";";
}

std::string PostgreSQLTransferThing::get_text(int studentID, int thingID, transferDirection direct)
{
    return "INSERT INTO PPO.StudentThingHistory (studentid, thingid, direction, transferdate) VALUES (" +
            std::to_string(studentID) + ", " +
            std::to_string(thingID) + ", " +
            std::to_string(direct) + ", current_date);";
}

std::string PostgreSQLTransferThingRoom::get_text(int id, int srcRoomID, int dstRoomID)
{
    return "INSERT INTO PPO.ThingRoomHistory (srcroomid, dstroomid, thingid, transferdate) VALUES (" +
            std::to_string(srcRoomID) + ", " +
            std::to_string(dstRoomID) + ", " +
            std::to_string(id) + ", current_date);";
}

std::string PostgreSQLAddRoom::get_text(RoomDTO room)
{
    return "INSERT INTO PPO.Rooms(roomtype, roomnumber) VALUES ('" +
            room.getRoomType() + "', " +
            std::to_string(room.getRoomNumber()) + ");";
}

std::string PostgreSQLGetRoom::get_text(int id)
{
    return "SELECT * FROM PPO.rooms WHERE RoomID = " + std::to_string(id) + ";";
}

std::string PostgreSQLGetRooms::get_text()
{
    return "SELECT * FROM PPO.rooms";
}

std::string PostgreSQLGetRoomThings::get_text(int id)
{
    return "SELECT T.thingid, T.marknumber, T.creationdate, T.thingtype, PPO.FindStudent(T.thingId),"\
           "PPO.FindRoom(T.thingid) FROM PPO.Thing as T WHERE PPO.FindRoom(T.ThingID) = " +
            std::to_string(id) + ";";
}

std::string PostgreSQLDeleteRoom::get_text(int id)
{
    return "DELETE FROM PPO.rooms WHERE RoomID = " + std::to_string(id) + ";";
}

std::string PostgreSQLAddThing::get_text(ThingDTO thing)
{
    return "INSERT INTO PPO.Thing(marknumber, creationdate, thingtype) VALUES ('" +
            std::to_string(thing.getMarkNumber()) + "', current_date, '" +
            thing.getThingType() + "');";
}

std::string PostgreSQLGetThing::get_text(int id)
{
    return "SELECT T.thingid, T.marknumber, T.creationdate, T.thingtype, PPO.FindStudent(T.thingId),"\
            "PPO.FindRoom(T.thingid) FROM PPO.Thing as T WHERE T.ThingID = " + std::to_string(id) + ";";
}

std::string PostgreSQLGetThings::get_text()
{
    return "SELECT T.thingid, T.marknumber, T.creationdate, T.thingtype, PPO.FindStudent(T.thingId),"\
            "PPO.FindRoom(T.thingid) FROM PPO.Thing as T;";
}

std::string PostgreSQLDeleteThing::get_text(int id)
{
    return "DELETE FROM PPO.Thing WHERE ThingID = " + std::to_string(id) + ";";
}

std::string PostgreSQLAddUser::get_text(std::string login, std::string password, Levels privelageLevel)
{
    return "INSERT INTO PPO.Users(userlogin, userpassword, userrole) VALUES ('" +
                                  login + "', '" + password + "', " + std::to_string(privelageLevel) + ");";
}

std::string PostgreSQLGetUser::get_text(int id)
{
    return "SELECT * FROM PPO.Users WHERE ID = " + std::to_string(id) + ";";
}

std::string PostgreSQLGetUserId::get_text(std::string login)
{
    return "SELECT * FROM PPO.Users WHERE UserLogin = '" + login + "';";
}



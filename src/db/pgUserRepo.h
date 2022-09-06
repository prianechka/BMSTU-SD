#ifndef PGUSERREPO_H
#define PGUSERREPO_H

#include "userRepo.h"
#include "../objects/connection.h"
#include "sql.h"
#include "exceptions.h"

class PgUserRepo : public InterfaceUserRepo
{
private:
    std::string connectString;
    std::shared_ptr<pqxx::connection> connection;

public:
    PgUserRepo(ConnectionParams params);
    ~PgUserRepo() = default;
    int getUserId(std::string login) override;
    User getUser(int id) override;
    void addUser(std::string login, std::string password, Levels privelageLevel) override;
};

#endif // PGUSERREPO_H

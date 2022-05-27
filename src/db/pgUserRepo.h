#ifndef PGUSERREPO_H
#define PGUSERREPO_H

#include "interfaceUserRepo.h"

class PgUserRepo : public InterfaceUserRepo
{
public:
    int getUserId(std::string login) override;
    User getUser(int id) override;
    void addUser(std::string login, std::string password, Levels privelageLevel) override;
};

#endif // PGUSERREPO_H

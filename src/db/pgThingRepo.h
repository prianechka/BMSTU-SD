#ifndef PGTHINGREPO_H
#define PGTHINGREPO_H

#include "thingRepo.h"
#include "../objects/connection.h"
#include "../objects/thing.h"
#include "exceptions.h"
#include "sql.h"

class PgThingRepo : public InterfaceThingRepo
{
private:
    std::string connectString;
    std::shared_ptr<pqxx::connection> connection;
public:
    PgThingRepo(ConnectionParams params);
    ~PgThingRepo() = default;
    void addThing(ThingDTO thing) override;
    std::vector<Thing> getThings() override;
    void deleteThing(int id) override;
    Thing getThing(int id) override;
    void transferThing(int id, int srcRoomID, int dstRoomID) override;
};

#endif // PGTHINGREPO_H

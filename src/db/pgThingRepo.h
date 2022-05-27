#ifndef PGTHINGREPO_H
#define PGTHINGREPO_H

#include "thingRepo.h"

class PgThingRepo : public InterfaceThingRepo
{
private:
    int connection;
public:
    void addThing(ThingDTO thing) override;
    std::vector<Thing> getThings() override;
    void deleteThing(int id) override;
    Thing getThing(int id) override;
    void transferThing(int id, int srcRoomID, int dstRoomID) override;
};

#endif // PGTHINGREPO_H

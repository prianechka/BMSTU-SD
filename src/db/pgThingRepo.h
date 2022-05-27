#ifndef PGTHINGREPO_H
#define PGTHINGREPO_H

#include "interfaceThingRepo.h"

class PgThingRepo : public InterfaceThingRepo
{
public:
    void addThing(int markNumber, std::string type) override;
    std::vector<Thing> getThings() override;
    void deleteThing(int id) override;
    Thing getThingInfo(int id) override;
    void transferThing(int id, int srcRoomID, int dstRoomID) override;
};

#endif // PGTHINGREPO_H

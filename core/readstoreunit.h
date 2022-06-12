#ifndef READSTOREUNIT_H
#define READSTOREUNIT_H
#include "ExecuteModul.h"

class ReadStoreUnit : public ExecuteModule
{
public:
    ReadStoreUnit();

    // ExecuteModule interface
private:
    void execute(Instruction instruction);
};

#endif // READSTOREUNIT_H

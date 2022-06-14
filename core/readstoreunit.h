#ifndef READSTOREUNIT_H
#define READSTOREUNIT_H
#include "ExecuteModul.h"

class ReadStoreUnit : public ExecuteModule
{
public:
    ReadStoreUnit();

    // ExecuteModule interface
    void execute(DecodedInstruction decodedInstruction);
};

#endif // READSTOREUNIT_H

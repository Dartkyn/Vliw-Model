#ifndef FLOWCONTROLUNIT_H
#define FLOWCONTROLUNIT_H
#include "ExecuteModul.h"

class FlowControlUnit : public ExecuteModule
{
public:
    FlowControlUnit();

    // ExecuteModule interface
    void execute(DecodedInstruction decodedInstruction);
};

#endif // FLOWCONTROLUNIT_H

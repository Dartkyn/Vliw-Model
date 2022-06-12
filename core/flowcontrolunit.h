#ifndef FLOWCONTROLUNIT_H
#define FLOWCONTROLUNIT_H
#include "ExecuteModul.h"

class FlowControlUnit : public ExecuteModule
{
public:
    FlowControlUnit();

    // ExecuteModule interface
private:
    void execute(Instruction instruction);
};

#endif // FLOWCONTROLUNIT_H

#ifndef EXECUTEMODUL_H
#define EXECUTEMODUL_H
#include "instruction.h"
class ExecuteModule
{
    virtual void execute(Instruction instruction) = 0;
};
#endif // EXECUTEMODUL_H

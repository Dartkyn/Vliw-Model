#ifndef EXECUTEMODUL_H
#define EXECUTEMODUL_H
#include "instruction.h"
#include "KeyWords.h"
class ExecuteModule
{
public:
    virtual void execute(DecodedInstruction decodedInstruction) = 0;
};
#endif // EXECUTEMODUL_H

#ifndef ARITHMETICLOGICUNIT_H
#define ARITHMETICLOGICUNIT_H
#include "ExecuteModul.h"

class ArithmeticLogicUnit : public ExecuteModule
{
public:
    ArithmeticLogicUnit();

    // ExecuteModule interface
    void execute(DecodedInstruction decodedInstruction);
};

#endif // ARITHMETICLOGICUNIT_H

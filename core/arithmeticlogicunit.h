#ifndef ARITHMETICLOGICUNIT_H
#define ARITHMETICLOGICUNIT_H
#include "ExecuteModul.h"

class ArithmeticLogicUnit : public ExecuteModule
{
public:
    ArithmeticLogicUnit();

    // ExecuteModule interface
private:
    void execute(Instruction instruction);
};

#endif // ARITHMETICLOGICUNIT_H

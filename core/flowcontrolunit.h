#ifndef FLOWCONTROLUNIT_H
#define FLOWCONTROLUNIT_H
#include "ExecuteModul.h"

class FlowControlUnit : public ExecuteModule
{
public:
    FlowControlUnit();

    // ExecuteModule interface
    void execute(DecodedInstruction decodedInstruction);
private:
    void execJump(QList<Operand> operands);
    void execJeq(QList<Operand> operands);
    void execJeqz(QList<Operand> operands);
    void execJgez(QList<Operand> operands);
    void execJne(QList<Operand> operands);
    void execJnez(QList<Operand> operands);
    void execJal(QList<Operand> operands);
    void execJ(QList<Operand> operands);
};

#endif // FLOWCONTROLUNIT_H

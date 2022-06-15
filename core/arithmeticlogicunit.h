#ifndef ARITHMETICLOGICUNIT_H
#define ARITHMETICLOGICUNIT_H
#include "ExecuteModul.h"

class ArithmeticLogicUnit : public ExecuteModule
{
public:
    ArithmeticLogicUnit();

    // ExecuteModule interface
    void execute(DecodedInstruction decodedInstruction);
private:
    void execAnd(QList<Operand> operands);
    void execAdd(QList<Operand> operands);
    void execDAdd(QList<Operand> operands);
    void execSub(QList<Operand> operands);
    void execDSub(QList<Operand> operands);
    void execDiv(QList<Operand> operands);
    void execDDiv(QList<Operand> operands);
    void execMult(QList<Operand> operands);
    void execDMult(QList<Operand> operands);
    void execOR(QList<Operand> operands);
    void execXOR(QList<Operand> operands);
    void execNot(QList<Operand> operands);
    void execSsl(QList<Operand> operands);
    void execDSsl(QList<Operand> operands);
    void execSrl(QList<Operand> operands);
    void execDSrl(QList<Operand> operands);
    void execMflo(Operand operand);
    void execMfhi(Operand operand);
    void execMovn(QList<Operand> operands);
    void execMovz(QList<Operand> operands);

};

#endif // ARITHMETICLOGICUNIT_H

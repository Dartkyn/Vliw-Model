#ifndef READSTOREUNIT_H
#define READSTOREUNIT_H
#include "ExecuteModul.h"

class ReadStoreUnit : public ExecuteModule
{
public:
    ReadStoreUnit();

    // ExecuteModule interface
    void execute(DecodedInstruction decodedInstruction);
private:
    void execLB(QList<Operand> operands);
    void execLD(QList<Operand> operands);
    void execLH(QList<Operand> operands);
    void execLW(QList<Operand> operands);
    void execSB(QList<Operand> operands);
    void execSD(QList<Operand> operands);
    void execSH(QList<Operand> operands);
    void execSW(QList<Operand> operands);
};

#endif // READSTOREUNIT_H

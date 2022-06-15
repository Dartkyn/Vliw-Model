#include "readstoreunit.h"
#include "QDebug"
ReadStoreUnit::ReadStoreUnit()
{

}


void ReadStoreUnit::execute(DecodedInstruction decodedInstruction)
{
    qDebug() << "I ReadStoreUnit execute: " + decodedInstruction.toString();
}

void ReadStoreUnit::execLB(QList<Operand> operands)
{
    
}

void ReadStoreUnit::execLD(QList<Operand> operands)
{
    
}

void ReadStoreUnit::execLH(QList<Operand> operands)
{
    
}

void ReadStoreUnit::execLW(QList<Operand> operands)
{
    
}

void ReadStoreUnit::execSB(QList<Operand> operands)
{
    
}

void ReadStoreUnit::execSD(QList<Operand> operands)
{
    
}

void ReadStoreUnit::execSH(QList<Operand> operands)
{
    
}

void ReadStoreUnit::execSW(QList<Operand> operands)
{
    
}

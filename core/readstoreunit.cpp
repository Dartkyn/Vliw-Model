#include "readstoreunit.h"
#include "QDebug"
ReadStoreUnit::ReadStoreUnit()
{

}


void ReadStoreUnit::execute(DecodedInstruction decodedInstruction)
{
    qDebug() << "I ReadStoreUnit execute: " + decodedInstruction.toString();
    auto kwordCN = decodedInstruction.kword.codeNumber;
    if(kwordCN == kwLB.codeNumber){execLB(decodedInstruction.operands); return;}
    if(kwordCN == kwLD.codeNumber){execLD(decodedInstruction.operands); return;}
    if(kwordCN == kwLH.codeNumber){execLH(decodedInstruction.operands); return;}
    if(kwordCN == kwLW.codeNumber){execLW(decodedInstruction.operands); return;}
    if(kwordCN == kwSB.codeNumber){execSB(decodedInstruction.operands); return;}
    if(kwordCN == kwSD.codeNumber){execSD(decodedInstruction.operands); return;}
    if(kwordCN == kwSH.codeNumber){execSH(decodedInstruction.operands); return;}
    if(kwordCN == kwSW.codeNumber){execSW(decodedInstruction.operands); return;}
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

#include "arithmeticlogicunit.h"
#include "QDebug"
ArithmeticLogicUnit::ArithmeticLogicUnit()
{

}


void ArithmeticLogicUnit::execute(DecodedInstruction decodedInstruction)
{
    qDebug() << "I ArithmeticLogicUnit execute: " + decodedInstruction.toString();
    auto kwordCN = decodedInstruction.kword.codeNumber;
    if(kwordCN == kwAnd.codeNumber){execAnd(decodedInstruction.operands); return;}
    if(kwordCN == kwAdd.codeNumber){execAdd(decodedInstruction.operands); return;}
    if(kwordCN == kwDAdd.codeNumber){execDAdd(decodedInstruction.operands); return;}
    if(kwordCN == kwSub.codeNumber){execSub(decodedInstruction.operands); return;}
    if(kwordCN == kwDSub.codeNumber){execDSub(decodedInstruction.operands); return;}
    if(kwordCN == kwDiv.codeNumber){execDiv(decodedInstruction.operands); return;}
    if(kwordCN == kwDDiv.codeNumber){execDDiv(decodedInstruction.operands); return;}
    if(kwordCN == kwMult.codeNumber){execMult(decodedInstruction.operands); return;}
    if(kwordCN == kwDMult.codeNumber){execDMult(decodedInstruction.operands); return;}
    if(kwordCN == kwOr.codeNumber){execOR(decodedInstruction.operands); return;}
    if(kwordCN == kwXor.codeNumber){execXOR(decodedInstruction.operands); return;}
    if(kwordCN == kwNot.codeNumber){execNot(decodedInstruction.operands); return;}
    if(kwordCN == kwSsl.codeNumber){execSsl(decodedInstruction.operands); return;}
    if(kwordCN == kwDSsl.codeNumber){execDSsl(decodedInstruction.operands); return;}
    if(kwordCN == kwSrl.codeNumber){execSrl(decodedInstruction.operands); return;}
    if(kwordCN == kwDsrl.codeNumber){execDSrl(decodedInstruction.operands); return;}
    if(kwordCN == kwMflo.codeNumber){execMflo(decodedInstruction.operands.at(0)); return;}
    if(kwordCN == kwMfhi.codeNumber){execMfhi(decodedInstruction.operands.at(0)); return;}
    if(kwordCN == kwMovn.codeNumber){execMovn(decodedInstruction.operands); return;}
    if(kwordCN == kwMovz.codeNumber){execMovz(decodedInstruction.operands); return;}
}

void ArithmeticLogicUnit::execAnd(QList<Operand> operands)
{
    auto result = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto operand1 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(2);
    auto operand2 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    long long res = operand1&operand2;
    result->setDoubleWord(res);
}

void ArithmeticLogicUnit::execAdd(QList<Operand> operands)
{
    auto result = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto operand1 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(2);
    auto operand2 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    result->setHalfWord(operand1+operand2);
}

void ArithmeticLogicUnit::execDAdd(QList<Operand> operands)
{
    auto result = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto operand1 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(2);
    auto operand2 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    result->setDoubleWord(operand1+operand2);
}

void ArithmeticLogicUnit::execSub(QList<Operand> operands)
{
    auto result = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto operand1 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(2);
    auto operand2 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    result->setHalfWord(operand1-operand2);
}

void ArithmeticLogicUnit::execDSub(QList<Operand> operands)
{
    auto result = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto operand1 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(2);
    auto operand2 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    result->setDoubleWord(operand1+operand2);
}

void ArithmeticLogicUnit::execDiv(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execDDiv(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execMult(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execDMult(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execOR(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execXOR(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execNot(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execSsl(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execDSsl(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execSrl(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execDSrl(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execMflo(Operand operand)
{

}

void ArithmeticLogicUnit::execMfhi(Operand operand)
{

}

void ArithmeticLogicUnit::execMovn(QList<Operand> operands)
{

}

void ArithmeticLogicUnit::execMovz(QList<Operand> operands)
{

}

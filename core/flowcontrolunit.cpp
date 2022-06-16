#include "flowcontrolunit.h"
#include "QDebug"
FlowControlUnit::FlowControlUnit()
{

}


void FlowControlUnit::execute(DecodedInstruction decodedInstruction)
{
    qDebug() << "I FlowControlUnit execute: " + decodedInstruction.toString();
    auto kwordCN = decodedInstruction.kword.codeNumber;
    if(kwordCN == kwJump.codeNumber){execJump(decodedInstruction.operands); return;}
    if(kwordCN == kwJeq.codeNumber){execJeq(decodedInstruction.operands); return;}
    if(kwordCN == kwJeqz.codeNumber){execJeqz(decodedInstruction.operands); return;}
    if(kwordCN == kwJgez.codeNumber){execJgez(decodedInstruction.operands); return;}
    if(kwordCN == kwJne.codeNumber){execJne(decodedInstruction.operands); return;}
    if(kwordCN == kwJnez.codeNumber){execJnez(decodedInstruction.operands); return;}
    if(kwordCN == kwJal.codeNumber){execJal(decodedInstruction.operands); return;}
    if(kwordCN == kwJ.codeNumber){execJ(decodedInstruction.operands); return;}
}

void FlowControlUnit::execJump(QList<Operand> operands)
{
    auto ic = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto operand = (oper.toperand == typeoper::adress)? oper.value.adress : oper.value.value;
    long long res = operand;
    ic->setDoubleWord(res);
}

void FlowControlUnit::execJeq(QList<Operand> operands)
{
    auto ic = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto operand1 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(2);
    auto operand2 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(3);
    auto point = (oper.toperand == typeoper::adress)? oper.value.adress : oper.value.value;
    if(operand1==operand2)
    {
        ic->setDoubleWord(point);
    }
}

void FlowControlUnit::execJeqz(QList<Operand> operands)
{
    auto ic = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto operand = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(2);
    auto point = (oper.toperand == typeoper::adress)? oper.value.adress : oper.value.value;
    if(operand==0)
    {
        ic->setDoubleWord(point);
    }
}

void FlowControlUnit::execJgez(QList<Operand> operands)
{
    auto ic = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto operand = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(2);
    auto point = (oper.toperand == typeoper::adress)? oper.value.adress : oper.value.value;
    if(operand>0)
    {
        ic->setDoubleWord(point);
    }
}

void FlowControlUnit::execJne(QList<Operand> operands)
{
    auto ic = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto operand1 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(2);
    auto operand2 = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(3);
    auto point = (oper.toperand == typeoper::adress)? oper.value.adress : oper.value.value;
    if(operand1!=operand2)
    {
        ic->setDoubleWord(point);
    }
}

void FlowControlUnit::execJnez(QList<Operand> operands)
{
    auto ic = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto operand = (oper.toperand == typeoper::rgister)? oper.value.reg->getDoubleWord() : oper.value.value;
    oper = operands.at(2);
    auto point = (oper.toperand == typeoper::adress)? oper.value.adress : oper.value.value;
    if(operand!=0)
    {
        ic->setDoubleWord(point);
    }
}

void FlowControlUnit::execJal(QList<Operand> operands)
{
    auto ic = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto r23 = oper.value.reg;
    oper = operands.at(2);
    auto point = (oper.toperand == typeoper::adress)? oper.value.adress : oper.value.value;
    r23->setDoubleWord(ic->getDoubleWord());
    ic->setDoubleWord(point);
}

void FlowControlUnit::execJ(QList<Operand> operands)
{
    auto ic = operands.at(0).value.reg;
    auto oper = operands.at(1);
    auto point = (oper.toperand == typeoper::adress)? oper.value.adress : oper.value.value;
    ic->setDoubleWord(point);
}

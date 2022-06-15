#include "flowcontrolunit.h"
#include "QDebug"
FlowControlUnit::FlowControlUnit()
{

}


void FlowControlUnit::execute(DecodedInstruction decodedInstruction)
{
    qDebug() << "I FlowControlUnit execute: " + decodedInstruction.toString();
}

void FlowControlUnit::execJump(Operand operand)
{
    
}

void FlowControlUnit::execJeq(QList<Operand> operands)
{
    
}

void FlowControlUnit::execJeqz(QList<Operand> operands)
{
    
}

void FlowControlUnit::execJgez(QList<Operand> operands)
{
    
}

void FlowControlUnit::execJne(QList<Operand> operands)
{
    
}

void FlowControlUnit::execJnez(QList<Operand> operands)
{
    
}

void FlowControlUnit::execJal(Operand operand)
{
    
}

void FlowControlUnit::execJ(Operand operand)
{
    
}

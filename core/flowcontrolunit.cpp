#include "flowcontrolunit.h"
#include "QDebug"
FlowControlUnit::FlowControlUnit()
{

}


void FlowControlUnit::execute(DecodedInstruction decodedInstruction)
{
    qDebug() << "I FlowControlUnit execute: " + decodedInstruction.toString();
}

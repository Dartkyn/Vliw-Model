#include "arithmeticlogicunit.h"
#include "QDebug"
ArithmeticLogicUnit::ArithmeticLogicUnit()
{

}


void ArithmeticLogicUnit::execute(DecodedInstruction decodedInstruction)
{
    qDebug() << "I ArithmeticLogicUnit execute: " + decodedInstruction.toString();
}

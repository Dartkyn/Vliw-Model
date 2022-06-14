#include "readstoreunit.h"
#include "QDebug"
ReadStoreUnit::ReadStoreUnit()
{

}


void ReadStoreUnit::execute(DecodedInstruction decodedInstruction)
{
    qDebug() << "I ReadStoreUnit execute: " + decodedInstruction.toString();
}

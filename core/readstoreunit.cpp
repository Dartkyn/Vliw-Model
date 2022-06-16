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
    auto reg = operands.at(0).value.reg;
    auto data = operands.at(1).value.data;
    auto index = operands.at(2).value.adress;
    QByteArray arr;
    arr.setNum(data->dataValue());
    while(arr.length() < 16)
        arr.push_front('0');
    char value = arr.at(index);
    reg->setByte(value);
}

void ReadStoreUnit::execLD(QList<Operand> operands)
{
    auto reg = operands.at(0).value.reg;
    auto data = operands.at(1).value.data;
    reg->setDoubleWord(data->dataValue());
}

void ReadStoreUnit::execLH(QList<Operand> operands)
{
    auto reg = operands.at(0).value.reg;
    auto data = operands.at(1).value.data;
    auto index = operands.at(2).value.adress;
    QByteArray arr;
    arr.setNum(data->dataValue());
    while(arr.length() < 16)
        arr.push_front('0');
    QByteArray value;
    for(int i = index*2; i<= (index+1)*2;i++)
        value.append(arr.at(i));
    reg->setHalfWord(value.toShort());
}

void ReadStoreUnit::execLW(QList<Operand> operands)
{
    auto reg = operands.at(0).value.reg;
    auto data = operands.at(1).value.data;
    auto index = operands.at(2).value.adress;
    QByteArray arr;
    arr.setNum(data->dataValue());
    while(arr.length() < 16)
        arr.push_front('0');
    QByteArray value;
    for(int i = index*4; i<= (index+1)*4;i++)
        value.append(arr.at(index*4));
    reg->setWord(value.toInt());
}

void ReadStoreUnit::execSB(QList<Operand> operands)
{
    auto reg = operands.at(0).value.reg;
    auto data = operands.at(1).value.data;
    auto index = operands.at(2).value.adress;
    QByteArray arr;
    arr.setNum(data->dataValue());
    while(arr.length() < 16)
        arr.push_front('0');
    char value = reg->getByte();
    arr.insert(value,index);
    data->setDataValue(arr.toLongLong());
}

void ReadStoreUnit::execSD(QList<Operand> operands)
{
    auto reg = operands.at(0).value.reg;
    auto data = operands.at(1).value.data;
    data->setDataValue(reg->getDoubleWord());
}

void ReadStoreUnit::execSH(QList<Operand> operands)
{
    auto reg = operands.at(0).value.reg;
    auto data = operands.at(1).value.data;
    auto index = operands.at(2).value.adress;
    QByteArray arr;
    arr.setNum(data->dataValue());
    while(arr.length() < 16)
        arr.push_front('0');
    short value = reg->getHalfWord();
    arr.insert(value,index*2);
    data->setDataValue(arr.toLongLong());
}

void ReadStoreUnit::execSW(QList<Operand> operands)
{
    auto reg = operands.at(0).value.reg;
    auto data = operands.at(1).value.data;
    auto index = operands.at(2).value.adress;
    QByteArray arr;
    arr.setNum(data->dataValue());
    while(arr.length() < 16)
        arr.push_front('0');
    int value = reg->getWord();
    arr.insert(value,index*4);
    data->setDataValue(arr.toLongLong());
}

#include "register.h"

Register::Register()
{
    _registerValue = 0;
}

char Register::getByte()
{
    return char(_registerValue);
}

short Register::getHalfWord()
{
    return short(_registerValue);
}

int Register::getWord()
{
    return int(_registerValue);
}

long long Register::getDoubleWord()
{
    return _registerValue;
}

void Register::setByte(char value)
{
    _registerValue = value;
}

void Register::setHalfWord(short value)
{
    _registerValue = value;
}

void Register::setWord(int value)
{
    _registerValue = value;
}

void Register::setDoubleWord(long long value)
{
    _registerValue = value;
}

QString Register::toString()
{
    QString str = QString::number(_registerValue, 16);
    while(str.length()< 16)
        str.push_front("0");
    return str;
}


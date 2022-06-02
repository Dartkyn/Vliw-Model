#include "registerblock.h"

RegisterBlock::RegisterBlock()
{
    for(int i= 0 ; i < 24; i++)
    {
        Register reg;
        _generalPurposeRegisters.push_back(reg);
    }
}

Register RegisterBlock::getRegister(QString regName)
{
    auto str = regName.toLower();
    if(str.first(1)=='r')
    {
       int ind = regName.replace("r", "").toInt();
       return _generalPurposeRegisters[ind];
    }
    else
    {
        if(str == "hi")
            return _HI;
        else
        {
            if(str == "lo")
                return _LO;
            else
                return _IC;
        }
    }
}

const Register &RegisterBlock::IC() const
{
    return _IC;
}

void RegisterBlock::setIC(const Register &newIC)
{
    _IC = newIC;
}

const Register &RegisterBlock::HI() const
{
    return _HI;
}

void RegisterBlock::setHI(const Register &newHI)
{
    _HI = newHI;
}

const Register &RegisterBlock::LO() const
{
    return _LO;
}

void RegisterBlock::setLO(const Register &newLO)
{
    _LO = newLO;
}

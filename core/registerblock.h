#ifndef REGISTERBLOCK_H
#define REGISTERBLOCK_H
#include "register.h"
#include "QList"

class RegisterBlock
{
public:
    RegisterBlock();
    Register getRegister(QString regName);
    const Register &IC() const;
    void setIC(const Register &newIC);

    const Register &HI() const;
    void setHI(const Register &newHI);

    const Register &LO() const;
    void setLO(const Register &newLO);
    QStringList toString();
private:
    QList<Register> _generalPurposeRegisters;
    Register _IC;
    Register _HI;
    Register _LO;
};

#endif // REGISTERBLOCK_H

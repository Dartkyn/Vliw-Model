#ifndef REGISTERBLOCK_H
#define REGISTERBLOCK_H
#include "register.h"
#include "QList"
//TODO подумать над реализацией регистра флагов.
class RegisterBlock
{
public:
    RegisterBlock();
    Register* getRegisterOnName(QString regName);
    Register &IC();
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

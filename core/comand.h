#ifndef COMAND_H
#define COMAND_H
#include "instruction.h"
class Comand
{
public:
    Comand();
    Comand(const QString &label, const QList<Instruction*> &instructions);
    const QString &label() const;
    void setLabel(const QString &newLabel);

    const QList<Instruction*> &instructions() const;
    void setInstructions(const QList<Instruction*> &newInstructions);
    QString toString();
private:
    QString _label;
    QList<Instruction*> _instructions;

};

#endif // COMAND_H

#include "comand.h"

Comand::Comand()
{

}

const QString &Comand::label() const
{
    return _label;
}

void Comand::setLabel(const QString &newLabel)
{
    _label = newLabel;
}

const QList<Instruction> &Comand::instructions() const
{
    return _instructions;
}

void Comand::setInstructions(const QList<Instruction> &newInstructions)
{
    _instructions = newInstructions;
}

QString Comand::toString()
{
    QString str = _label + " ";
    for(int i = 0; i< _instructions.length() - 1; i++)
    {
        str = str + _instructions[i].toString() + ";";
    }
    str = str + _instructions.back().toString();
    return str;
}

Comand::Comand(const QString &label, const QList<Instruction> &instructions) : _label(label),
    _instructions(instructions)
{}

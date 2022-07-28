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
    QString str;
    str =(_label.length() > 0)? _label + "//": "";
    for(int i = 0; i < _instructions.length() - 1; i++)
    {
        str = str + _instructions[i].toString() + ";";
    }
    str = str + _instructions.back().toString();
    return str;
}

bool Comand::operator ==(Comand comad)
{
    if(this == nullptr)
    {
        return false;
    }
    bool flag = true;
    for(int i = 0; i < this->_instructions.length(); i++)
    {
        if(!(this->_instructions.at(i) == comad._instructions.at(i)))
        {
            flag = false;
        }
    }
    return flag;

}

Comand::Comand(const QString &label, const QList<Instruction> &instructions) : _label(label),
    _instructions(instructions)
{}

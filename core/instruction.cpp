#include "instruction.h"

Instruction::Instruction()
{

}

Instruction::Instruction(QString keyword, const QStringList &parameters) : _keyword(keyword),
    _parameters(parameters)
{}

QString Instruction::keyword() const
{
    return _keyword;
}

void Instruction::setKeyword(QString newKeyword)
{
    _keyword = newKeyword;
}

const QStringList &Instruction::parameters() const
{
    return _parameters;
}

void Instruction::setParameters(const QStringList &newParameters)
{
    _parameters = newParameters;
}

QString Instruction::toString()
{
    QString str = _keyword + " ";
    // TODO Проверить, нужны ли параметры
    for(int i = 0; i< _parameters.length(); i++)
    {
        str = str + _parameters[i] + ",";
    }
    return str;

}


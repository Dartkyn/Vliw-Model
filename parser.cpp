#include "parser.h"

Parser::Parser()
{

}

void Parser::parseString(QStringList fileStringList)
{


}

const QStringList &Parser::getDataStrings() const
{
    return dataStrings;
}

void Parser::setDataStrings(const QStringList &newDataStrings)
{
    dataStrings = newDataStrings;
}

const QList<Comand> &Parser::getComandList() const
{
    return comandList;
}

void Parser::setComandList(const QList<Comand> &newComandList)
{
    comandList = newComandList;
}

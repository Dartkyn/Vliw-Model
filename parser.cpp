#include "parser.h"

Parser::Parser()
{

}

void Parser::parseString(QStringList fileStringList)
{
    int uk_str = 0;
    while(uk_str < fileStringList.length())
    {
        qDebug() << fileStringList[uk_str];
        if(fileStringList[uk_str] == kwData)
        {
            uk_str = parseDataString(++uk_str, fileStringList);
        }
        else
        {

            uk_str = parseCodeString(++uk_str, fileStringList);
        }
        uk_str++;
    }
}

const QStringList &Parser::getDataStrings() const
{
    return _dataStrings;
}


const QList<Comand> &Parser::getComandList() const
{
    return _comandList;
}

int Parser::parseDataString(int number, QStringList fileStringList)
{
    qDebug() << "Hello from parseData";
    return number++;
}

int Parser::parseCodeString(int number, QStringList fileStringList)
{
    Comand comand;
    qDebug() << "Hello from parseCode";
    QString currentStr = fileStringList[number];
    qDebug() <<currentStr;
    int indxLabelEnd = currentStr.indexOf(":") + 2;
    qDebug() << indxLabelEnd;
    int indxCommentEnd = currentStr.indexOf("#");
    QString label = currentStr.section("", 0, indxLabelEnd);
    QString comment = currentStr.section("", indxCommentEnd,currentStr.length());
    currentStr = currentStr.section("", indxLabelEnd, indxCommentEnd);
    comand = parseComand(currentStr);
    comand.setLabel(label);
    _comandList.append(comand);
    qDebug() << currentStr;
    return number++;
}

Comand Parser::parseComand(QString str)
{
    Comand com;
    return com;
}

Instruction Parser::parseInstructrions(QString str)
{
    Instruction inst;
    return inst;
}





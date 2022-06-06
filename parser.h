#ifndef PARSER_H
#define PARSER_H
#include "core/comand.h"
#include "QDebug"
class Parser
{
public:
    Parser();
    void parseString(QStringList fileStringList);
    const QStringList &getDataStrings() const;

    const QList<Comand> &getComandList() const;

private:
    QStringList _dataStrings;
    QList<Comand> _comandList;

    int parseDataString(int number, QStringList fileStringList);
    int parseCodeString(int number, QStringList fileStringList);
    Instruction parseInstructrions(QString str);
    Comand parseComand(QString str);
};

#endif // PARSER_H

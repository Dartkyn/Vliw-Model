#ifndef PARSER_H
#define PARSER_H
#include "core/comand.h"
#include "core/data.h"
#include "QDebug"
class Parser
{
public:
    Parser();
    void parseString(QStringList fileStringList);
    const QList<Data> &getDataStrings() const;

    const QList<Comand> &getComandList() const;

private:
    QList<Data> _dataStrings;
    QList<Comand> _comandList;

    void parseDataString(QString currentStr);
    void parseCodeString(QString currentStr);
    Instruction* parseInstructrions(QString str);
    Comand parseComand(QString str, QString label);
};

#endif // PARSER_H

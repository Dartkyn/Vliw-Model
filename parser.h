#ifndef PARSER_H
#define PARSER_H
#include "core/comand.h"

class Parser
{
public:
    Parser();
    void parseString(QStringList fileStringList);
    const QStringList &getDataStrings() const;
    void setDataStrings(const QStringList &newDataStrings);

    const QList<Comand> &getComandList() const;
    void setComandList(const QList<Comand> &newComandList);

private:
    QStringList dataStrings;
    QList<Comand> comandList;
};

#endif // PARSER_H

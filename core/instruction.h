#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "KeyWords.h"
#include "QStringList"
class Instruction
{
public:
    Instruction();
    Instruction(QString keyword, const QStringList &parameters);
    QString keyword() const;
    void setKeyword(QString newKeyword);

    const QStringList &parameters() const;
    void setParameters(const QStringList &newParameters);
    QString toString();
private:
    QString _keyword;
    QStringList _parameters;


};

#endif // INSTRUCTION_H

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "KeyWords.h"
#include "QStringList"
class Instruction
{
public:
    Instruction();
    Instruction(QString keyword, const QStringList &parameters);
    Keyword keyword() const;
    void setKeyword(QString newKeyword);

    const QStringList &parameters() const;
    void setParameters(const QStringList &newParameters);
    QString toString();
    bool operator == (Instruction instruction) const;
private:
    Keyword _keyword;
    QStringList _parameters;
    Keyword findKeyword(QString newKWord);

};

#endif // INSTRUCTION_H

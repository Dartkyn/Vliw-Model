#ifndef KEYWORDS_H
#define KEYWORDS_H
#include "QString"

constexpr int MEM_SIZE = 0x100;
struct Keyword{
    QString kword;
    int codeNumber;
};
//ключевые слова - директивы.
static const QString kwData = ".data";
static const QString kwCode = ".code";
//Ключевые слова - директивы данных
static const Keyword kwByte = {".byte", 001};
static const Keyword kwHalfWord = { ".hword", 002};
static const Keyword kwWord = {".word", 003};
static const Keyword kwDoubleWord = { ".dword", 004};
//Ключевые слова - арифметико-логические команды
static const Keyword kwAnd = {"and", 010};
static const Keyword kwAdd = {"add", 011};
static const Keyword kwDAdd = {"dadd", 012};
static const Keyword kwSub = {"sub",013};
static const Keyword kwDSub = {"dsub",014};
static const Keyword kwDiv = {"div",015};
static const Keyword kwDDiv = {"ddiv",016};
static const Keyword kwMult = {"mult",017};
static const Keyword kwDMult = {"dmult", 18};
static const Keyword kwOr = {"or",19};
static const Keyword kwXor = {"xor",20};
static const Keyword kwNot = {"not",21};
static const Keyword kwSsl = {"ssl",22};
static const Keyword kwDSsl = {"dssl",23};
static const Keyword kwSrl = {"srl",24};
static const Keyword kwDsrl = {"dsrl",25};
static const Keyword kwMflo = {"mflo",26};
static const Keyword kwMfhi = {"mfhi",27};
static const Keyword kwMovn = {"movn",28};
static const Keyword kwMovz = {"movz",29};
//Ключевые слова - команды обмена с памятью
static const Keyword kwLB = {"lb",30};
static const Keyword kwLD = {"ld",31};
static const Keyword kwLH = {"lh",32};
static const Keyword kwLW = {"lw",33};
static const Keyword kwSB = {"sb",34};
static const Keyword kwSD = {"sd",35};
static const Keyword kwSH = {"sh",36};
static const Keyword kwSW = {"sw",37};
//Ключевые слова - команды переходов
static const Keyword kwJump = {"jump",40};
static const Keyword kwJeq = {"jeq",41};
static const Keyword kwJeqz = {"jeqz",42};
static const Keyword kwJgez = {"jgez",43};
static const Keyword kwJne = {"jne",44};
static const Keyword kwJnez = {"jnez",45};
static const Keyword kwJal = {"jal",46};
static const Keyword kwJ = {"j",47};

static const Keyword kwNop = {"nop",100};
static const Keyword kwErr = {"error",666};

/*static const QString flContKW[] = {kwJump, kwJeq, kwJeqz,kwJgez,kwJne,kwJnez, kwJal, kwJ};
static const QString rdStKW[] = {kwLB, kwLD,kwLH,kwLW, kwSB, kwSD, kwSH, kwSW};
static const QString aluKW[] = {kwAnd, kwAdd, kwDAdd, kwSub, kwDSub, kwDiv,
                                kwDDiv, kwMult, kwDMult, kwOr, kwXor,
                               kwNot, kwSsl, kwDSsl, kwSrl, kwDsrl, kwMflo, kwMfhi, kwMovn, kwMovz};

*/
#endif // KEYWORDS_H

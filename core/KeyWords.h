#ifndef KEYWORDS_H
#define KEYWORDS_H
#include "QString"

constexpr int MEM_SIZE = 0x100;

//ключевые слова - директивы.
static const QString kwData = ".data";
static const QString kwCode = ".code";
//Ключевые слова - директивы данных
static const QString kwByte = ".byte";
static const QString kwHalfWord = ".hword";
static const QString kwWord = ".word";
static const QString kwDoubleWord = ".dword";
//Ключевые слова - арифметико-логические команды
static const QString kwAnd = "and";
static const QString kwAdd = "add";
static const QString kwDAdd = "dadd";
static const QString kwSub = "sub";
static const QString kwDSub = "dsub";
static const QString kwDiv = "div";
static const QString kwDDiv = "ddiv";
static const QString kwMult = "mult";
static const QString kwDMult = "dmult";
static const QString kwOr = "or";
static const QString kwXor = "xor";
static const QString kwNot = "not";
static const QString kwSsl = "ssl";
static const QString kwDSsl = "dssl";
static const QString kwSrl = "srl";
static const QString kwDsrl = "dsrl";
static const QString kwMflo = "mflo";
static const QString kwMfhi = "mfhi";
static const QString kwMovn = "movn";
static const QString kwMovz = "movz";
//Ключевые слова - команды обмена с памятью
static const QString kwLB = "lb";
static const QString kwLD = "ld";
static const QString kwLH = "lh";
static const QString kwLW = "lw";
static const QString kwSB = "sb";
static const QString kwSD = "sd";
static const QString kwSH = "sh";
static const QString kwSW = "sw";
//Ключевые слова - команды переходов
static const QString kwJump = "jump";
static const QString kwJeq = "jeq";
static const QString kwJeqz = "jeqz";
static const QString kwJgez = "jgez";
static const QString kwJne = "jne";
static const QString kwJnez = "jnez";
static const QString kwJal = "jal";
static const QString kwJ = "j";

static const QString kwNop = "nop";
#endif // KEYWORDS_H

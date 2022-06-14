#ifndef KEYWORDS_H
#define KEYWORDS_H
#include "QString"
#include "register.h"
#include "QList"
struct Keyword{
    QString kword;
    int codeNumber;
    int operCount;
};
//ключевые слова - директивы.
static const QString kwData = ".data";
static const QString kwCode = ".code";
//Ключевые слова - директивы данных
static const Keyword kwByte = {".byte", 001,0};
static const Keyword kwHalfWord = { ".hword", 002,0};
static const Keyword kwWord = {".word", 003,0};
static const Keyword kwDoubleWord = { ".dword", 004,0};
//Ключевые слова - арифметико-логические команды
static const Keyword kwAnd = {"and", 010,3};
static const Keyword kwAdd = {"add", 011,3};
static const Keyword kwDAdd = {"dadd", 012,3};
static const Keyword kwSub = {"sub",013,3};
static const Keyword kwDSub = {"dsub",014,3};
static const Keyword kwDiv = {"div",015,2};
static const Keyword kwDDiv = {"ddiv",016,2};
static const Keyword kwMult = {"mult",017,2};
static const Keyword kwDMult = {"dmult", 18,2};
static const Keyword kwOr = {"or",19,3};
static const Keyword kwXor = {"xor",20,3};
static const Keyword kwNot = {"not",21,1};
static const Keyword kwSsl = {"ssl",22,3};
static const Keyword kwDSsl = {"dssl",23,3};
static const Keyword kwSrl = {"srl",24,3};
static const Keyword kwDsrl = {"dsrl",25,3};
static const Keyword kwMflo = {"mflo",26,1};
static const Keyword kwMfhi = {"mfhi",27,1};
static const Keyword kwMovn = {"movn",28,3};
static const Keyword kwMovz = {"movz",29,3};
//Ключевые слова - команды обмена с памятью
static const Keyword kwLB = {"lb",30,2};
static const Keyword kwLD = {"ld",31,2};
static const Keyword kwLH = {"lh",32,2};
static const Keyword kwLW = {"lw",33,2};
static const Keyword kwSB = {"sb",34,2};
static const Keyword kwSD = {"sd",35,2};
static const Keyword kwSH = {"sh",36,2};
static const Keyword kwSW = {"sw",37,2};
//Ключевые слова - команды переходов
static const Keyword kwJump = {"jump",40,1};
static const Keyword kwJeq = {"jeq",41,3};
static const Keyword kwJeqz = {"jeqz",42,2};
static const Keyword kwJgez = {"jgez",43,2};
static const Keyword kwJne = {"jne",44,3};
static const Keyword kwJnez = {"jnez",45,2};
static const Keyword kwJal = {"jal",46,1};
static const Keyword kwJ = {"j",47,1};

static const Keyword kwNop = {"nop",100,0};
static const Keyword kwErr = {"error",666,0};

enum typeinstr{arlog = 100, flcontr=200, ldstore=300, empty=400};
enum typeoper{rgister = 70, value = 80, adress = 90};
struct Operand{
    typeoper toperand;
    union OperandValue{
        long long value;
        int adress;
        Register* reg;
    }value;
};
struct DecodedInstruction{
    Keyword kword;
    typeinstr type;
    QList<Operand> operands;
    QString toString() const{
        QString str = "Keyword: " + kword.kword + " codeNumber: " + QString::number(kword.codeNumber);
        if(kword.codeNumber!=kwNop.codeNumber)
        {str +=" Operands: ";
        for(int i = 0; i< operands.length(); i++)
        {
            auto op = operands.at(i);
            str+= "oper" + QString::number(i);
            switch (op.toperand) {
            case typeoper::rgister:{
                str += " register: " + op.value.reg->toString();
                break;
            }
            case typeoper::value:{
                str+= " value: " + QString::number(op.value.value);
                break;
            }
            case typeoper::adress:{
                str+= " adress: " + QString::number(op.value.adress);
                break;
            }
            }
            str += " ; ";
        }
        }
        str+= "\\ \n";
        return str;
    }
};
#endif // KEYWORDS_H

#include "instruction.h"

Instruction::Instruction()
{

}

Instruction::Instruction(QString keyword, const QStringList &parameters)
{
    _keyword = findKeyword(keyword);
    _parameters = parameters;
}

Keyword Instruction::keyword() const
{
    return _keyword;
}

void Instruction::setKeyword(QString newKeyword)
{
    _keyword = findKeyword(newKeyword);
}

const QStringList &Instruction::parameters() const
{
    return _parameters;
}

void Instruction::setParameters(const QStringList &newParameters)
{
    _parameters = newParameters;
}

QString Instruction::toString()
{
    QString str = _keyword.kword;

    if(_parameters.length() > 0)
    {
        str+=" ";
        for(int i = 0; i< _parameters.length() - 1; i++)
        {
            str = str + _parameters[i] + ",";
        }
        str += _parameters.last();
    }
    return str;
}

bool Instruction::operator ==(Instruction instruction) const
{
    if(this->_keyword.codeNumber == instruction.keyword().codeNumber)
        return true;
    else
        return false;
}

Keyword Instruction::findKeyword(QString newKWord)
{
    if(kwAnd.kword == newKWord) return kwAnd;
    if(kwAdd.kword == newKWord) return kwAdd;
    if(kwDAdd.kword == newKWord) return kwDAdd;
    if(kwSub.kword == newKWord) return kwSub;
    if(kwDSub.kword == newKWord) return kwDSub;
    if(kwDiv.kword == newKWord) return kwDiv;
    if(kwDDiv.kword == newKWord) return kwDDiv;
    if(kwMult.kword == newKWord) return kwMult;
    if(kwDMult.kword == newKWord) return kwDMult;
    if(kwOr.kword == newKWord) return kwOr;
    if(kwXor.kword == newKWord) return kwXor;
    if(kwNot.kword == newKWord) return kwNot;
    if(kwSll.kword == newKWord) return kwSll;
    if(kwDSll.kword == newKWord) return kwDSll;
    if(kwSrl.kword == newKWord) return kwSrl;
    if(kwDsrl.kword == newKWord) return kwDsrl;
    if(kwMflo.kword == newKWord) return kwMflo;
    if(kwMfhi.kword == newKWord) return kwMfhi;
    if(kwMovn.kword == newKWord) return kwMovn;
    if(kwMovz.kword == newKWord) return kwMovz;
    if(kwLB.kword == newKWord) return kwLB;
    if(kwLD.kword == newKWord) return kwLD;
    if(kwLH.kword == newKWord) return kwLH;
    if(kwLW.kword == newKWord) return kwLW;
    if(kwSB.kword == newKWord) return kwSB;
    if(kwSD.kword == newKWord) return kwSD;
    if(kwSH.kword == newKWord) return kwSH;
    if(kwSW.kword == newKWord) return kwSW;
    if(kwJump.kword == newKWord) return kwJump;
    if(kwJeq.kword == newKWord) return kwJeq;
    if(kwJeqz.kword == newKWord) return kwJeqz;
    if(kwJgez.kword == newKWord) return kwJgez;
    if(kwJne.kword == newKWord) return kwJne;
    if(kwJnez.kword == newKWord) return kwJnez;
    if(kwJal.kword == newKWord) return kwJal;
    if(kwJ.kword == newKWord) return kwJ;
    if(kwNop.kword == newKWord) return kwNop;
    return kwErr;
}


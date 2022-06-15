#include "proccessor.h"
#include "arithmeticlogicunit.h"
#include "flowcontrolunit.h"
#include "readstoreunit.h"
Proccessor::Proccessor()
{
    _currentFetchComand = nullptr;
    _currentDecodeComand = nullptr;
    _currentExecuteComand = nullptr;
}

Proccessor::Proccessor(const RegisterBlock &registerBlock, const QList<Data> &dataCache, const QList<Comand> &comandCachce, Comand *currentFetchComand, Comand *currentDecodeComand, Comand *currentExecuteComand, const QList<ExecuteModule *> &executeModuleList) : _registerBlock(registerBlock),
    _dataCache(dataCache),
    _comandCachce(comandCachce),
    _currentFetchComand(currentFetchComand),
    _currentDecodeComand(currentDecodeComand),
    _currentExecuteComand(currentExecuteComand),
    _executeModuleList(executeModuleList)
{}

RegisterBlock Proccessor::registerBlock() const
{
    return _registerBlock;
}

void Proccessor::setRegisterBlock(RegisterBlock newRegisterBlock)
{
    _registerBlock = newRegisterBlock;
}


const QList<Comand> &Proccessor::comandCahce() const
{
    return _comandCachce;
}

void Proccessor::setComandCahce(const QList<Comand> &newComandCahce)
{
    _comandCachce = newComandCahce;
}
/*
Comand *Proccessor::currentComand() const
{
    return _currentComand;
}
*/
/*void Proccessor::setCurrentComand(Comand *newCurrentComand)
{
    _currentComand = newCurrentComand;
}
*/
void Proccessor::update()
{
    for(int i = 0; i < _listeners.length();i++)
    {
        _listeners[i]->updateInfo(this->toProcessorInfo());
    }
}

QStringList Proccessor::toString()
{
    QStringList list;
    list.append(_registerBlock.toString());
    QStringList dataString;
    for(auto data:_dataCache)
    {
        dataString.append(data.toString());
    }
    list.append(dataString);
    QStringList comandList;
    for(int i = 0; i < _comandCachce.length(); i++)
    {
        comandList.append(_comandCachce[i].toString());
    }
    list.append(comandList);
    if(_currentFetchComand!= nullptr)list.append(currentFetchComand()->toString());
    if(_currentDecodeComand!= nullptr)list.append(currentDecodeComand()->toString());
    if(_currentExecuteComand!= nullptr)list.append(currentExecuteComand()->toString());
    return list;
}


void Proccessor::doContiniousExecution()
{
    Comand cmd;
    Instruction inst;
    inst.setKeyword("nop");
    QList<Instruction> list;
    list.append(inst);
    list.append(inst);
    list.append(inst);
    cmd.setInstructions(list);
    while(!(*_currentExecuteComand == cmd))
    {
        tick();
    }
}

Memento* Proccessor::doStep()
{
    qDebug() << "Делаем cнимок";
    Snapshot* snp = new Snapshot(this, _registerBlock, _dataCache, _comandCachce,
                                 _currentFetchComand, _currentDecodeComand, _currentExecuteComand);
    qDebug() << "Снимок создан";
    tick();
    return snp;
}


void Proccessor::init(QList<Comand> lstComand, QList<Data> lstMemory)
{
    _comandCachce = lstComand;
    _dataCache = lstMemory;
    qDebug() << "Память в процессоре";
    for(auto str : _dataCache)
    {
        qDebug() << str.toString();
    }
    qDebug() << "Команды в процессоре";
    for(int i = 0;i < _comandCachce.length();i++)
    {
        qDebug() << _comandCachce.value(i).toString();
    }
    update();
}

const QList<Data> &Proccessor::dataCache() const
{
    return _dataCache;
}

void Proccessor::setDataCache(const QList<Data> &newDataCache)
{
    _dataCache = newDataCache;
}

Comand *Proccessor::currentDecodeComand() const
{
    return _currentDecodeComand;
}

void Proccessor::setCurrentDecodeComand(Comand *newCurrentDecodeComand)
{
    _currentDecodeComand = newCurrentDecodeComand;
}

Comand *Proccessor::currentExecuteComand() const
{
    return _currentExecuteComand;
}

void Proccessor::setCurrentExecuteComand(Comand *newCurrentExecuteComand)
{
    _currentExecuteComand = newCurrentExecuteComand;
}

Comand *Proccessor::currentFetchComand() const
{
    return _currentFetchComand;
}

void Proccessor::setCurrentFetchComand(Comand *newCurrentFetchComand)
{
    _currentFetchComand = newCurrentFetchComand;
}

void Proccessor::tick()
{
    chooseComand();
    auto dc = decodeComand();
    for(int i = 0; i < dc.length(); i++)
    {
        qDebug() << dc.at(i).toString();
    }
    executeComand(dc);
    update();
}

void Proccessor::chooseComand()
{
    int ic = _registerBlock.IC().getDoubleWord();
    _currentFetchComand = &(_comandCachce[ic]);
    qDebug() << "Текущая команда: " + _currentFetchComand->toString();
    ic++;
    if(ic>=_comandCachce.length())
    {
        ic = 0;
    }
    _registerBlock.IC().setDoubleWord(ic);
}

void Proccessor::executeComand(QList<DecodedInstruction> decodeComand)
{
    _currentExecuteComand = _currentDecodeComand;
    for(int i = 0; i< decodeComand.length(); i++)
    {
        ExecuteModule* execMod;
        switch (decodeComand.at(i).type) {
        case typeinstr::arlog : {execMod = new ArithmeticLogicUnit(); break;}
        case typeinstr::ldstore :{execMod = new ReadStoreUnit(); break;}
        case typeinstr::flcontr : {execMod = new FlowControlUnit(); break;}
        case typeinstr::empty:{execMod = nullptr; break;}
        }
        _executeModuleList.append(execMod);
    }
    for(int i = 0; i< decodeComand.length(); i++)
    {
        if(decodeComand.at(i).type!=typeinstr::empty)
        {
            _executeModuleList.at(i)->execute(decodeComand.at(i));
        }
    }
    _executeModuleList.clear();
}

QList<DecodedInstruction> Proccessor::decodeComand()
{
    _currentDecodeComand = _currentFetchComand;
    auto instruct =  _currentDecodeComand->instructions();
    QList<DecodedInstruction> decodInstructions;
    for(int i = 0; i<instruct.length(); i++)
    {
        DecodedInstruction decInsruct;
        decInsruct.kword = instruct.at(i).keyword();
        switch (decInsruct.kword.codeNumber) {
        case 10 ...29 : { decInsruct.type = typeinstr::arlog; break;};
        case 30 ...37:{decInsruct.type = typeinstr::ldstore; break;};
        case 40 ...47: {decInsruct.type = typeinstr::flcontr; break;}
        default: {decInsruct.type = typeinstr::empty; break;};
        }
        auto params = instruct.at(i).parameters();
        for(auto param: params)
        {
            Operand operand;
            if(param.length() > 1)
            {
                if(param.at(0) =='r'&&(param.at(1) >= '0'&& (param.at(1) <= '9')))
                {
                    operand.toperand = typeoper::rgister;
                    operand.value.reg = _registerBlock.getRegisterOnName(param);
                }
            else
            {
                if(param.at(0)>='0')
                {
                    if(param.at(1) == 'x')
                    {
                        operand.toperand = typeoper::value;
                        operand.value.value = param.section("", 2, param.length()).toInt();
                    }

                    else
                    {
                        if(param.at(0)<='9')
                        {
                           operand.toperand = typeoper::value;
                           operand.value.value = param.toInt();
                        }
                    }
                }
                else
                {
                     if(param.contains('('))
                     {
                        QString shift = param.section("",0,param.indexOf('('));
                        QString base = param.section("",param.indexOf('(')+2, param.indexOf(')'));
                        auto reg = _registerBlock.getRegisterOnName(base);
                        operand.toperand = typeoper::adress;
                        operand.value.adress = reg->getDoubleWord() + shift.toInt();
                     }
                     else
                     {
                        int adr = findAdressByLabel(param);
                        if(adr>=0)
                        {
                            operand.toperand = typeoper::adress;
                            operand.value.adress = adr;
                        }
                     }
                }
            }
            }
            else
            {
                if(param.at(0)<='9'&&param.at(0)>='0')
                {
                   operand.toperand = typeoper::value;
                   operand.value.value = param.toInt();
                }
                else
                {
                    int adr = findAdressByLabel(param);
                    if(adr>=0)
                    {
                        operand.toperand = typeoper::adress;
                        operand.value.adress = adr;
                    }
                }
            }
            decInsruct.operands.append(operand);
        }
        decodInstructions.append(decInsruct);
    }
    return decodInstructions;
}

int Proccessor::findAdressByLabel(QString label)
{
    for(int i = 0; i<_dataCache.length();i++)
    {
        if(_dataCache.at(i).label()==label)
            return i;
    }
    for(int i = 0; i<_comandCachce.length();i++)
    {
        if(_comandCachce.at(i).label()== label)
            return i;
    }
    return -1;
}

ProcessorInfo Proccessor::toProcessorInfo()
{
    ProcessorInfo procInfo;
    procInfo.registerInfo = _registerBlock.toString();
    QStringList dataString;
    for(auto data:_dataCache)
    {
        dataString.append(data.toString());
    }
    procInfo.dataInfo = dataString;
    QStringList comandList;
    for(int i = 0; i < _comandCachce.length(); i++)
    {
        comandList.append(_comandCachce[i].toString());
    }
    procInfo.comandInfo = comandList;
    procInfo.currentFetchComandInfo = (_currentFetchComand!=nullptr)? _currentFetchComand->toString(): "";
    procInfo.currentDecodeComandInfo = (_currentFetchComand!=nullptr)? _currentDecodeComand->toString(): "";
    procInfo.currentExecuteComandInfo = (_currentFetchComand!=nullptr)? _currentExecuteComand->toString(): "";
    return procInfo;
}

Proccessor::Snapshot::Snapshot(Proccessor *proccessor, const RegisterBlock &registerBlck, const QList<Data> &dataCh, const QList<Comand> &comandCh, Comand *currFetchComand, Comand *currDecodeComand, Comand *currExecuteComand) : proccessor(proccessor),
    _registerBlck(registerBlck),
    _dataCh(dataCh),
    _comandCh(comandCh),
    currFetchComand(currFetchComand),
    currDecodeComand(currDecodeComand),
    currExecuteComand(currExecuteComand)
{}


void Proccessor::Snapshot::restore()
{
    qDebug() << "Восстанавливаем";
    proccessor->setRegisterBlock(_registerBlck);
    proccessor->setDataCache(_dataCh);
    proccessor->setComandCahce(_comandCh);
    proccessor->setCurrentFetchComand(currFetchComand);
    proccessor->setCurrentDecodeComand(currDecodeComand);
    proccessor->setCurrentExecuteComand(currExecuteComand);
}



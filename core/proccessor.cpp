#include "proccessor.h"

Proccessor::Proccessor()
{

}

Proccessor::Proccessor(RegisterBlock *registerBlock, const QList<Data> &dataCache, const QList<Comand> &comandCahce, Comand *currentComand) : _registerBlock(registerBlock),
    _dataCache(dataCache),
    _comandCachce(comandCahce),
    _currentComand(currentComand)
{}

RegisterBlock *Proccessor::registerBlock() const
{
    return _registerBlock;
}

void Proccessor::setRegisterBlock(RegisterBlock *newRegisterBlock)
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

Comand *Proccessor::currentComand() const
{
    return _currentComand;
}

void Proccessor::setCurrentComand(Comand *newCurrentComand)
{
    _currentComand = newCurrentComand;
}

void Proccessor::update()
{
    for(int i = 0; i < _listeners.length();i++)
    {
        _listeners[i]->updateInfo(this->toString());
    }
}

QStringList Proccessor::toString()
{
    QStringList list;
    list.append(_registerBlock->toString());
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
    list.append(currentComand()->toString());
    return list;
}


void Proccessor::doContiniousExecution()
{
}

void Proccessor::doStep()
{
}

void Proccessor::doStepBack()
{
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
    for(auto cmd : _comandCachce)
    {
        qDebug() << cmd.toString();
    }
}

const QList<Data> &Proccessor::dataCache() const
{
    return _dataCache;
}

void Proccessor::setDataCache(const QList<Data> &newDataCache)
{
    _dataCache = newDataCache;
}

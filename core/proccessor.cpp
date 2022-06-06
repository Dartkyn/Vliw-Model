#include "proccessor.h"

Proccessor::Proccessor()
{

}

Proccessor::Proccessor(RegisterBlock *registerBlock, const QStringList &dataCache, const QList<Comand> &comandCahce, Comand *currentComand) : _registerBlock(registerBlock),
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

const QStringList &Proccessor::dataCache() const
{
    return _dataCache;
}

void Proccessor::setDataCache(const QStringList &newDataCache)
{
    _dataCache = newDataCache;
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
    list.append(_dataCache);
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

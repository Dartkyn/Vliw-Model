#ifndef PROCCESSOR_H
#define PROCCESSOR_H
#include "registerblock.h"
#include "comand.h"
#include "core.h"
class Proccessor : public Core
{
public:
    Proccessor();
    Proccessor(RegisterBlock *registerBlock, const QStringList &dataCache, const QList<Comand> &comandCahce, Comand *currentComand);
    RegisterBlock *registerBlock() const;
    void setRegisterBlock(RegisterBlock *newRegisterBlock);

    const QStringList &dataCache() const;
    void setDataCache(const QStringList &newDataCache);

    const QList<Comand> &comandCahce() const;
    void setComandCahce(const QList<Comand> &newComandCahce);

    Comand *currentComand() const;
    void setCurrentComand(Comand *newCurrentComand);
    //
    void update();
    QStringList toString();

    void doContiniousExecution();
    void doStep();
    void doStepBack();



private:
    /*! Свойство, хранящее указатель на блок регистров */
    RegisterBlock *_registerBlock;
    /*! Свойство, хранящее кеш данные, содержащий строки данных */
    QStringList _dataCache;
    /*! Свойство, список команд */
    QList<Comand> _comandCachce;
    /*! Свойство, хранящее указатель на текущую исполняемую команду */
    Comand *_currentComand;
    void tick();
    Comand chooseComand(int IC);
    void decodeComand();
};

#endif // PROCCESSOR_H

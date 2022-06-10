#ifndef PROCCESSOR_H
#define PROCCESSOR_H
#include "registerblock.h"
#include "comand.h"
#include "core.h"
#include "data.h"
class Proccessor : public Core
{
public:
    Proccessor();
    Proccessor(RegisterBlock registerBlock, const QList<Data> &dataCache, const QList<Comand> &comandCahce, Comand *currentComand);
    RegisterBlock registerBlock() const;
    void setRegisterBlock(RegisterBlock newRegisterBlock);

    const QList<Comand> &comandCahce() const;
    void setComandCahce(const QList<Comand> &newComandCahce);

    Comand *currentComand() const;
    void setCurrentComand(Comand *newCurrentComand);
    //
    void update();
    QStringList toString();

    void doContiniousExecution();
    Memento* doStep();
    void init(QList<Comand> lstComand, QList<Data> lstMemory);


    const QList<Data> &dataCache() const;
    void setDataCache(const QList<Data> &newDataCache);

private:
    /*! Свойство, хранящее указатель на блок регистров */
    RegisterBlock _registerBlock;
    /*! Свойство, хранящее кеш данные, содержащий строки данных */
    QList<Data> _dataCache;
    /*! Свойство, список команд */
    QList<Comand> _comandCachce;
    /*! Свойство, хранящее указатель на текущую исполняемую команду */
    Comand *_currentComand;
    void tick();
    Comand chooseComand(int IC);
    void decodeComand();
    //TODO Перенести в отдельный класс
public:
    class Snapshot:public Memento
    {
    public:
        Snapshot();
        Snapshot(Proccessor *proccessor, const RegisterBlock &registerBlck, const QList<Data> &dataCh, const QList<Comand> &comandCh, Comand *currComand);
        //void getSnapshot();
        void restore();
    private:
        Proccessor *proccessor;
        RegisterBlock _registerBlck;
        QList<Data> _dataCh;
        QList<Comand> _comandCh;
        Comand *currComand;};
};

#endif // PROCCESSOR_H

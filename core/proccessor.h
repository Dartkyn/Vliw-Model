#ifndef PROCCESSOR_H
#define PROCCESSOR_H
#include "registerblock.h"
#include "comand.h"
#include "core.h"
#include "data.h"
#include "ExecuteModul.h"

class Proccessor : public Core
{
public:
    Proccessor();
    Proccessor(RegisterBlock registerBlock, const QList<Data> &dataCache, const QList<Comand> &comandCahce, Comand *currentComand);
    Proccessor(const RegisterBlock &registerBlock, const QList<Data> &dataCache, const QList<Comand> &comandCachce, Comand *currentFetchComand, Comand *currentDecodeComand, Comand *currentExecuteComand, const QList<ExecuteModule *> &executeModuleList);
    RegisterBlock registerBlock() const;
    void setRegisterBlock(RegisterBlock newRegisterBlock);

    const QList<Comand> &comandCahce() const;
    void setComandCahce(const QList<Comand> &newComandCahce);

    //Comand *currentComand() const;
    //void setCurrentComand(Comand *newCurrentComand);
    //
    void update();
    QStringList toString();

    void doContiniousExecution();
    Memento* doStep();
    void init(QList<Comand> lstComand, QList<Data> lstMemory);


    const QList<Data> &dataCache() const;
    void setDataCache(const QList<Data> &newDataCache);
    Comand *currentFetchComand() const;
    void setCurrentFetchComand(Comand *newCurrentFetchComand);
    Comand *currentDecodeComand() const;
    void setCurrentDecodeComand(Comand *newCurrentDecodeComand);
    Comand *currentExecuteComand() const;
    void setCurrentExecuteComand(Comand *newCurrentExecuteComand);
private:
    /*! Свойство, хранящее указатель на блок регистров */
    RegisterBlock _registerBlock;
    /*! Свойство, хранящее кеш данные, содержащий строки данных */
    QList<Data> _dataCache;
    /*! Свойство, список команд */
    QList<Comand> _comandCachce;
    /*! Свойство, хранящее указатель на текущую исполняемую команду */
    Comand *_currentFetchComand;
    Comand *_currentDecodeComand;
    Comand *_currentExecuteComand;
    QList<ExecuteModule*> _executeModuleList;
    void tick();
    void chooseComand();
    void executeComand(QList<DecodedInstruction> decodeComand);
    QList<DecodedInstruction> decodeComand();
    int findAdressByLabel(QString label);
    ProcessorInfo toProcessorInfo();
public:
    class Snapshot:public Memento
    {
    public:
        Snapshot();
        Snapshot(Proccessor *proccessor, const RegisterBlock &registerBlck, const QList<Data> &dataCh, const QList<Comand> &comandCh, Comand *currComand);
        Snapshot(Proccessor *proccessor, const RegisterBlock &registerBlck, const QList<Data> &dataCh, const QList<Comand> &comandCh, Comand *currFetchComand, Comand *currDecodeComand, Comand *currExecuteComand);
        //void getSnapshot();
        void restore();
    private:
        Proccessor *proccessor;
        RegisterBlock _registerBlck;
        QList<Data> _dataCh;
        QList<Comand> _comandCh;
        Comand *currFetchComand;
        Comand *currDecodeComand;
        Comand *currExecuteComand;
    };

};

#endif // PROCCESSOR_H

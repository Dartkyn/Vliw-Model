#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "QFile"
#include "QDebug"
#include "QDir"
#include "QByteArray"
#include "parser.h"
#include "core/memento.h"
class Core;
/*! Класс, отвечающий за получение команд от GUI и передача ее классам ядра*/
class Controller
{
public:
    void createNewFile();
    QByteArray openFile(QString pathToFile);
    void saveFile(QByteArray fileContets);
    int parseFile();
    /*! Метод, отвечающий за сборку  исходного кода*/
    int build();
    Controller();
    void attachCore(Core* core);
    ~Controller();
    void doStep();
    void doStepBack();
    void doContiniousExecute();
private:
     /*! */
    Parser *_parser;
    /*! */
    Core *_core;
    /*! Свойстово хранящее экземпляр открытого файла*/
    QFile _currentOpenedFile;
    /*! Свойстово отвечающее за хранение содержиого файла*/
    QByteArray _contentFile;
    std::vector<Memento*> _history;
    bool _isRunning = false;
};

#endif // CONTROLLER_H

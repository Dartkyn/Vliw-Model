#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "QFile"
#include "QDebug"
#include "QDir"
#include "QByteArray"
#include "parser.h"

class Core;
class Controller
{
public:
    void createNewFile();
    QByteArray openFile(QString pathToFile);
    void saveFile(QByteArray fileContets);
    void parseFile();
    /*! Метод, отвечающий за запуск исходного кода, если isStepRun=true - запуск в пошаговом режиме*/
    void build(bool isStepRun);
    Controller();
    void attachCore(Core* core);
    ~Controller();

private:
     /*! */
    Parser *_parser;
    /*! */
    Core *_core;
    /*! Свойстово хранящее экземпляр открытого файла*/
    QFile _currentOpenedFile;
    /*! Свойстово отвечающее за хранение содержиого файла*/
    QByteArray _contentFile;

    void doContiniousExecute();
    void doStep();
    void doStepBack();
};

#endif // CONTROLLER_H

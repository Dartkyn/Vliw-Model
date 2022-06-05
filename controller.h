#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "parser.h"
#include "QDebug"
#include "QFile"
#include "QDir"
#include "QByteArray"
class Core;
class Controller
{
public:
    // TODO Остатки от синглтона, не забыть удалить
    //Controller *instance() const;
    //GUI *gui() const;
    //void setGui(GUI *newGui);
    void createNewFile();
    QByteArray openFile(QString pathToFile);
    void saveFile(QString fileContets);
    void parseFile();
    void build(bool isStepRun);
    void doContiniousExecute();
    void doStep();
    void doStepBack();
    Controller();
    void attachCore(Core* core);
    ~Controller();

private:
    //static Controller* _instance;
    //GUI *_gui;
    Parser *_parser;
    Core *_core;
    QFile *_currentOpenedFile;
};

#endif // CONTROLLER_H

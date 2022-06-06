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
    // TODO Остатки от синглтона, не забыть удалить
    //Controller *instance() const;
    //GUI *gui() const;
    //void setGui(GUI *newGui);
    void createNewFile();
    QByteArray openFile(QString pathToFile);
    void saveFile(QString fileContets);
    void parseFile();
    void build(bool isStepRun);
    Controller();
    void attachCore(Core* core);
    ~Controller();

private:
    //static Controller* _instance;
    //GUI *_gui;
    Parser *_parser = nullptr;
    Core *_core = nullptr;
    QFile _currentOpenedFile;
    QByteArray _contentFile;

    void doContiniousExecute();
    void doStep();
    void doStepBack();
};

#endif // CONTROLLER_H

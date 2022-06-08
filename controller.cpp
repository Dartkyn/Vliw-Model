#include "controller.h"
#include "core/core.h"
void Controller::createNewFile()
{

    QString str = QDir::currentPath() + "/temp.dat";
    qDebug() << str;
    _currentOpenedFile.setFileName(str);
    _currentOpenedFile.open(QIODevice::ReadWrite);
    qDebug() << _currentOpenedFile.fileName();
}

QByteArray Controller::openFile(QString pathToFile)
{
    qDebug() << pathToFile;
    try {
         qDebug() << "Create Pointer";
         if(QFile::exists(pathToFile))
         {
             qDebug() << "Файл существует";
            _currentOpenedFile.setFileName(pathToFile);
             qDebug() << "File create";
            _currentOpenedFile.open(QIODevice::ReadWrite);
             _contentFile = _currentOpenedFile.readAll();
            qDebug() << _contentFile;
            return _contentFile;
         }
    }  catch (std::exception& e) {
        qDebug() << QString(e.what());
    }
    return "";
}

void Controller::saveFile(QByteArray fileContets)
{
    qDebug() << fileContets;
    _currentOpenedFile.write(fileContets);
}

void Controller::parseFile()
{
    QString str = QString(_contentFile);
    str.replace("\n\n","");
    qDebug() << str;
    _parser->parseString(str.split("\n"));
}

void Controller::build(bool isStepRun)
{
    parseFile();
    _core->init(_parser->getComandList(), _parser->getDataStrings());
    if(isStepRun == true)
    {
       doStep();
    }
    else
    {
        doContiniousExecute();
    }
}

void Controller::doContiniousExecute()
{
    
}

void Controller::doStep()
{
    
}

void Controller::doStepBack()
{
    
}
Controller::Controller()
{
    _parser = new Parser();
}

void Controller::attachCore(Core *core)
{
    _core = core;
}

Controller::~Controller()
{
    _currentOpenedFile.close();
}

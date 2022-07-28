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
            _currentOpenedFile.open(QIODevice::ReadOnly);
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
    qDebug() << "Сохраняем файл";
    qDebug() << fileContets;
    _currentOpenedFile.close();
    _currentOpenedFile.open(QIODevice::WriteOnly);
    _currentOpenedFile.write(fileContets);
    _currentOpenedFile.flush();
    _contentFile = fileContets;
}

int Controller::parseFile()
{
    QString str = QString(_contentFile);
    str.replace("\n\n","");
    qDebug() << str;
    if(_parser->parseString(str.split("\n"))==0)
        return 0;
    else
        return -1;
}

int Controller::build()
{
    if(parseFile()==0)
    {
        _core->init(_parser->getComandList(), _parser->getDataStrings());
        return 0;
    }
    else
        return -1;
}

void Controller::doContiniousExecute()
{
    _core->doContiniousExecution();
}

void Controller::doStep()
{
   _history.push_back(_core->doStep());
}

void Controller::doStepBack()
{
    Memento* mem = _history.back();
    mem->restore();
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

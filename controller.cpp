#include "controller.h"

/*Controller* Controller::_instance = nullptr;
Controller *Controller::instance() const
{
    if(_instance == nullptr)
    {
        _instance = new Controller();
    }
    return _instance;
}
*/

/*GUI *Controller::gui() const
{
    return _gui;
}

void Controller::setGui(GUI *newGui)
{
    _gui = newGui;
}*/
void Controller::createNewFile()
{
    /* TODO  Не создается файл, крашит программу, разобраться
    QString str = QDir::currentPath() + "//temp.dat";
    qDebug() << str;
    _currentOpenedFile = new QFile(str);
    if(_currentOpenedFile->exists())
    {
        _currentOpenedFile->open(QIODevice::ReadWrite);
    }
    qDebug() << _currentOpenedFile->fileName();
    */
}

QByteArray Controller::openFile(QString pathToFile)
{
    qDebug() << pathToFile;
    try {
         qDebug() << "Create Pointer";
         if(QFile::exists(pathToFile))
         {
             qDebug() << "Файл существует";
            _currentOpenedFile = new QFile(pathToFile);
             qDebug() << "File create";
            _currentOpenedFile->open(QIODevice::ReadWrite);
            QByteArray fileArray = _currentOpenedFile->readAll();
            qDebug() << fileArray;
            return fileArray;
         }
    }  catch (std::exception& e) {
        qDebug() << QString(e.what());
    }
    return "";

}

void Controller::saveFile(QString fileContets)
{
    qDebug() << fileContets;
    _currentOpenedFile->write(fileContets.toUtf8());
}

void Controller::parseFile()
{
    //_parser->parseString();
}

void Controller::build(bool isStepRun)
{
    parseFile();
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
    _currentOpenedFile->close();
    delete _currentOpenedFile;
}

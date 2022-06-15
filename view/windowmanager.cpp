#include "windowmanager.h"

using namespace std;

WindowManager* WindowManager::_instance = nullptr;
WindowManager::WindowManager()
{
    _processorInfo.registerInfo = {""};
    _processorInfo.dataInfo = {""};
    _processorInfo.comandInfo = {""};
    _processorInfo.currentFetchComandInfo = "";
    _processorInfo.currentDecodeComandInfo = "";
    _processorInfo.currentExecuteComandInfo = "";
    _enterWindow = new MainWindow();
    _currentOpenedWindow = dynamic_cast<QMainWindow*>(_enterWindow);
    _workWindow = new WorkWindow();
    _registerWindow = new RegisterMainForm();
    _memoryWindow = new MemoryMainWindow();
}

WindowManager::WindowManager(MainWindow *enterWindow, QMainWindow *currentOpenedWindow, WorkWindow *workWindow, RegisterMainForm *registerWindow, MemoryMainWindow *memoryWindow) : _enterWindow(enterWindow),
    _currentOpenedWindow(currentOpenedWindow),
    _workWindow(workWindow),
    _registerWindow(registerWindow),
    _memoryWindow(memoryWindow)
{}

void WindowManager::openWindow(QMainWindow *wd)
{
    wd->show();
}

void WindowManager::openCurrentWindow()
{
    _currentOpenedWindow->show();
}

MainWindow *WindowManager::enterWindow() const
{
    return _enterWindow;
}

void WindowManager::setEnterWindow(MainWindow *newEnterWindow)
{
    _enterWindow = newEnterWindow;
}

QMainWindow *WindowManager::currentOpenedWindow() const
{
    return _currentOpenedWindow;
}

void WindowManager::setCurrentOpenedWindow(QMainWindow *newCurrentOpenedWindow)
{
    _currentOpenedWindow = newCurrentOpenedWindow;
}

WorkWindow *WindowManager::workWindow() const
{
    return _workWindow;
}

void WindowManager::setWorkWindow(WorkWindow *newWorkWindow)
{
    _workWindow = newWorkWindow;
}

RegisterMainForm *WindowManager::registerWindow() const
{
    return _registerWindow;
}

void WindowManager::setRegisterWindow(RegisterMainForm *newRegisterWindow)
{
    _registerWindow = newRegisterWindow;
}

MemoryMainWindow *WindowManager::memoryWindow() const
{
    return _memoryWindow;
}

void WindowManager::setMemoryWindow(MemoryMainWindow *newMemoryWindow)
{
    _memoryWindow = newMemoryWindow;
}

WindowManager *WindowManager::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new WindowManager();
    }
    return _instance;
}

const ProcessorInfo &WindowManager::processorInfo() const
{
    return _processorInfo;
}

void WindowManager::setProcessorInfo(const ProcessorInfo &newProcessorInfo)
{
    _processorInfo = newProcessorInfo;
}

void WindowManager::updateInfo(ProcessorInfo coreInfo)
{
    _processorInfo.registerInfo = coreInfo.registerInfo;
    _processorInfo.dataInfo = coreInfo.dataInfo;
    _processorInfo.comandInfo = coreInfo.comandInfo;
    _processorInfo.currentFetchComandInfo = coreInfo.currentFetchComandInfo;
    _processorInfo.currentDecodeComandInfo = coreInfo.currentDecodeComandInfo;
    _processorInfo.currentExecuteComandInfo = coreInfo.currentExecuteComandInfo;
    _workWindow->init();
}

const QStringList &WindowManager::recentFiles() const
{
    return _recentFiles;
}

void WindowManager::setRecentFiles(const QStringList &newRecentFiles)
{
    _recentFiles = newRecentFiles;
}

void WindowManager::runFile()
{
    _controller->build();
    _isRunning = true;
    _controller->doContiniousExecute();
    _isRunning = false;
}

void WindowManager::runStepFile()
{
    if(!_isRunning)
    {
        _controller->build();
        _isRunning = true;
        _controller->doStep();
    }
    else
    {
        _controller->doStep();
    }
}

void WindowManager::stepBack()
{
    _controller->doStepBack();
}

void WindowManager::saveFile(QByteArray fileContent)
{
    if(!_isRunning)
    {
        _controller->saveFile(fileContent);
    }
}

void WindowManager::openFile(QString filePath)
{
    QByteArray byteArray = _controller->openFile(filePath);

    _recentFiles.append(filePath);
    _workWindow->loadCodeFile(byteArray);
    if(_currentOpenedWindow == _enterWindow)
    {
        _currentOpenedWindow = _workWindow;
        _workWindow->init();
        openCurrentWindow();
    }

}

void WindowManager::createFile()
{
    _controller->createNewFile();
    if(_currentOpenedWindow == _enterWindow)
    {
        _currentOpenedWindow = _workWindow;
        _workWindow->init();
        openCurrentWindow();
    }
}



#include "windowmanager.h"
using namespace std;

WindowManager* WindowManager::_instance = nullptr;
WindowManager::WindowManager()
{
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

void WindowManager::OpenCurrentWindow()
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

void WindowManager::updateInfo(QStringList coreInfo)
{
    _processorInfo.registerInfo = QStringList(coreInfo.at(0));
    _processorInfo.dataInfo = QStringList(coreInfo.at(1));
    _processorInfo.comandInfo = QStringList(coreInfo.at(2));
    _processorInfo.currentComandInfo = coreInfo.at(3);
}



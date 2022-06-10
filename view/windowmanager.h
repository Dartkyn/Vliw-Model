#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <QMainWindow>
#include <QWidget>
#include "mainwindow.h"
#include "workwindow.h"
#include "memorymainwindow.h"
#include "registermainform.h"
#include "gui.h"
class WindowManager : public GUI
{
public:
    void openWindow(QMainWindow* wd);
    void openCurrentWindow();
    MainWindow *enterWindow() const;
    void setEnterWindow(MainWindow *newEnterWindow);

    QMainWindow *currentOpenedWindow() const;
    void setCurrentOpenedWindow(QMainWindow *newCurrentOpenedWindow);

    WorkWindow *workWindow() const;
    void setWorkWindow(WorkWindow *newWorkWindow);

    RegisterMainForm *registerWindow() const;
    void setRegisterWindow(RegisterMainForm *newRegisterWindow);

    MemoryMainWindow *memoryWindow() const;
    void setMemoryWindow(MemoryMainWindow *newMemoryWindow);

    static WindowManager *getInstance();


    const ProcessorInfo &processorInfo() const;
    void setProcessorInfo(const ProcessorInfo &newProcessorInfo);

    void updateInfo(QStringList coreInfo);
    const QStringList &recentFiles() const;
    void setRecentFiles(const QStringList &newRecentFiles);
    void openFile(QString filePath);
    void createFile();
    void runFile();
    void runStepFile();
    void stepBack();
    void saveFile(QByteArray fileContent);
private:
    static WindowManager* _instance;
    /*!Начальная форма, открываемая при запуске программы */
    MainWindow* _enterWindow;
    /*!Указатель на текущую открытую форму */
    QMainWindow* _currentOpenedWindow;
    /*!Основная рабочая форма*/
    WorkWindow* _workWindow;
    /*!Форма, предназначенная для вывода регистров */
    RegisterMainForm* _registerWindow;
    /*!Форма, предназначенная для вывода содержимого памяти */
    MemoryMainWindow* _memoryWindow;
    /*!QList<QMainWindow*> WindowList; */
    QStringList _recentFiles;
    bool _isRunning = false;
    WindowManager();
    WindowManager(MainWindow *enterWindow, QMainWindow *currentOpenedWindow, WorkWindow *workWindow, RegisterMainForm *registerWindow, MemoryMainWindow *memoryWindow);

};

#endif // WINDOWMANAGER_H

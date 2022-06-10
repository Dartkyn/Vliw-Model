#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include "mainwindow.h"
#include "ui_workwindow.h"
#include "codeeditor.h"
#include "pipelineitem.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QIcon>
#include <QHeaderView>
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>

class WindowManager;
using namespace std;
namespace Ui {
class WorkWindow;
}

class WorkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkWindow(QWidget *parent = nullptr);
    ~WorkWindow();
    void loadCodeFile(QByteArray fileArray);
private slots:
    void on_showHideRegisters_toggled(bool arg1);

    void on_showHideMemory_toggled(bool arg1);

    void on_showHidePipelines_toggled(bool arg1);

    void on_openRegisterForm_triggered();

    void on_openMemoryForm_triggered();

    void on_runMenuItem_triggered();

    void on_runStepMenuItem_triggered();

    void on_runFileToolBarItem_triggered();

    void on_runStepToolBarItem_triggered();

    void on_actionrunStepBackToolBarItem_triggered();

    void on_saveFileToolBarItem_triggered();

private:
    void drawItems();
    void registerTableInitiate();
    void memoryTableInitiate();
    void runFile();
    void runStepFile();
    void runStepBack();
    void saveFile();
private:
    Ui::WorkWindow *ui;
    QWidget* codeEditor;
};

#endif // WORKWINDOW_H

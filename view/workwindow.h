#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include <QMainWindow>
#include "registermainform.h"
#include "memorymainwindow.h"

namespace Ui {
class WorkWindow;
}

class WorkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkWindow(QWidget *parent = nullptr);
    ~WorkWindow();

private slots:
    void on_showHideRegisters_toggled(bool arg1);

    void on_showHideMemory_toggled(bool arg1);

    void on_showHidePipelines_toggled(bool arg1);

    void on_openRegisterForm_triggered();

    void on_openMemoryForm_triggered();

private:
    void DrawItems();
    void ToolBarInitiate();
    void registerTableInitiate();
    void memoryTableInitiate();
    void loadCodeFile(QString pathToFile);
private:
    Ui::WorkWindow *ui;
    RegisterMainForm regForm;
    MemoryMainWindow memForm;
    QWidget* codeEditor;
};

#endif // WORKWINDOW_H

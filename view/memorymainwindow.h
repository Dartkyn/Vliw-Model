#ifndef MEMORYMAINWINDOW_H
#define MEMORYMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MemoryMainWindow;
}

class MemoryMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MemoryMainWindow(QWidget *parent = nullptr);
    ~MemoryMainWindow();
    void init();

private:
    Ui::MemoryMainWindow *ui;
    void memoryTableInitiate();
};

#endif // MEMORYMAINWINDOW_H

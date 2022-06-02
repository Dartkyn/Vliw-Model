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

private:
    void memoryTableInitiate();
    Ui::MemoryMainWindow *ui;
};

#endif // MEMORYMAINWINDOW_H

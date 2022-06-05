#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>
#include <QFileDialog>
#include "QtDebug"
#include "windowmanager.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->setupUi(this);
    QStringList mod;
    mod.append("C:\\MyFiles\\Projects\\file1.dat");
    mod.append("C:\\MyFiles\\Projects\\file2.dat");
    mod.append("C:\\MyFiles\\Projects\\file3.dat");
    QStringListModel* model = new QStringListModel();
    model->setStringList(mod);
    ui->recentFilesListView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFilePushButton_clicked()
{
    QFileDialog fileDlg;
    QString filePath = fileDlg.getOpenFileName(this, tr("Открыть файл"),
                            "/",
                            tr("Файлы (*.txt *.dat)"));
    if(filePath.capacity() != 0)
    {
        WindowManager::getInstance()->OpenFile(filePath);
        this->close();
    }
}


void MainWindow::on_newFilePushButton_clicked()
{
    qDebug() << "Hello from click";
    WindowManager::getInstance()->CreateFile();
    this->close();
}




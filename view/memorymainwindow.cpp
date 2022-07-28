#include "memorymainwindow.h"
#include "ui_memorymainwindow.h"
#include <QStandardItemModel>
#include "windowmanager.h"
MemoryMainWindow::MemoryMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MemoryMainWindow)
{
    ui->setupUi(this);
}

MemoryMainWindow::~MemoryMainWindow()
{
    delete ui;
}

void MemoryMainWindow::init()
{
    memoryTableInitiate();
}

void MemoryMainWindow::memoryTableInitiate()
{
    QStringList headerList;
    QStandardItemModel* model = new QStandardItemModel();
    headerList.append("Адрес");
    headerList.append("Метка");
    headerList.append("Данные в 10 с/с");
    headerList.append("Данные в 16 с/с");
    model->setHorizontalHeaderLabels(headerList);
    ui->memoryTableView->setModel(model);
    ui->memoryTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    QStringList str;
    str = WindowManager::getInstance()->processorInfo().dataInfo;
    for(int i = 0; i < str.length(); i++)
    {
        QStringList row = str.at(i).split("//");
        model->setItem(i,0, new QStandardItem(QString("0" + QString::number(i))));
        if(row.count() >2)
        {
            model->setItem(i,1, new QStandardItem(row.at(0)));
            long long value = row.at(2).toLongLong();
            model->setItem(i,2, new QStandardItem(QString::number(value)));
            model->setItem(i,3, new QStandardItem(QString::number(value,16)));
        }
        else
        {
            long long value = row.at(1).toLongLong();
            model->setItem(i,2, new QStandardItem(QString::number(value)));
            model->setItem(i,3, new QStandardItem(QString::number(value,16)));
        }

    }
}

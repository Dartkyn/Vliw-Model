#include "memorymainwindow.h"
#include "ui_memorymainwindow.h"
#include <QStandardItemModel>
MemoryMainWindow::MemoryMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MemoryMainWindow)
{
    ui->setupUi(this);
    memoryTableInitiate();
}

MemoryMainWindow::~MemoryMainWindow()
{
    delete ui;
}

void MemoryMainWindow::memoryTableInitiate()
{
    QStringList headerList;
    QStandardItemModel* model = new QStandardItemModel();
    headerList.append("Адресс");
    headerList.append("Данные в 10 с/с");
    headerList.append("Представление в 16 с/с");
    headerList.append("Ссылка");
    headerList.append("Комментарий");
    model->setHorizontalHeaderLabels(headerList);
    ui->memoryTableView->setModel(model);
    ui->memoryTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    int num;
    for(int i = 0; i < 32; i++)
    {
        num= rand()/(RAND_MAX/255);
        QStandardItem* item = new QStandardItem(QString("0" + QString::number(i)));
        model->setItem(i,0, item);
        model->setItem(i,1, new QStandardItem(QString::number(num)));
        model->setItem(i,2, new QStandardItem(QString::number(model->item(i,1)->text().toInt(),16).toUpper()));
        model->setItem(i,3, new QStandardItem(QString("$a" + QString::number(i))));
    }
}

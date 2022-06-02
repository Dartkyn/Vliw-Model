#include "registermainform.h"
#include "ui_registermainform.h"
#include <QStandardItemModel>

RegisterMainForm::RegisterMainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterMainForm)
{
    ui->setupUi(this);
    registerTableInitiate();
}

RegisterMainForm::~RegisterMainForm()
{
    delete ui;
}

void RegisterMainForm::registerTableInitiate()
{
    QStringList headerList;
    QStandardItemModel* model = new QStandardItemModel();
    headerList.append("Регистр");
    headerList.append("Десятичное значение");
    headerList.append("Шестнадцатеричное значение");
    model->setHorizontalHeaderLabels(headerList);
    ui->registersTableView->setModel(model);
    ui->registersTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    int num;
    for(int i = 0; i < 32; i++)
    {
        num= rand()/(RAND_MAX/255);
        QStandardItem* item = new QStandardItem(QString("R" + QString::number(i)));
        model->setItem(i,0, item);
        model->setItem(i,1, new QStandardItem(QString::number(num)));
        model->setItem(i,2, new QStandardItem(QString::number(model->item(i,1)->text().toInt(),16).toUpper()));
    }
}

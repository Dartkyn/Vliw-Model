#include "registermainform.h"
#include "ui_registermainform.h"
#include <QStandardItemModel>
#include "windowmanager.h"
RegisterMainForm::RegisterMainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterMainForm)
{
    ui->setupUi(this);
}

RegisterMainForm::~RegisterMainForm()
{
    delete ui;
}

void RegisterMainForm::init()
{
    registerTableInitiate();
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
    QStringList str;
    str = WindowManager::getInstance()->processorInfo().registerInfo;
    for(int i = 0; i < str.length(); i++)
    {
        qDebug()<< str.at(i);
        QStringList row = str.at(i).split(" ");
        model->setItem(i,0, new QStandardItem(row.at(0)));
        model->setItem(i,1, new QStandardItem(QString::number(row.at(1).toLongLong())));
        model->setItem(i,2, new QStandardItem(QString::number(model->item(i,1)->text().toLongLong(),16).toUpper()));
    }
}

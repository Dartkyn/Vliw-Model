#include "workwindow.h"
#include "ui_workwindow.h"
#include <QGraphicsScene>
#include <QIcon>
#include <QHeaderView>
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>
#include "codeeditor.h"
#include "pipelineitem.h"
using namespace std;
WorkWindow::WorkWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WorkWindow)
{
    ui->setupUi(this);
    //DrawItems();
    ToolBarInitiate();
    //registerTableInitiate();
    //memoryTableInitiate();
    codeEditor = new CodeEditor();
    ui->codeGroupBox->layout()->addWidget(codeEditor);
    //loadCodeFile("C:\\MyFiles\\Projects\\QTProjects\\TestGUI\\logs\\inp.txt");
}

WorkWindow::~WorkWindow()
{
    delete ui;
}

void WorkWindow::DrawItems()
{
    QGraphicsScene * scene = new QGraphicsScene;
    ui->pipelinesGraphicsView->setScene(scene);
    PipelineItem* pipIt;
    int count;
    for(int i = 0; i < 200; i+=40)
    {
        pipIt = new PipelineItem(QRectF(0+i, i, 40, 40), QBrush(Qt::yellow), "IF");
        scene->addItem(pipIt);
        pipIt = new PipelineItem(QRectF(40+i, i, 40, 40), QBrush(Qt::blue), "ID");
        scene->addItem(pipIt);
        pipIt = new PipelineItem(QRectF(80+i, i, 40, 40), QBrush(Qt::red), "EX");
        scene->addItem(pipIt);
        pipIt = new PipelineItem(QRectF(120+i, i, 40, 40), QBrush(Qt::green), "MEM");
        scene->addItem(pipIt);
        pipIt = new PipelineItem(QRectF(160+i, i, 40, 40), QBrush(Qt::darkMagenta), "WB");
        scene->addItem(pipIt);
        count = i;
    }
    count+=40;
    pipIt = new PipelineItem(QRectF(0+count, count, 40, 40), QBrush(Qt::yellow), "IF");
    scene->addItem(pipIt);
    pipIt = new PipelineItem(QRectF(40+count, count, 40, 40), QBrush(Qt::blue), "ID");
    scene->addItem(pipIt);
    pipIt = new PipelineItem(QRectF(80+count, count, 40, 40), QBrush(Qt::red), "EX");
    scene->addItem(pipIt);
    pipIt = new PipelineItem(QRectF(120+count, count, 40, 40), QBrush(Qt::green), "MEM");
    scene->addItem(pipIt);
    count+=40;
    pipIt = new PipelineItem(QRectF(0+count, count, 40, 40), QBrush(Qt::yellow), "IF");
    scene->addItem(pipIt);
    pipIt = new PipelineItem(QRectF(40+count, count, 40, 40), QBrush(Qt::blue), "ID");
    scene->addItem(pipIt);
    pipIt = new PipelineItem(QRectF(80+count, count, 40, 40), QBrush(Qt::red), "EX");
    scene->addItem(pipIt);
    count+=40;
    pipIt = new PipelineItem(QRectF(0+count, count, 40, 40), QBrush(Qt::yellow), "IF");
    scene->addItem(pipIt);
    pipIt = new PipelineItem(QRectF(40+count, count, 40, 40), QBrush(Qt::blue), "ID");
    scene->addItem(pipIt);
    count+=40;
    pipIt = new PipelineItem(QRectF(0+count, count, 40, 40), QBrush(Qt::yellow), "IF");
    scene->addItem(pipIt);
}

void WorkWindow::ToolBarInitiate()
{
    QIcon newIcon, loadIcon, closeIcon, runIcon, runStepIcon, settingsIcon, saveIcon;
    newIcon.addFile("C:\\MyFiles\\Projects\\QTProjects\\TestGUI\\icons\\new_file.png");
    loadIcon.addFile("C:\\MyFiles\\Projects\\QTProjects\\TestGUI\\icons\\open_file.png");
    closeIcon.addFile("C:\\MyFiles\\Projects\\QTProjects\\TestGUI\\icons\\close_file.png");
    saveIcon.addFile("C:\\MyFiles\\Projects\\QTProjects\\TestGUI\\icons\\save_file.png");
    runIcon.addFile("C:\\MyFiles\\Projects\\QTProjects\\TestGUI\\icons\\run.png");
    runStepIcon.addFile("C:\\MyFiles\\Projects\\QTProjects\\TestGUI\\icons\\run_step.png");
    settingsIcon.addFile("C:\\MyFiles\\Projects\\QTProjects\\TestGUI\\icons\\settings.png");
    ui->toolBar->addAction(newIcon, "Новый файл...");
    ui->toolBar->addAction(loadIcon, "Открыть файл...");
    ui->toolBar->addAction(closeIcon, "Закрыть файл");
    ui->toolBar->addAction(saveIcon, "Сохранить файл");
    ui->toolBar->addAction(runIcon, "Запустить");
    ui->toolBar->addAction(runStepIcon, "Запусть в пошаговом режиме");
}

void WorkWindow::registerTableInitiate()
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

void WorkWindow::memoryTableInitiate()
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

void WorkWindow::loadCodeFile(QByteArray fileArray)
{
    QString str;
    str.append(fileArray);
    CodeEditor* cded = dynamic_cast<CodeEditor*>(codeEditor);
    cded->setPlainText(str);
}

void WorkWindow::on_showHideRegisters_toggled(bool arg1)
{
    if(arg1)
    {
        ui->registersGroupBox->show();
    }
    else
    {
        ui->registersGroupBox->hide();
    }
}


void WorkWindow::on_showHideMemory_toggled(bool arg1)
{
    if(arg1)
    {
        ui->memoryGroupBox->show();
    }
    else
    {
        ui->memoryGroupBox->hide();
    }
}


void WorkWindow::on_showHidePipelines_toggled(bool arg1)
{
    if(arg1)
    {
        ui->pipelineGroupBox->show();
    }
    else
    {
        ui->pipelineGroupBox->hide();
    }
}


void WorkWindow::on_openRegisterForm_triggered()
{
    regForm.show();
}


void WorkWindow::on_openMemoryForm_triggered()
{
    memForm.show();
}


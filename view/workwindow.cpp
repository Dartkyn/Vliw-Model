#include "workwindow.h"
#include "windowmanager.h"
const int drItemSize = 90;

WorkWindow::WorkWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WorkWindow)
{
    ui->setupUi(this);
    codeEditor = new CodeEditor();
    ui->codeGroupBox->layout()->addWidget(codeEditor);
    _scene = new QGraphicsScene();
    ui->pipelinesGraphicsView->setScene(_scene);
}

WorkWindow::~WorkWindow()
{
    delete ui;
}

void WorkWindow::drawItems()
{
    PipelineItem* pipIt;
    QString str_fetch = WindowManager::getInstance()->processorInfo().currentFetchComandInfo;
    str_fetch = prepareComandString(str_fetch);
    if(str_fetch!="")
    {
        pipIt = new PipelineItem(QRectF(_currentXCoord, _currentYCoord, drItemSize, drItemSize), QBrush(Qt::yellow), "IF\n\n" + str_fetch);
        _scene->addItem(pipIt);
    }
    QString str_decode = WindowManager::getInstance()->processorInfo().currentDecodeComandInfo;
    str_decode = prepareComandString(str_decode);
    if(str_decode!="")
    {
        pipIt = new PipelineItem(QRectF(_currentXCoord + drItemSize, _currentYCoord, drItemSize, drItemSize), QBrush(Qt::blue), "ID\n\n" + str_decode);
        _scene->addItem(pipIt);
    }
    QString str_execute = WindowManager::getInstance()->processorInfo().currentExecuteComandInfo;
    str_execute = prepareComandString(str_execute);
    if(str_execute!="")
    {
        pipIt = new PipelineItem(QRectF(_currentXCoord+drItemSize*2, _currentYCoord, drItemSize, drItemSize), QBrush(Qt::red), "EX",Qt::AlignTop);
        _scene->addItem(pipIt);
        int coords_x = pipIt->pipRect().x();
        int coords_y = pipIt->pipRect().y()+30;
        int minsize = (drItemSize-30)/3;
        QStringList str_executeList = str_execute.split("\n");
        pipIt = new PipelineItem(QRectF(coords_x,coords_y,drItemSize,minsize),
                                             QBrush(Qt::green),str_executeList.at(0));
        _scene->addItem(pipIt);
        pipIt = new PipelineItem(QRectF(coords_x,coords_y + minsize,drItemSize,minsize),
                                             QBrush(Qt::green),str_executeList.at(1));
        _scene->addItem(pipIt);
        pipIt = new PipelineItem(QRectF(coords_x,coords_y + minsize*2,drItemSize,minsize),
                                             QBrush(Qt::green),str_executeList.at(2));
        _scene->addItem(pipIt);
    }
    _currentYCoord+=drItemSize;
    _currentLine++;
    _currentXCoord = drItemSize * _currentLine;
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

void WorkWindow::memoryTableInitiate()
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

void WorkWindow::loadCodeFile(QByteArray fileArray)
{
    QString str;
    str.append(fileArray);
    CodeEditor* cded = dynamic_cast<CodeEditor*>(codeEditor);
    cded->setPlainText(str);
}

void WorkWindow::init()
{
    registerTableInitiate();
    memoryTableInitiate();
    QString msg="";
    if(WindowManager::getInstance()->isRunning())
    {
        msg = "Текущая команда: " + WindowManager::getInstance()->processorInfo().currentExecuteComandInfo;
    }
    else
    {
        msg = "Исполнение не запущено";
    }
    statusBar()->showMessage(msg);
    drawItems();
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
    WindowManager::getInstance()->openWindow(dynamic_cast<QMainWindow*>(WindowManager::getInstance()->registerWindow()));
}


void WorkWindow::on_openMemoryForm_triggered()
{
    WindowManager::getInstance()->openWindow(dynamic_cast<QMainWindow*>(WindowManager::getInstance()->memoryWindow()));
}

void WorkWindow::runFile()
{

    WindowManager::getInstance()->runFile();
}

void WorkWindow::runStepFile()
{
    WindowManager::getInstance()->runStepFile();
}

void WorkWindow::runStepBack()
{
    WindowManager::getInstance()->stepBack();
}

void WorkWindow::saveFile()
{
    QPlainTextEdit* textEdit = dynamic_cast<QPlainTextEdit*>(codeEditor);
    WindowManager::getInstance()->saveFile(textEdit->toPlainText().toUtf8());
}

QString WorkWindow::prepareComandString(QString comandString)
{
    if(comandString.contains("//"))
        comandString = comandString.section("",comandString.indexOf("//")+3, comandString.length());
    comandString.replace(";","\n");
    return comandString;
}


void WorkWindow::on_runMenuItem_triggered()
{
    saveFile();
    runFile();
}


void WorkWindow::on_runStepMenuItem_triggered()
{
    saveFile();
    runStepFile();
}


void WorkWindow::on_runFileToolBarItem_triggered()
{
    saveFile();
    runFile();
}


void WorkWindow::on_runStepToolBarItem_triggered()
{
    saveFile();
    runStepFile();
}


void WorkWindow::on_actionrunStepBackToolBarItem_triggered()
{
    runStepBack();
}


void WorkWindow::on_saveFileToolBarItem_triggered()
{
    saveFile();
}


#ifndef GUI_H
#define GUI_H
#include "QStringList"
#include "controller.h"
class Controller;
struct ProcessorInfo{
    QStringList registerInfo;
    QStringList dataInfo;
    QStringList comandInfo;
    QString currentFetchComandInfo;
    QString currentDecodeComandInfo;
    QString currentExecuteComandInfo;
};

class GUI{
protected:
    ProcessorInfo _processorInfo;
    Controller *_controller = nullptr;
public:
    virtual void updateInfo(ProcessorInfo coreInfo)=0;
    virtual void attachController(Controller* controller){_controller = controller;};
};


#endif // GUI_H

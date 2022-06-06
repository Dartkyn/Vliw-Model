#ifndef CORE_H
#define CORE_H
#include "view/gui.h"
class GUI;
class Core{
protected:
    QList<GUI*> _listeners;
public:
    virtual void update()=0;
    virtual void attach(GUI *gui){_listeners.append(gui);};
    virtual void doContiniousExecution() = 0;
    virtual void doStep() = 0;
    virtual void doStepBack()=0;
};

#endif // CORE_H

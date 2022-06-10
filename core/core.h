#ifndef CORE_H
#define CORE_H
#include "view/gui.h"
#include "memento.h"
class GUI;
class Data;
class Comand;
class Core{
protected:
    QList<GUI*> _listeners;
public:
    virtual void update()=0;
    virtual void attach(GUI *gui){_listeners.append(gui);};
    virtual void doContiniousExecution() = 0;
    virtual Memento* doStep() = 0;
    virtual void init(QList<Comand> lstComand, QList<Data> lstMemory) = 0;
};

#endif // CORE_H

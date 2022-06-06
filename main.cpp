#include <QApplication>
#include "controller.h"
#include "view/windowmanager.h"
#include "core/proccessor.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller *controller = new Controller();
    GUI *gui = dynamic_cast<GUI*>(WindowManager::getInstance());
    Core *processor = dynamic_cast<Core*>(new Proccessor());
    processor->attach(gui);
    controller->attachCore(processor);
    gui->attachController(controller);
    WindowManager::getInstance()->openCurrentWindow();
    return a.exec();
}

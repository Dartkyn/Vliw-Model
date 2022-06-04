#include <QApplication>
#include "QDebug"
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //WindowManager::getInstance()->OpenCurrentWindow();
    return a.exec();
}

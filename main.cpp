#include "view/windowmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WindowManager::getInstance()->OpenCurrentWindow();
    return a.exec();
}

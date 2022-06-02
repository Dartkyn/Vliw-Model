#include "view/windowmanager.h"

#include <QApplication>
#include "core/register.h"
#include "QDebug"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //WindowManager::getInstance()->OpenCurrentWindow();
    Register reg;
    reg.setByte(8);
    qDebug() << reg.toString();
    reg.setDoubleWord(8223372036854775807);
    qDebug() << reg.toString();
    return a.exec();
}

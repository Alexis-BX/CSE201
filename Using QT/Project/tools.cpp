#include "tools.h"
#include <QTime>
#include <QCoreApplication>

void delay(int i) //milliseconds
{
    QTime dieTime= QTime::currentTime().addMSecs(i);

    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

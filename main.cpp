#include <QCoreApplication>
#include "ConsoleFileObserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ConsoleFileObserver observer;
    return a.exec();
}

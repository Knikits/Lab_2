#include <QCoreApplication>
#include "ConsoleFileObserver.h"

/*
 Паттерн Наблюдатель включает в себя два компонента: Источник и Наблюдатель.
 Количество Наблюдателей одновременно взаимодействующих с Источником ничем не ограничено.
 Причем, к одному и тому же Источнику могут быть подключены объекты-Наблюдатели как одного класса,
 так и разных
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ConsoleFileObserver observer;
    return a.exec();
}

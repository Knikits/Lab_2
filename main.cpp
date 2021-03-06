#include <QCoreApplication>
#include "FileMonitor.h"
#include "File.h"
#include <thread>

/*
 Паттерн Наблюдатель включает в себя два компонента: Источник и Наблюдатель.
 Количество Наблюдателей одновременно взаимодействующих с Источником ничем не ограничено.
 Причем, к одному и тому же Источнику могут быть подключены объекты-Наблюдатели как одного класса,
 так и разных
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileMonitor check; // наблюдатель
    File file("D:/Lab_2/file.txt"); // объект, за которым следим
    file.Sub(&check); // оформляем подписку
    while(true)
    {
        file.checkFile();
        std::this_thread::sleep_for(std::chrono::seconds(1)); // секунда
    }
    return a.exec();
}

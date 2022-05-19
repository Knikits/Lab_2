#include <QCoreApplication>
#include "FileMonitor.h"
#include "File.h"
#include <thread>

/*
 Паттерн Наблюдатель включает в себя два компонента: Источник и Наблюдатель.
 Количество Наблюдателей одновременно взаимодействующих с Источником ничем не ограничено.
 Причем, к одному и тому же Источнику могут быть подключены Наблюдатели как одного класса,
 так и разных
*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    File file("D:/Lab_2/file.txt"); // объект, за которым следим
    FileMonitor check1; // наблюдатель
    file.Sub(&check1); // оформляем подписку
    while(true)
    {
        file.checkFile();
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); //миллисекунда
    }
    return a.exec();
}

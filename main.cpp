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

    //протестируем работу с разными условиями

    //когда на файл не подписан подписчик, соответственно, за файлом следить некому!
    /*
    QCoreApplication a(argc, argv);
    File file("D:/Lab_2/file.txt"); // объект, за которым следим
    FileMonitor check1; // наблюдатель
    //file.Sub(&check1); // оформляем подписку
    while(true)
    {
        file.checkFile();
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); //миллисекунда
    }
    return a.exec();
    */

    //когда на файл подписано несколько наблюдателей
    /*
    QCoreApplication a(argc, argv);
    File file("D:/Lab_2/file.txt"); // объект, за которым следим
    FileMonitor check1; // наблюдатель
    FileMonitor check2;
    file.Sub(&check1); // оформляем подписку
    file.Sub(&check2);
    while(true)
    {
        file.checkFile();
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); //миллисекунда
    }
    return a.exec();
    */
    //Как мы видим, каждый наблюдатель будет оповещён об изменениях. Повторюсь, что количество наблюдателей, одновременно взаимодействующих с объектом, ничем не ограничено.

    //подпишем и отпишем сразу же! Всё корректно
    /*
    QCoreApplication a(argc, argv);
    File file("D:/Lab_2/file.txt"); // объект, за которым следим
    FileMonitor check1; // наблюдатель
    file.Sub(&check1); // оформляем подписку
    file.unSub(&check1);
    while(true)
    {
        file.checkFile();
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); //миллисекунда
    }
    return a.exec();
    */

    /*
    //попробуем отписать неподписанного наблюдателя, соответственно, никто не будет следить за файлом.
    QCoreApplication a(argc, argv);
    File file("D:/Lab_2/file.txt"); // объект, за которым следим
    FileMonitor check1; // наблюдатель
    file.unSub(&check1);
    while(true)
    {
        file.checkFile();
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); //миллисекунда
    }
    return a.exec();
    */

    /*
    также можно менять число в скобках std::this_thread::sleep_for(std::chrono::milliseconds(1))
    это частота обновления
    */

}

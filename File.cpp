#include "File.h"
#include "sys\stat.h"
#include "iostream"
#include <QDebug>

File::File(std::string stream) // принимаем имя файла формата строки
{
    this->filename = QString::fromStdString(stream); // запоминает имя файла
    this->predInfo = new Info(); // запоминает исходное состояние
    struct stat statBuf; //специально использую #include "sys\stat.h" для запоминания инфы
    predInfo->exist = stat(filename.toStdString().c_str(), &statBuf) == 0; //далее узнаём характеристики файла
    if (predInfo->exist == 0)
    {
        predInfo->size = 0;
    }
    else predInfo->size = statBuf.st_size;
    Missingfile = 0;
}

void File::checkFile() // вызывается в main
{
    Info* info = new Info();
    struct stat statBuf;
    info->exist = stat(filename.toStdString().c_str(), &statBuf) == 0;
    if (info->exist == 0)
    {
        info->size = 0;
    }
    else info->size = statBuf.st_size;
    if (info -> exist == true)
    {
        if (*predInfo != *info) // если произошли изменения в файле
        {
            Notify(info); // то оповещаем
            predInfo = info; // новое состояние
            Missingfile = 0;
        }
    }
    else
    {
        if ((*predInfo != *info) && (Missingfile == 0)) // если произошли изменения в файле
        {
            Notify(info); // то оповещаем
            predInfo = info; // новое состояние
            Missingfile = 1;
        }
    }
}
